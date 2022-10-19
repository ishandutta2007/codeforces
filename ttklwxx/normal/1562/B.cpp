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
char s[100005];
int minn[10],maxn[10];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",s+1);
		for(int i=1;i<=9;i++)minn[i]=1000000000,maxn[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(minn[s[i]-'0']==1000000000)minn[s[i]-'0']=i;
			maxn[s[i]-'0']=i;
		}
		//for(int i=1;i<=9;i++)printf("%d %d\n",minn[i],maxn[i]);
		if(minn[1]!=1000000000)
		{
			printf("1\n1\n");
			continue;
		}
		if(minn[4]!=1000000000)
		{
			printf("1\n4\n");
			continue;
		}
		if(minn[6]!=1000000000)
		{
			printf("1\n6\n");
			continue;
		}
		if(minn[8]!=1000000000)
		{
			printf("1\n8\n");
			continue;
		}
		if(minn[9]!=1000000000)
		{
			printf("1\n9\n");
			continue;
		}
		if(maxn[2]>minn[2])
		{
			printf("2\n22\n");
			continue;
		}
		if(maxn[5]>minn[2])
		{
			printf("2\n25\n");
			continue;
		}
		if(maxn[7]>minn[2])
		{
			printf("2\n27\n");
			continue;
		}
		if(maxn[2]>minn[3])
		{
			printf("2\n32\n");
			continue;
		}
		if(maxn[3]>minn[3])
		{
			printf("2\n33\n");
			continue;
		}
		if(maxn[5]>minn[3])
		{
			printf("2\n35\n");
			continue;
		}
		if(maxn[2]>minn[5])
		{
			printf("2\n52\n");
			continue;
		}
		if(maxn[5]>minn[5])
		{
			printf("2\n55\n");
			continue;
		}
		if(maxn[7]>minn[5])
		{
			printf("2\n57\n");
			continue;
		}
		if(maxn[2]>minn[7])
		{
			printf("2\n72\n");
			continue;
		}
		if(maxn[5]>minn[7])
		{
			printf("2\n75\n");
			continue;
		}
		if(maxn[7]>minn[7])
		{
			printf("2\n77\n");
			continue;
		}
	}
	return 0;
}