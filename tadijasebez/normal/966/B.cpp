#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
bool ckmax(int &a, int b){ a=max(a,b);return a==b;}
bool ckmin(int &a, int b){ a=min(a,b);return a==b;}
bool ckmax(ll &a, ll b){ a=max(a,b);return a==b;}
bool ckmin(ll &a, ll b){ a=min(a,b);return a==b;}
const int mod=1e9+7;
int pow(int x, int k){ int ret=1;for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;return ret;}
int inv(int x){ return pow(x,mod-2);}
void add(int &a, int b){ a+=b;if(a>=mod) a-=mod;}
void sub(int &a, int b){ a-=b;if(a<0) a+=mod;}
void mul(int &a, int b){ a=(ll)a*b%mod;}
void div(int &a, int b){ mul(a,inv(b));}
const int N=300050;
int a[N],id[N];
bool comp(int i, int j){ return a[i]>a[j];}
int main()
{
	int n,x1,x2,i;
	scanf("%i %i %i",&n,&x1,&x2);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	int sol1=0,sol2=0;

		for(i=1;i<=n;i++)
		{
			if((ll)a[id[i]]*i>=x2){ sol1=i;break;}
		}
		for(i=sol1+1;i<=n;i++)
		{
			if((ll)a[id[i]]*(i-sol1)>=x1){ sol2=i;break;}
		}
		if(sol1 && sol2)
		{
			printf("Yes\n%i %i\n",sol2-sol1,sol1);
			for(i=sol1+1;i<=sol2;i++) printf("%i ",id[i]);printf("\n");
			for(i=1;i<=sol1;i++) printf("%i ",id[i]);printf("\n");
			return 0;
		}
		sol1=0;sol2=0;
		for(i=1;i<=n;i++)
		{
			if((ll)a[id[i]]*i>=x1){ sol1=i;break;}
		}
		for(i=sol1+1;i<=n;i++)
		{
			if((ll)a[id[i]]*(i-sol1)>=x2){ sol2=i;break;}
		}
		if(!sol1 || !sol2) return printf("No\n"),0;
		printf("Yes\n%i %i\n",sol1,sol2-sol1);
		for(i=1;i<=sol1;i++) printf("%i ",id[i]);printf("\n");
		for(i=sol1+1;i<=sol2;i++) printf("%i ",id[i]);printf("\n");

	return 0;
}