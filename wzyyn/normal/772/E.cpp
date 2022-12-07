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
const int N=2005;
int ls[N],rs[N],fa[N];
int vis[N],n,nd,rt;
int find_leaf(int x){
	return ls[x]?find_leaf(ls[x]):x;
}
int getsize(int x,int pa){
	int sz=1;
	if (ls[x]&&!vis[ls[x]]&&ls[x]!=pa) sz+=getsize(ls[x],x);
	if (rs[x]&&!vis[rs[x]]&&rs[x]!=pa) sz+=getsize(rs[x],x);
	if (fa[x]&&!vis[fa[x]]&&fa[x]!=pa) sz+=getsize(fa[x],x);
	return sz;
}
int dfs(int x,int pa,int n){
	int sz=1,v,mx=0;
	if (ls[x]&&!vis[ls[x]]&&ls[x]!=pa)
		sz+=(v=dfs(ls[x],x,n)),mx=max(mx,v);
	if (rs[x]&&!vis[rs[x]]&&rs[x]!=pa)
		sz+=(v=dfs(rs[x],x,n)),mx=max(mx,v);
	if (fa[x]&&!vis[fa[x]]&&fa[x]!=pa)
		sz+=(v=dfs(fa[x],x,n)),mx=max(mx,v);
	if (sz*2>n&&mx*2<=n) rt=x;
	return sz;
}
void dfs(int x,int id){
	int sz=getsize(x,-1);
	dfs(x,-1,sz); vis[x=rt]=1;
	if (x<=n){
		int p=fa[x]; ++nd;
		if (p) ls[p]==x?ls[p]=nd:rs[p]=nd;
		ls[nd]=x; rs[nd]=id; fa[nd]=p;
		fa[x]=fa[id]=nd;
		return;
	}
	//cout<<x<<' '<<sz<<' '<<nd<<endl;
	int p1=find_leaf(ls[x]);
	int p2=find_leaf(rs[x]);
	printf("%d %d %d\n",p1,p2,id);
	fflush(stdout);
	char s[5];
	scanf("%s",s+1);
	if (s[1]=='X'){
		if (vis[fa[x]]||!fa[x]){
			int p3=fa[x]; ++nd;
			if (p3) ls[p3]==x?ls[p3]=nd:rs[p3]=nd;
			ls[nd]=x; rs[nd]=id; fa[nd]=p3;
			fa[x]=fa[id]=nd;
		}
		else
			dfs(fa[x],id);
		return;
	} 
	if (s[1]=='Z'){
		if (vis[ls[x]]){
			int p3=ls[x]; ++nd;
			ls[x]=nd; ls[nd]=p3; rs[nd]=id;
			fa[nd]=x; fa[p3]=fa[id]=nd;
		}
		else
			dfs(ls[x],id);
		return;
	}
	if (s[1]=='Y'){
		if (vis[rs[x]]){
			int p3=rs[x]; ++nd;
			rs[x]=nd; ls[nd]=p3; rs[nd]=id;
			fa[nd]=x; fa[p3]=fa[id]=nd;
		}
		else
			dfs(rs[x],id);
		return;
	}
	assert(0);
}
int main(){
	scanf("%d",&n);
	fa[1]=fa[2]=nd=n+1;
	ls[nd]=1; rs[nd]=2;
	For(i,3,n){
		memset(vis,0,sizeof(vis));
		dfs(nd,i);
		//For(j,1,nd) printf("%d %d %d\n",ls[j],rs[j],fa[j]);
	}
	puts("-1");
	For(i,1,nd) printf("%d ",fa[i]?fa[i]:-1);
}