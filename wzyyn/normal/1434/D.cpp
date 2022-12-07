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
const int N=500005;
int n,x[N],y[N],v[N];
vector<pii> e[N];
int dep[N],dfn[N],ed[N],pos[N];
int fl[N],p2[N*2];
pii st[N*2][20];
int lg[N*2];
void dfs(int x,int fa){
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	p2[x]=++*p2;
	st[*p2][0]=pii(dep[x],x);
	for (auto i:e[x])
		if (i.fi!=fa){
			fl[i.fi]=fl[x]^i.se;
			dep[i.fi]=dep[x]+1;
			dfs(i.fi,x);
			st[++*p2][0]=pii(dep[x],x);
		}
	ed[x]=*dfn;
}
struct node{
	int p1,p2,d;
	bool operator <(const node &a)const{
		return d<a.d;
	}
};
node get_node(int x,int y){
	if (x==-1&&y==-1) return (node){x,y,-(1<<30)};
	if (x==-1||y==-1) return (node){x,y,-(1<<29)};
	int px=p2[x],py=p2[y];
	if (px>py) swap(px,py);
	int k=lg[py-px+1];
	return (node){x,y,dep[x]+dep[y]-2*min(st[px][k],st[py-(1<<k)+1][k]).fi};
}
node merge(node a,node b){
	if (b.p1!=-1) a=max(a,max(get_node(a.p1,b.p1),get_node(a.p2,b.p1)));
	if (b.p2!=-1) a=max(a,max(get_node(a.p1,b.p2),get_node(a.p2,b.p2)));
	return a;
}
node t[N*4][2];
int nn,rev[N*4];
void pushup(int i){
	rev[i]=rev[i*2]^rev[i*2+1];
	t[i][0]=merge(t[i*2][0],t[i*2+1][rev[i*2]]);
	t[i][1]=merge(t[i*2][1],t[i*2+1][!rev[i*2]]);
}
void build(int n){
	nn=1;
	for (;nn<=n;nn<<=1);
	For(i,0,nn-1) t[i+nn][0]=t[i+nn][1]=(node){-1,-1,-(1<<30)};
	For(i,1,n) t[i+nn][fl[pos[i]]]=(node){pos[i],-1,-(1<<29)};
	Rep(i,nn-1,1) pushup(i);
}
void change(int l,int r){
	l+=nn; r+=nn;
	rev[l]^=1; swap(t[l][0],t[l][1]);
	rev[r]^=1; swap(t[r][1],t[r][1]);
	for (l>>=1,r>>=1;l!=r;l>>=1,r>>=1) pushup(l),pushup(r);
	for (;l;l>>=1) pushup(l);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		scanf("%d%d%d",&x[i],&y[i],&v[i]);
		e[x[i]].PB(pii(y[i],v[i]));
		e[y[i]].PB(pii(x[i],v[i]));
	}
	dfs(1,0);
	For(i,2,*p2) lg[i]=lg[i/2]+1;
	For(i,1,19)
		For(j,1,(*p2)-(1<<i)+1)
			st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	build(n);
	int m;
	scanf("%d",&m);
	For(i,1,m){
		int id;
		scanf("%d",&id);
		int p=(dep[x[id]]>dep[y[id]]?x[id]:y[id]);
		change(dfn[p],ed[p]);
		printf("%d\n",max(0,max(t[1][0].d,t[1][1].d)));
	}
}