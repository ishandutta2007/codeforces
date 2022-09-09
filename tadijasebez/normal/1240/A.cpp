#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ldb long double
const int mod=1e9+7;//998244353;
void ckmx(int &x, int y){ x=max(x,y);}
void ckmn(int &x, int y){ x=min(x,y);}
void ckmx(ll &x, ll y){ x=max(x,y);}
void ckmn(ll &x, ll y){ x=min(x,y);}
int mul(int x, int y){ return (ll)x*y%mod;}
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
const int N=200050;
int p[N];
ll sum[N];
int main()
{
    int q;
    scanf("%i",&q);
    while(q--)
	{
		int n;
		scanf("%i",&n);
		for(int i=1;i<=n;i++) scanf("%i",&p[i]);
		sort(p+1,p+1+n);
		reverse(p+1,p+1+n);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i];
		int x,y,a,b;
		scanf("%i %i",&x,&a);
		scanf("%i %i",&y,&b);
		if(x<y) swap(x,y),swap(a,b);
		ll k;
		scanf("%lld",&k);
		int z,A=0,B=0,AB=0;
		for(z=1;z<=n;z++)
		{
			if(z%a==0 && z%b==0) AB++;
			else if(z%a==0) A++;
			else if(z%b==0) B++;
			ll now=sum[AB]*(x+y)/100;
			now+=(sum[AB+A]-sum[AB])*x/100;
			now+=(sum[AB+A+B]-sum[AB+A])*y/100;
			if(now>=k) break;
		}
		if(z==n+1) printf("-1\n");
		else printf("%i\n",z);
	}
	return 0;
}