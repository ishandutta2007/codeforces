#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=200005;
int n,Q;
struct Info{
	int id,tp,x,y;
	bool operator <(const Info &a)const{
		if (x!=a.x) return x<a.x;
		if (y!=a.y) return y<a.y;
		return id<a.id;
	}
}q[N*2];
vector<int> vec[N*4];
int Qx[N],Qy[N],Jud[N][2];
int Ex[N*2],Ey[N*2],ans[N];
int fa[N],sz[N],qx[N],qy[N],top;
int vis[N*2],m;
int get(int x){
	return x==fa[x]?x:get(fa[x]);
}
void merge(int x,int y){
	x=get(x); y=get(y);
	if (x==y) return;
	if (sz[x]<sz[y]) swap(x,y);
	qx[++top]=x; qy[top]=y;
	fa[y]=x; sz[x]+=sz[y];
}
void pop_back(){
	int x=qx[top],y=qy[top]; top--;
	sz[x]-=sz[y]; fa[y]=y;
}
void insert(int k,int l,int r,int x,int y,int v){
	if (l>r) while(1);
	if (l==x&&r==y){
		vec[k].PB(v);
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
	int posi=top;
	For(i,0,vec[k].size()-1)
		if (vis[vec[k][i]])
			merge(Ex[vec[k][i]],Ey[vec[k][i]]);
	if (l==r){
		if (!Qx[l]){
			ans[l]=ans[l-1];
			vis[Jud[l][ans[l]]]^=1;
		}
		else{
			int x=(Qx[l]+ans[l-1]-1)%n+1;
			int y=(Qy[l]+ans[l-1]-1)%n+1;
			ans[l]=(get(x)==get(y));
		}
	}
	else{
		int mid=(l+r)/2;
		solve(k*2,l,mid);
		solve(k*2+1,mid+1,r);
	}
	for (;top>posi;pop_back());
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) fa[i]=i,sz[i]=1;
	For(i,1,Q){
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			if (x>y) swap(x,y);
			q[++top]=(Info){i,0,x,y};
			x=x%n+1; y=y%n+1;
			if (x>y) swap(x,y);
			q[++top]=(Info){i,1,x,y};
		}
		else
			Qx[i]=x,Qy[i]=y;
	}
	sort(q+1,q+top+1);
	int id=1,suff;
	Ex[1]=q[1].x; Ey[1]=q[1].y;
	For(i,2,top+1){
		Jud[q[i-1].id][q[i-1].tp]=id;
		suff=(q[i].x!=q[i-1].x||q[i].y!=q[i-1].y?Q:q[i].id);
		if (q[i-1].id<suff) insert(1,1,Q,q[i-1].id+1,suff,id);
		if (i!=top+1&&(q[i].x!=q[i-1].x||q[i].y!=q[i-1].y))
			Ex[++id]=q[i].x,Ey[id]=q[i].y;
	}
	top=0;
	solve(1,1,Q);
	For(i,1,Q) if (Qx[i]) putchar('0'+ans[i]);
}