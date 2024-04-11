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
int n,A,B,da,db,dia,dis;
vector<int> e[N];
int f[N],dep[N];
void dfs(int x,int fa){
	f[x]=0;
	if (x==B) dis=dep[x];
	for (auto i:e[x])
		if (i!=fa){
			dep[i]=dep[x]+1;
			dfs(i,x);
			dia=max(dia,f[i]+f[x]+1);
			f[x]=max(f[x],f[i]+1);
		}
}
void solve(){
	scanf("%d%d%d%d%d",&n,&A,&B,&da,&db);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dia=dep[A]=0;
	dfs(A,0);
	db=min(db,dia);
	if (dis<=da||2*da>=db)
		puts("Alice");
	else puts("Bob");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}