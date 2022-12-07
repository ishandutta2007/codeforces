#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=500005,K=55;
int n,m,k,Q,top,c[N];
vector<int> t[N*4],vec[N];
int x[N],y[N],E[N],C[N];
int fa[K][N],sz[K][N];
bool v[K][N];
struct node{
	int k,x,y;
}q[N];
int get(int c,int x){
	return x==fa[c][x]?x:get(c,fa[c][x]);
}
int getv(int c,int x){
	return x==fa[c][x]?0:v[c][x]^getv(c,fa[c][x]);
}
bool merge(int x,int y,int c){
	//printf("MERGE %d %d %d\n",x,y,c);
	int xx=get(c,x),vx=getv(c,x);
	int yy=get(c,y),vy=getv(c,y);
	if (xx!=yy){
		if (sz[c][xx]>sz[c][yy]) swap(xx,yy);
		q[++top]=(node){c,xx,yy};
		fa[c][xx]=yy;
		v[c][xx]=vx^vy^1;
		sz[c][yy]+=sz[c][xx];
	}
	else
		if (vx^vy^1)
			return 0;
	return 1;
}
void pop(){
	//printf("POP\n");
	int c=q[top].k,x=q[top].x,y=q[top].y;
	fa[c][x]=x; v[c][x]=0;
	sz[c][y]-=sz[c][x]; top--;
}
void insert(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k].PB(v);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) insert(k*2,l,mid,x,y,v);
	else if (x>mid) insert(k*2+1,mid+1,r,x,y,v);
	else{
		insert(k*2,l,mid,x,mid,v);
		insert(k*2+1,mid+1,r,mid+1,y,v);
	}
}
void solve(int k,int l,int r){
	int tmp=top; 
	For(i,0,t[k].size()-1){
		int id=t[k][i];
		if (c[id]) merge(x[id],y[id],c[id]);
	}
	if (l==r){
		if (l==Q+1) return;
		if (merge(x[E[l]],y[E[l]],C[l]))
			c[E[l]]=C[l],puts("YES");
		else puts("NO");
	}
	else{
		int mid=(l+r)/2;
		solve(k*2,l,mid);
		solve(k*2+1,mid+1,r);
	}
	for (;top>tmp;pop());
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&Q);
	For(i,1,k) For(j,1,n) fa[i][j]=j,sz[i][j]=1;
	For(i,1,m) scanf("%d%d",&x[i],&y[i]);
	For(i,1,Q) scanf("%d%d",&E[i],&C[i]);
	For(i,1,Q) vec[E[i]].PB(i);
	For(i,1,m) vec[i].PB(Q+1);
	For(i,1,m)
		For(j,0,vec[i].size()-2)
			insert(1,1,Q+1,vec[i][j]+1,vec[i][j+1],i);
	solve(1,1,Q+1);
}
/*
50*500000*(
*/