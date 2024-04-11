#include<bits/stdc++.h>
using namespace std;
double f[1<<21];
long long a[1<<21];
char s[55][25];
int n,m;
int main()
{
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%s",s[i]);
	n=strlen(s[0]);
	for(int i=0;i<m;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			int t=0;
			for(int k=0;k<n;k++)
				if(s[i][k]==s[j][k])
					t|=(1<<k);
			a[t]|=(1LL<<i);
			a[t]|=(1LL<<j);
		}
	}
	for(int t=(1<<n)-1;t>=0;t--)
	{
		for(int i=0;i<n;i++)
			if(t&(1<<i))
				a[t^(1<<i)]|=a[t];
		int p=0;
		for(int i=0;i<n;i++)
		{
			if(!(t&(1<<i)))
			{
				f[t]+=f[t^(1<<i)];
				p++;
			}
		}
		if(p)
			f[t]/=p;
		f[t]+=__builtin_popcountll(a[t])*1.0/m;
	}
	printf("%.9lf\n",f[0]);
	return 0;
}