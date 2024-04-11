#include<bits/stdc++.h>
using namespace std;
const int N=300005;
char s[N];
int n,k,fl,a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%s",&n,&k,s+1);
		fl=1;
		for(int i=1;i<=k;i++)
			a[i]=-1;
		for(int i=1;i<=n&&fl;i+=k)
		{
			for(int j=i;j<i+k&&j<=n&&fl;j++)
			{
				if(s[j]=='?')
					continue;
				int x=s[j]-'0';
				if(a[j-i+1]!=-1)
				{
					if(a[j-i+1]!=x)
						fl=0;
				}
				else
					a[j-i+1]=x;
			}
		}
		int b[2]={};
		for(int i=1;i<=k;i++)
			if(a[i]!=-1)
				b[a[i]]++;
		for(int i=1;i<=k;i++)
		{
			if(a[i]==-1)
			{
				if(b[0]<b[1])
					b[0]++;
				else
					b[1]++;
			}
		}
		if(b[0]!=b[1])
			fl=0;
		puts(fl?"YES":"NO");
	}
	return 0;
}