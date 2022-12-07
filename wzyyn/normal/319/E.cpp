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
const int N=200005;
pii q[N];
int Q,nd,tp[N],a[N];
int px,py,fa[N],at[N];
vector<int> t[N*4];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void insert(int k,int l,int r,int x,int y,int id){
	if (x<=l&&r<=y)
		return t[k].PB(id),void(0);
	int mid=(l+r)/2;
	if (x<=mid) insert(k*2,l,mid,x,y,id);
	if (y>mid) insert(k*2+1,mid+1,r,x,y,id);
}
void update(int k,int l,int r,int p,int id){
	for (;t[k].size();t[k].pop_back()){
		int x=get(t[k].back());
		q[nd].fi=min(q[nd].fi,q[x].fi);
		q[nd].se=max(q[nd].se,q[x].se);
		fa[x]=id;
	}
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) update(k*2,l,mid,p,id);
	else update(k*2+1,mid+1,r,p,id);
}
bool In(pii x,pii y){
	return (y.fi<x.fi&&x.fi<y.se)||
		   (y.fi<x.se&&x.se<y.se);
}
int main(){
	scanf("%d",&Q); nd=Q;
	For(i,1,Q) scanf("%d%d%d",&tp[i],&q[i].fi,&q[i].se);
	For(i,1,Q) if (tp[i]==1)
		a[++*a]=q[i].fi,a[++*a]=q[i].se;
	sort(a+1,a+*a+1);
	For(i,1,Q) fa[i]=i;
	For(i,1,Q)
		if (tp[i]==2){
			int x=get(at[q[i].fi]);
			int y=get(at[q[i].se]);
			puts(x==y||In(q[at[q[i].fi]],q[y])?"YES":"NO");
		}
		else{
			at[++*at]=i;
			q[i].fi=lower_bound(a+1,a+*a+1,q[i].fi)-a;
			q[i].se=lower_bound(a+1,a+*a+1,q[i].se)-a;
			q[++nd]=q[i]; fa[i]=fa[nd]=nd;
			update(1,1,*a,q[i].fi,nd);
			update(1,1,*a,q[i].se,nd);
			if (q[nd].se-q[nd].fi>1)
				insert(1,1,*a,q[nd].fi+1,q[nd].se-1,nd);
		}
}