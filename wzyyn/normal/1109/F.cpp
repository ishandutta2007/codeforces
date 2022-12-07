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
const int N=1005;
const int M=200005;
const int INF=1<<30;
int n,m,a[N][N];
pii p[M];
ll ans;
namespace TR{
	pii t[M*4];
	int tg[M*4];
	void build(int k,int l,int r){
		t[k]=pii(-INF,r-l+1);
		if (l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
	}
	void add(int k,int v){
		t[k].fi+=v;
		tg[k]+=v;
	}
	void pushdown(int k){
		if (!tg[k]) return;
		add(k*2,tg[k]);
		add(k*2+1,tg[k]);
		tg[k]=0;
	}
	void pushup(int k){
		t[k]=pii(max(t[k*2].fi,t[k*2+1].fi),0);
		if (t[k].fi==t[k*2].fi) t[k].se+=t[k*2].se;
		if (t[k].fi==t[k*2+1].fi) t[k].se+=t[k*2+1].se;
	}
	void change(int k,int l,int r,int x,int y,int v){
		if (x<=l&&r<=y) return add(k,v);
		pushdown(k);
		int mid=(l+r)/2;
		if (x<=mid) change(k*2,l,mid,x,y,v);
		if (y>mid) change(k*2+1,mid+1,r,x,y,v);
		pushup(k);
	}
}
namespace LCT{
	int fa[M],rev[M];
	int ch[M][2];
	bool isroot(int k){
		return ch[fa[k]][0]!=k&&ch[fa[k]][1]!=k;
	}
	void rever(int k){
		swap(ch[k][0],ch[k][1]);
		rev[k]^=1;
	}
	void pushdown(int k){
		if (!rev[k]) return;
		if (ch[k][0]) rever(ch[k][0]);
		if (ch[k][1]) rever(ch[k][1]);
		rev[k]=0;
	}
	void Down(int k){
		if (!isroot(k)) Down(fa[k]); 
		pushdown(k);
	}
	void rotate(int x){
		int y=fa[x],z=fa[y];
		int l=(ch[y][1]==x),r=l^1;
		if (!isroot(y)) ch[z][ch[z][1]==y]=x;
		fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
		ch[y][l]=ch[x][r]; ch[x][r]=y;
	}
	void splay(int x){
		Down(x);
		for (;!isroot(x);rotate(x)){
			int y=fa[x],z=fa[y];
			if (!isroot(y)) rotate((ch[z][0]==y)^(ch[y][0]==x)?x:y);
		}
	}
	void access(int x){
		for (int t=0;x;t=x,x=fa[x])
			splay(x),ch[x][1]=t;
	}
	void makeroot(int x){
		access(x); splay(x); rever(x);
	}
	void link(int x,int y){
		makeroot(x); fa[x]=y;
	}
	void cut(int x,int y){
		makeroot(x);
		access(y);
		splay(y);
		ch[y][0]=fa[x]=0;
	}
	int find_rt(int x){
		access(x);
		splay(x);
		for (;ch[x][0];x=ch[x][0]);
		splay(x);
		return x;
	}
}
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
bool jud(int l,int r){
	static int q[10];
	int px=p[l].fi,py=p[l].se;
	*q=0;
	For(d,0,3){
		int nx=px+dx[d],ny=py+dy[d];
		if (l<a[nx][ny]&&a[nx][ny]<=r)
			q[++*q]=LCT::find_rt(a[nx][ny]);
	}
	For(i,1,*q) For(j,i+1,*q)
		if (q[i]==q[j]) return 0;
	return 1;
}
void erase(int l,int r){
	TR::change(1,1,n*m,r,r,-INF);
	int px=p[r].fi,py=p[r].se;
	For(d,0,3){
		int nx=px+dx[d],ny=py+dy[d];
		if (l<a[nx][ny]&&a[nx][ny]<=r){
			TR::change(1,1,n*m,a[px][py],n*m,1);
			LCT::cut(a[px][py],a[nx][ny]);
		}
	}
}
void insert(int l,int r){
	TR::change(1,1,n*m,l,l,INF);
	int px=p[l].fi,py=p[l].se;
	For(d,0,3){
		int nx=px+dx[d],ny=py+dy[d];
		if (l<=a[nx][ny]&&a[nx][ny]<=r){
			TR::change(1,1,n*m,a[nx][ny],n*m,1);
			LCT::link(a[px][py],a[nx][ny]);
		}
	}
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m){
		scanf("%d",&a[i][j]);
		p[a[i][j]]=pii(i,j);
	}
	TR::build(1,1,n*m);
	int p=n*m;
	Rep(i,n*m,1){
		for (;!jud(i,p);erase(i,p--));
		insert(i,p);
		TR::change(1,1,n*m,i,n*m,-1);
		//out<<i<<' '<<p<<' '<<TR::t[1].fi<<' '<<TR::t[1].se<<endl;
		if (TR::t[1].fi==-1) ans+=TR::t[1].se;
	}
	printf("%lld\n",ans);
}
/*
3^n 

1^n 3^n+1 
*/