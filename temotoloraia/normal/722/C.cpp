#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=100005;
const ll INF=1e11;
int n,a[N],b[N],fix[N],parent[N];
ll ans[N];
ll sum[N];
int pp (int x)
{
	if (parent[x]==x)return x;
	return parent[x]=pp(parent[x]);
}
void dsu (int u, int v)
{
	u=pp(u);
	v=pp(v);
	parent[v]=u;
	sum[u]+=sum[v];
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)cin>>b[i];
	for (int i=1;i<=n;i++){
		parent[i]=i;
		sum[i]=a[i];
	}
	for (int i=n;i>=1;i--){
		fix[b[i]]=1;
		if (fix[b[i]-1])dsu(b[i],b[i]-1);
		if (fix[b[i]+1])dsu(b[i],b[i]+1);
		ans[i]=max(ans[i+1],sum[b[i]]);
	}
	for (int i=2;i<=n+1;i++)cout<<ans[i]<<endl;
    return 0;
}