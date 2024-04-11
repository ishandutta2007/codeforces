#include<iostream>
#include<cstdio>
#include<cmath>
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
char s1[2000000],s2[2000000];
int sl1[27],sl2[27];
int main()
{
	int t,n,k,tans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		for(int i=1;i<=26;i++)sl1[i]=sl2[i]=0; 
		for(int i=1;i<=n;i++)
		{
			sl1[s1[i]-'a'+1]++;
		}
		for(int i=1;i<=n;i++)
		{
			sl2[s2[i]-'a'+1]++; 
		}
		tans=0;
		flag=false;
		for(int i=26;i>=1;i--)
		{
			tans=tans+sl2[i]-sl1[i];
			if(tans<0||tans%k!=0)
			{
				flag=true;
				printf("No\n");
				break;
			}
		}
		if(flag==false)printf("Yes\n");
	}
	return 0;
}