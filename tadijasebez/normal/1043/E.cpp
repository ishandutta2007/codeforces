#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
vector<int> id;
int Find(int x){ return lower_bound(id.begin(),id.end(),x)-id.begin()+1;}
const int N=300050;
vector<int> E[N];
struct BIT
{
	ll sum[N];
	void init(){ for(int i=0;i<N;i++) sum[i]=0;}
	BIT(){ init();}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	ll Get(int i){ ll ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
	ll Get(int l, int r){ return Get(r)-Get(l-1);}
} X,Y,CX,CY;
int x[N],y[N],pos[N];
void Add(int i)
{
	X.Set(pos[i],x[i]);CX.Set(pos[i],1);
	Y.Set(pos[i],y[i]);CY.Set(pos[i],1);
}
void Rem(int i)
{
	X.Set(pos[i],-x[i]);CX.Set(pos[i],-1);
	Y.Set(pos[i],-y[i]);CY.Set(pos[i],-1);
}
int main()
{
	int n,m,u,v,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i %i",&x[i],&y[i]),id.pb(x[i]-y[i]),E[i].pb(i);
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	while(m--) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(i=1;i<=n;i++) pos[i]=Find(x[i]-y[i]),Add(i);
	ll ans;
	for(i=1;i<=n;i++)
	{
		for(j:E[i]) Rem(j);
		ans=X.Get(1,pos[i])+Y.Get(pos[i]+1,id.size());
		ans+=(ll)x[i]*CY.Get(pos[i]+1,id.size())+(ll)y[i]*CX.Get(1,pos[i]);
		for(j:E[i]) Add(j);
		printf("%lld ",ans);
	}
	return 0;
}