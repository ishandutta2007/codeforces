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
int n,p[N],w[N],pos[N],v[N],rt[N];
int ls[N],rs[N],fa[N],nd;
ll sz[N],val[N],ans;

const int M=70000005;
int Ls[M],Rs[M],S[M],ndd;
void change(int &k,int l,int r,int p,int v){
	if (!k) k=++ndd; 
	S[k]+=v;
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(Ls[k],l,mid,p,v);
	else change(Rs[k],mid+1,r,p,v);
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return S[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(Ls[k],l,mid,x,y);
	if (x>mid) return ask(Rs[k],mid+1,r,x,y);
	return ask(Ls[k],l,mid,x,mid)+ask(Rs[k],mid+1,r,mid+1,y);
}
void update(int k,int v,int d){
	assert(fa[k]);
	if (ls[fa[k]]==k) val[fa[k]]+=d*ask(rt[rs[fa[k]]],1,n,1,v);
	else val[fa[k]]+=d*ask(rt[ls[fa[k]]],1,n,v,n);
	change(rt[k],1,n,v,d);
}
ll Func(int k){
	return min(val[k],sz[k]-val[k]);
}
int build(int l,int r){
	//cout<<l<<' '<<r<<endl;
	int k=++nd;
	if (l==r) return pos[l]=k,k;
	int mid=min_element(w+l,w+r)-w;
	sz[k]=1ll*(mid-l+1)*(r-mid);
	ls[k]=build(l,mid);
	rs[k]=build(mid+1,r);
	fa[ls[k]]=fa[rs[k]]=k;
	For(i,l,mid) update(ls[k],p[i],1);
	For(i,mid+1,r) update(rs[k],p[i],1);
	ans+=Func(k);
	return k;
}
void change(int x,int v1,int v2){
	for (int y=x;fa[y];y=fa[y]){
		ans-=Func(fa[y]);
		update(y,v1,-1);
		update(y,v2,1);
		ans+=Func(fa[y]);
	}
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n-1) scanf("%d",&w[i]);
	build(1,n);
	//cerr<<233<<' '<<ans<<endl;
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		change(pos[x],p[x],p[y]);
		change(pos[y],p[y],p[x]);
		swap(p[x],p[y]);
		//cout<<val[1]<<' '<<val[2]<<' '<<sz[1]<<' '<<sz[2]<<endl;
		cout<<ans<<endl;
	}
}