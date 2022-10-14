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
const int N=200005;
int n,b[N],p[N],rt,w[N],pp[N];
vector<int> e[N];
void dfs(int x){
	for (int i:e[x]){
		w[i]=pp[i]-pp[x];
		dfs(i);
	}
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) e[i].clear();
	For(i,1,n){
		scanf("%d",b+i);
		if (b[i]==i) rt=i;
		else e[b[i]].PB(i);
	}
	For(i,1,n){
		scanf("%d",p+i);
		pp[p[i]]=i;
	}
	For(i,1,n)
		if (pp[i]<pp[b[i]]) {
			puts("-1");
			return;
		}
	w[rt]=0;
	dfs(rt);
	For(i,1,n) printf("%d ",w[i]); puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}