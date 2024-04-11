#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
int n,ans,sz[N];
ll S,SS,q[N*20];
vector<pii> e[N];
void dfs(int x,int fa){
	sz[x]=(e[x].size()==1&&x!=1);
	for (auto i:e[x])
		if (i.fi!=fa){
			dfs(i.fi,x);
			SS+=1ll*i.se*sz[i.fi];
			sz[x]+=sz[i.fi];
			for (int rem=i.se;rem;rem/=2)
				q[++*q]=sz[i.fi]*1ll*(rem-rem/2);
		}
}
void solve(){
	*q=ans=SS=0;
	scanf("%d%lld",&n,&S);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].PB(pii(y,v));
		e[y].PB(pii(x,v));
	}
	dfs(1,0);
	sort(q+1,q+*q+1);
	for (;SS>S;SS-=q[*q],--*q,++ans);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}