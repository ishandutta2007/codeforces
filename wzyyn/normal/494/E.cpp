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
/*
const int N=105;
int vis[N],sg[N][N];
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) For(j,1,m){
		memset(vis,0,sizeof(vis));
		For(dk,1,min(min(i,j),k)){
			int v=0;
			For(dx,0,dk-1) For(dy,0,dk-1)
				if (dx||dy) v^=sg[i-dx][j-dy];
			vis[v]=1;
		}
		for (;vis[sg[i][j]];++sg[i][j]);
		printf("%d%c",sg[i][j],j==m?'\n':' ');
	}
}
*/
const int N=200005;
int q[N],m,k,top;
struct rect{
	int x1,y1,x2,y2;
}a[N];
struct opt{
	int x,l,r,v;
	bool operator <(const opt &a)const{
		return x<a.x;
	}
}op[N];
pii t[N*4];
int tg[N*4];
void build(int k,int l,int r){
	t[k]=pii(0,(q[r+1]-q[l])&1);
	tg[k]=0;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void add(int k,int v){
	tg[k]+=v;
	t[k].fi+=v;
}
void pushup(int k){
	t[k]=pii(min(t[k*2].fi,t[k*2+1].fi),0);
	if (t[k].fi==t[k*2].fi) t[k].se^=t[k*2].se;
	if (t[k].fi==t[k*2+1].fi) t[k].se^=t[k*2+1].se;
}
void pushdown(int k){
	if (!tg[k]) return;
	add(k*2,tg[k]);
	add(k*2+1,tg[k]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y) return add(k,v);
	pushdown(k);
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,y,v);
	if (y>mid) change(k*2+1,mid+1,r,x,y,v);
	pushup(k);
}
bool check(){
	*q=0; top=0;
	For(i,1,m)
		if (a[i].y1<=a[i].y2&&a[i].x1<=a[i].x2){
			//cout<<a[i].x1<<' '<<a[i].y1<<' '<<a[i].x2<<' '<<a[i].y2<<endl;
			q[++*q]=a[i].y1,q[++*q]=a[i].y2+1;
			op[++top]=(opt){a[i].x1  ,a[i].y1,a[i].y2,1};	
			op[++top]=(opt){a[i].x2+1,a[i].y1,a[i].y2,-1};
		}
	if (!top) return 0;
	sort(q+1,q+*q+1);
	sort(op+1,op+top+1);
	*q=unique(q+1,q+*q+1)-q-1;
	build(1,1,(*q)-1);
	int ans=0;
	For(i,1,top){
		int p1=lower_bound(q+1,q+*q+1,op[i].l)-q;
		int p2=lower_bound(q+1,q+*q+1,op[i].r+1)-q-1;
		change(1,1,(*q)-1,p1,p2,op[i].v);
		//cout<<i<<' '<<op[i].x<<' '<<op[i+1].x<<' '<<t[1].se<<endl; 
		if ((op[i+1].x-op[i].x)&1)
			ans^=(q[*q]-q[1]-(t[1].fi?0:t[1].se))&1;
	}
	//cout<<(ans&1)<<endl;
	return ans&1;
}
int main(){
	scanf("%*d%d%d",&m,&k);
	For(i,1,m) scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	for (int v=1;v<=k;v<<=1){
		if (check()) return puts("Hamed");
		For(i,1,m){
			a[i].x1=(a[i].x1+a[i].x1%2)/2;
			a[i].y1=(a[i].y1+a[i].y1%2)/2;
			a[i].x2=(a[i].x2-a[i].x2%2)/2;
			a[i].y2=(a[i].y2-a[i].y2%2)/2;
		}
	}
	puts("Malek");
}