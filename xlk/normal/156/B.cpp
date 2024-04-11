#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",&x);
#define print(x) printf("%d ",&x);

const int inf=0x3fffffff;
using namespace std;
int n,m;
int x,sm;
int cnt,z;
int f[200020];
int s[200020];
int c[200020];
int b[200020];
int a[200020];
int p[200020];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void U(int x,int y)
{
	f[F(x)]=F(y);
	return;
}
int main()
{
	scan(n)
	scan(m);
	fo(i,n)
	{
		char s[30];
		scanf("%s",s);
		if(s[0]=='-')
		{
			sscanf(s+1,"%d",&x);
			p[i]=1;
			a[i]=x;
			b[x]++;
			sm++;
		}
		if(s[0]=='+')
		{
			sscanf(s+1,"%d",&x);
			p[i]=-1;
			a[i]=x;
			c[x]++;
		}
	}
	fo(i,n)
	{
		if(sm-b[i]+c[i]==m)
			cnt++,z=i;
	}
	if(cnt>1)
	{
		fo(i,n)
		{
			if(sm-b[i]+c[i]==m)
				s[i]=1;
		}
		fo(i,n)
		{
			if(s[a[i]]==0)
			{
				if(p[i]==1)
					puts("Truth");
				else
					puts("Lie");
			}
			else
			{
				puts("Not defined");
			}
		}
	}
	else
	{
		fo(i,n)
		{
			s[z]=3;
			if(a[i]!=z)
			{
				if(p[i]==1)
					puts("Truth");
				else
					puts("Lie");
			}
			else
			{
				if(p[i]==1)
					puts("Lie");
				else
					puts("Truth");
			}
		}
	}
	return 0;
}