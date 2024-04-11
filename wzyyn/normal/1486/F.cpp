#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=300005;
int n;
int dep[N],fa[N][20];
vector<int> e[N];
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int dif=dep[x]-dep[y];
	Rep(i,18,0)
		if (dif&(1<<i))
			x=fa[x][i];
	Rep(i,18,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int jmp(int x,int y){
	if (x==y) return -1;
	int dif=dep[x]-dep[y]-1;
	Rep(i,18,0)	
		if (dif&(1<<i))
			x=fa[x][i];
	return x; 
}
int S1[N],S2[N];
vector<pii> op[N];
map<pii,int> mp;
ll ans;
void solve(int x){
	for (auto i:e[x])
		if (i!=fa[x][0]){
			solve(i);
			S1[x]+=S1[i];
			S2[x]+=S2[i];
		}
	int sum=S2[x];
	mp.clear();
	for (auto i:op[x]){
		int px=jmp(i.fi,x);
		int py=jmp(i.se,x);
		ans+=(--sum);
		if (px!=-1) ans-=(--S1[px]);
		if (py!=-1) ans-=(--S1[py]);
		if (px!=-1&&py!=-1){
			ans+=mp[pii(px,py)];
			++mp[pii(px,py)];
			++mp[pii(py,px)];
		}
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		e[y].PB(x);
	}
	dfs(1);
	For(i,1,18) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=LCA(x,y);
		++S1[x]; ++S1[y]; S1[L]-=2;
		++S2[x]; ++S2[y]; --S2[L]; --S2[fa[L][0]];
		//cout<<x<<' '<<y<<' '<<L<<endl;
		op[L].PB(pii(x,y));
	}
	solve(1);
	cout<<ans<<endl;
}