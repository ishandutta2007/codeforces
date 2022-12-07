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

const int N=200005;
int n,a[N],q[N],S[N],sz[N];
int fa[N],top[N],pos[N],dep[N];
vector<int> e[N],v[N];
int dfn[N],ed[N];

void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
			sz[x]+=sz[i];
		}
}
void dfs2(int x,int tp){
	
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	top[x]=tp;
	
	int k=0;
	for (auto i:e[x])
		if (i!=fa[x]&&sz[i]>sz[k])
			k=i;
	if (k)
		dfs2(k,tp);
	for (auto i:e[x])
		if (i!=fa[x]&&i!=k)
			dfs2(i,i);
	ed[x]=*dfn;
}
int jmp(int x,int y){
	for (;;){
		if (dep[top[x]]<=dep[y])
			return pos[dfn[x]-dep[x]+dep[y]+1];
		if (fa[top[x]]==y)
			return top[x];
		x=fa[top[x]];
	}
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
void UPD(int x,int y){
	For(i,0,1){
		if (isfa(x,y)){
			int p=jmp(y,x);
			//cout<<x<<' '<<y<<' '<<p<<endl;
			++S[1],--S[dfn[p]],++S[ed[p]+1];
		}
		else ++S[dfn[x]],--S[ed[x]+1];
		swap(x,y);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) q[i]=a[i];
	sort(q+1,q+n+1);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	dfs2(1,1);
	For(i,1,n){
		int p=lower_bound(q+1,q+n+1,a[i])-q;
		For(j,0,min(1,(int)v[p].size()-1)) UPD(i,v[p][j]);
		v[p].PB(i);
	}
	For(i,1,n) S[i]+=S[i-1];
	int ans=0;
	For(i,1,n) ans+=(!S[i]);
	printf("%d\n",ans);
}