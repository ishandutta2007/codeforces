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
int n,fa[N],m,Q,pl,pr;
int v[N],fav[N],ri[N],top;
int x[N],y[N],sz[N];
pii op[N];
int get(int x){
	if (x==fa[x]) return x;
	int t=get(fa[x]);
	v[x]=v[fa[x]]^fav[x];
	return t;
}
bool Insert(int id){
	int px=get(x[id]);
	int py=get(y[id]);
	if (px==py){
		if (v[x[id]]^v[y[id]]^1)
			return 0;
	}
	else{
		if (sz[px]>sz[py]) swap(px,py);
		fav[px]=v[x[id]]^v[y[id]]^1;
		fa[px]=py; sz[py]+=sz[px];
		op[++top]=pii(px,py);
	}
	return 1;
}
void erase(int ed){
	for (;top>ed;--top){
		int x=op[top].fi;
		int y=op[top].se;
		fa[x]=x; fav[x]=v[x]=0; sz[y]-=sz[x];
	}
}
void build(int l,int r,int L,int R){
	if (l>r) return;
	int tmp=top;
	for (;pl<=l;Insert(pl++));
	for (;pr>=R;Insert(pr--));
	int tmp2=top;
	int pos=R-1;
	int mid=(l+r)/2;
	for (;pl<=mid;Insert(pl++));
	for (;pos>mid&&pos>=L;--pos)
		if (!Insert(pos)) break;
	//cout<<"res "<<mid<<' '<<pos<<' '<<l<<' '<<R<<endl;
	ri[mid]=++pos;
	erase(tmp2); pl=l+1; pr=R-1;
	build(l,mid-1,L,pos);
	erase(tmp2); pl=l+1; pr=R-1;
	build(mid+1,r,pos,R);
	erase(tmp);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,m) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) fa[i]=i,sz[i]=1;
	pl=1; pr=m;
	int ed=m+1;
	bool flag=0;
	For(i,1,m)
		if (!Insert(i)){
			ed=i; break;
		}
	erase(0);
	For(i,ed,m) ri[i]=m+2;
	build(0,ed-1,1,m+1);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		puts(y+1>=ri[x-1]?"NO":"YES");
	}
}
/*
6 6 4
1 3
1 5
1 6
2 5
2 6
3 4
1 1
2 2
3 3
1 6
*/