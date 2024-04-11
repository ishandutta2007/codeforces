#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=100050;
int Gauss[20],sz,bad;
void Add(int x)
{
	for(int i=19;~i;i--)
	{
		if((x>>i)&1)
		{
			if(!Gauss[i])
			{
				Gauss[i]=x;
				sz++;
				return;
			}
			else x^=Gauss[i];
		}
	}
	bad++;
}
int min(int a, int b){ return a>b?b:a;}
bool Can(int x)
{
	for(int i=19;~i;i--) x=min(x,x^Gauss[i]);
	return x==0;
}
const int mod=1e9+7;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int a[N],l[N],x[N],sol[N];
vector<int> Qs[N];
int main()
{
	int n,q,i,j;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=q;i++)
	{
		scanf("%i %i",&l[i],&x[i]);
		Qs[l[i]].pb(i);
	}
	for(i=1;i<=n;i++)
	{
		Add(a[i]);
		for(j=0;j<Qs[i].size();j++)
		{
			int id=Qs[i][j];
			if(Can(x[id]))
			{
				sol[id]=pow(2,bad);
			}
		}
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}