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
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n;
int dep[N],fa[N][18];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,16) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,16,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void solve(){
	int x,y,a,b,k;
	scanf("%d%d%d%d%d",&a,&b,&x,&y,&k);
	int v1=dis(x,y);
	int v2=dis(x,a)+1+dis(b,y);
	int v3=dis(x,b)+1+dis(a,y);
	//cout<<v1<<' '<<v2<<' '<<v3<<endl;
	if ((v1+k)%2==0&&v1<=k) puts("YES");
	else if ((v2+k)%2==0&&v2<=k) puts("YES");
	else if ((v3+k)%2==0&&v3<=k) puts("YES");
	else puts("NO");
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	For(i,1,16) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	int Q;
	scanf("%d",&Q);
	while (Q--) solve();
}