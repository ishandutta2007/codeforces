#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[200005];
int sl[27];
int main()
{
	int t,n,minn,mpos,zs;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=26;i++)sl[i]=0;
		for(int i=1;i<=n;i++)
		{
			sl[s[i]-'a'+1]++;
		}
		minn=1000000000;
		mpos=0;
		for(int i=1;i<=26;i++)
		{
			if(sl[i]>0)
			{
				minn=sl[i];
				mpos=i;
				break;
			}
		}
		if(minn==n)
		{
			printf("%s\n",s+1);
			continue;
		}
		for(int j=1;j<=26;j++)
		{
			if(sl[j]==1)
			{
				minn=1;
				mpos=j;
				break;
			}
		}
		if(minn==1)
		{
			printf("%c",'a'+mpos-1);
			sl[mpos]--;
			for(int i=2;i<=n;i++)
			{
				for(int j=1;j<=26;j++)
				{
					if(sl[j]>0)
					{
						printf("%c",'a'+j-1);
						sl[j]--;
						break; 
					}
				}
			}
			printf("\n");
		}
		else if(minn<=n/2+1)
		{
			printf("%c%c",'a'+mpos-1,'a'+mpos-1);
			sl[mpos]-=2;
			for(int i=3;i<=n;i++)
			{
				if(i%2==0&&sl[mpos]>0)
				{
					printf("%c",'a'+mpos-1);
					sl[mpos]--;
					continue;
				}
				else
				{
					for(int j=1;j<=26;j++)
					{
						if(sl[j]>0&&j!=mpos)
						{
							printf("%c",'a'+j-1);
							sl[j]--;
							break;
						}
					}
				}
			}
			printf("\n");
		}
		else
		{
			zs=0;
			for(int j=1;j<=26;j++)if(sl[j]>0)zs++;
			printf("%c",'a'+mpos-1);
			sl[mpos]--;
			if(zs==2)
			{
				int sth=0;
				for(int j=1;j<=26;j++)if(sl[j]>0&&j!=mpos)
				{
					sth=j;
					break;
				}
				for(int j=1;j<=sl[sth];j++)printf("%c",'a'+sth-1);
				for(int j=1;j<=sl[mpos];j++)printf("%c",'a'+mpos-1);
				printf("\n");
				continue;
			}
			int sth=0;
			for(int j=1;j<=26;j++)if(sl[j]>0&&j!=mpos)
			{
				sth=j;
				break;
			}
			printf("%c",'a'+sth-1);
			sl[sth]--;
			for(int j=1;j<=sl[mpos];j++)printf("%c",mpos+'a'-1);
			sl[mpos]=0;
			for(int j=1;j<=26;j++)
			{
				if(sl[j]>0&&j!=mpos&&j!=sth)
				{
					printf("%c",'a'+j-1);
					sl[j]--;
					break;
				}
			}
			while(1)
			{
				flag=false; 
				for(int j=1;j<=26;j++)
				{
					if(sl[j]>0)
					{
						printf("%c",'a'+j-1);
						sl[j]--;
						flag=true;
						break;
					}
				}
				if(flag==false)break;
			}
			printf("\n");
		}
	} 
	return 0;
}