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
const int N=300050;
int a[N],klasa[N],n,len[N];
map<int,int> last[N];
void Solve()
{
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&a[i]);
	klasa[n+1]=n+1;len[n+1]=0;
	ll ans=0;
	for(int i=n;i>=1;i--)
	{
        int my=-1;
        if(last[a[i]].count(klasa[i+1])) my=last[a[i]][klasa[i+1]];
        if(my==-1) klasa[i]=i;
        else klasa[i]=klasa[my+1];
        last[a[i]][klasa[i]]=i;
        if(my!=-1) len[i]=len[my+1]+1;
		else len[i]=0;
		ans+=len[i];
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) last[i].clear();
}
int main()
{
    int q;
    scanf("%i",&q);
    while(q--)
	{
		Solve();
	}
	return 0;
}