#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=500005;
int n,a,b,v[N],ans[N];
int vis[N],q[N];
vector<int> vs[N],vp[N];
void solve(){
	scanf("%d%d%d",&n,&a,&b);
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,n) ans[i]=-1;
	For(i,1,n+1){
		vis[i]=0;
		vp[i].resize(0);
		vs[i].resize(0);
	}
	For(i,1,n){
		vis[v[i]]=1;
		vp[v[i]].PB(i);
	}
	For(i,1,n+1)
		if (vp[i].size())
			vs[vp[i].size()].PB(i);
	int p=n;
	For(i,1,a){
		for (;!vs[p].size();p--);
		int x=vs[p].back();
		ans[vp[x].back()]=x;
		vp[x].pop_back();
		vs[p].pop_back();
		vs[p-1].PB(x);
	}
	*q=0;
	For(i,1,n+1)
		for (auto j:vp[i])
			q[++*q]=j;
	p=1;
	for (;vis[p];++p);
	b=n-b;
	For(i,1,(*q)){
		int np=(i+(*q)/2-1)%(*q)+1;
		ans[q[i]]=v[q[np]];
		if (ans[q[i]]==v[q[i]]){
			--b; ans[q[i]]=p;
			if (b<0) return puts("NO"),void(0);
		}
	}
	For(i,1,n)
		if (b&&ans[i]!=v[i]&&ans[i]!=p)
			ans[i]=p,b--;
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}