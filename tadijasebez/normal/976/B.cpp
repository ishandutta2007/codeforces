#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool ckmax(int &a, int b){ int c=a;a=max(a,b);return c!=a;}
bool ckmin(int &a, int b){ int c=a;a=min(a,b);return c!=a;}
bool ckmax(ll &a, ll b){ ll c=a;a=max(a,b);return c!=a;}
bool ckmin(ll &a, ll b){ ll c=a;a=min(a,b);return c!=a;}
pair<ll,ll> Get(int n, int m, ll k)
{
	ll x,y;
	if(k<n) return mp(k+1,1);
	k-=n;ll sz=m-1;
	x=n-k/sz;
	k%=sz*2;
	if(k>=sz) y=2*sz-k+1;
	else y=k+2;
	return mp(x,y);
	//printf("%i %i\n",x,y);
}
int main()
{
	int n,m,i;ll k;
	scanf("%i %i %lld",&n,&m,&k);
	ll x,y;
	//if(k<n) return printf("%i 1\n",k+1),0;
	//for(i=0;i<n*m;i++)
	//{
	//	pair<int,int> tmp=Get(n,m,i);
	//	printf("%i %i\n",tmp.first,tmp.second);
	//}
	pair<ll,ll> sol=Get(n,m,k);
	printf("%lld %lld\n",sol.first,sol.second);
	/*if(k<n) return printf("%i 1\n",k+1),0;
	k-=n;
	int x=n-k/(2*(m-1))*2,y;
	k%=2*(m-1);
	if(k>=(m-1)) x--;
	if(k<(m-1)) y=k+2;
	else y=2*(m-1)-k+1;
	printf("%i %i\n",x,y);*/
	return 0;
}