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
vector<int> e[N];
int sz[N],n,rt,frt;
int p1,p2;
void dfs(int x,int fa){
	int mx=0;
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa){
			dfs(i,x);
			sz[x]+=sz[i];
			mx=max(mx,sz[i]);
		}
	if (sz[x]*2>=n&&mx*2<n)
		rt=x,frt=fa;
}
void dfs2(int x,int fa){
	if (e[x].size()==1){
		p1=x,p2=fa;
	} 
	for (auto i:e[x])
		if (i!=fa) dfs2(i,x);
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		e[y].PB(x);
	}
	dfs(1,0);
	if (rt==1){
		printf("%d %d\n",1,e[1][0]);
		printf("%d %d\n",1,e[1][0]);
	}
	else{
		dfs2(frt,rt);
		printf("%d %d\n",p1,p2);
		printf("%d %d\n",p1,rt);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}