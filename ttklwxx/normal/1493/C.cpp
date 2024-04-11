#include<iostream>
#include<cstdio>
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
int sl[200005],hx[200005];
int main()
{
	int t,n,k,hs;
	bool flag;
	int sfl;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		scanf("%s",s+1);
		if(n%k!=0)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=26;i++)sl[i]=0;
		for(int i=1;i<=n;i++)sl[s[i]-'a'+1]++;
		flag=false;
		for(int i=1;i<=26;i++)
		{
			if(sl[i]%k!=0)
			{
				flag=true;
				break;
			}
		}
		if(flag==false)
		{
			printf("%s\n",s+1);
			continue;
		}
		flag=false;
		for(int i=n;i>=1;i--)
		{
			sl[s[i]-'a'+1]--;
			if(s[i]=='z')continue;
			hs=n+1-i;
			for(int j=1;j<=26;j++)
			{
				hx[j]=(k-sl[j]%k)%k;
				hs-=hx[j];
			}
			if(hs<0)continue;
			hs/=k;
			if(hs==0)
			{
				sfl=0;
				for(int j=s[i]-'a'+2;j<=26;j++)
				{
					if(hx[j]>0)
					{
						hx[j]--;
						sfl=j;
						break;
					}
				}
				if(sfl==0)continue;
				for(int j=1;j<=i-1;j++)printf("%c",s[j]);
				printf("%c",sfl+'a'-1);
				for(int j=1;j<=26;j++)
				{
					for(int k=1;k<=hx[j];k++)printf("%c",'a'+j-1);
				}
				printf("\n");
				flag=true;
				break;
			}
			if(hx[s[i]-'a'+2]==0)
			{
				hs--;
				hx[s[i]-'a'+2]+=k;
			}
			sfl=s[i]-'a'+2;
			hx[s[i]-'a'+2]--; 
			hx[1]+=hs*k;
			for(int j=1;j<=i-1;j++)printf("%c",s[j]);
			printf("%c",sfl+'a'-1);
			for(int j=1;j<=26;j++)
			{
				for(int k=1;k<=hx[j];k++)printf("%c",'a'+j-1);
			}
			printf("\n");
			flag=true;
			break;
		}
		if(flag==false)printf("-1\n");
	}
	return 0;
}