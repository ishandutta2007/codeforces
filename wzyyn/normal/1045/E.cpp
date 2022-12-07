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
int n,m;
struct P{
	int x,y,c,id;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator +(const P &a)const{
		return P(x+a.x,y+a.y);
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
	bool operator ==(const P &a)const{
		return x==a.x&&y==a.y;
	}
}a[N],b[N];
pii ans[N];
int top;
bool cmp(P x,P y){
	return x*y>0;
}
void Convex_Hull(){
	sort(a+1,a+n+1);
	P bas=a[1];
	For(i,1,n){
		a[i].x-=bas.x;
		a[i].y-=bas.y;
	}
	sort(a+2,a+n+1,cmp);
	int top=1; b[1]=a[1];
	For(i,2,n){
		for (;top>=2&&(b[top]-b[top-1])*(a[i]-b[top])<=0;--top);
		b[++top]=a[i];
	}
	m=top;
}
bool In(P x,P y,P z,P p){
	return ((y-x)*(p-x)>0&&(z-y)*(p-y)>0&&(x-z)*(p-z)>0)||
		   ((y-x)*(p-x)<0&&(z-y)*(p-y)<0&&(x-z)*(p-z)<0);
}
void solve(P a,P b,P c,vector<P> v){
	//cout<<a.id<<' '<<b.id<<' '<<c.id<<endl;
	assert(a.c==b.c);
	assert(a.c!=c.c);
	bool flag=0;
	for (auto i:v) if (i.c!=a.c) flag=1;
	if (!flag){
		for (auto i:v)
			ans[++top]=pii(i.id,a.id);
		return;
	}
	P mid;
	for (auto i:v) if (i.c!=a.c) mid=i;
	ans[++top]=pii(c.id,mid.id);
	vector<P> d1,d2,d3;
	for (auto i:v){
		if (In(a,b,mid,i)) d1.PB(i);
		if (In(a,c,mid,i)) d2.PB(i);
		if (In(b,c,mid,i)) d3.PB(i);
	}
	solve(a,b,mid,d1);
	solve(c,mid,a,d2);
	solve(c,mid,b,d3);
}
void TRYITRY1(){
	int p1=0,p2=0;
	For(i,1,m)
		if (b[i].c==b[i%m+1].c)
			ans[++top]=pii(b[i].id,b[i%m+1].id);
		else p1?p2=i:p1=i;
	//cout<<p1<<' '<<p2<<endl;
	//For(i,1,m) cout<<b[i].id<<' '<<b[i].c<<endl;
	for (int x=p1%m+1;x!=p2;x=x%m+1){
		vector<P> tmp; tmp.resize(0);
		For(j,1,n) if (In(b[x],b[x%m+1],b[p2%m+1],a[j])) tmp.PB(a[j]);
		solve(b[x],b[x%m+1],b[p2%m+1],tmp);
	}
	for (int x=p2%m+1;x!=p1;x=x%m+1){
		vector<P> tmp; tmp.resize(0);
		For(j,1,n) if (In(b[x],b[x%m+1],b[p1%m+1],a[j])) tmp.PB(a[j]);
		solve(b[x],b[x%m+1],b[p1%m+1],tmp);
	}
}
void TRYITRY2(){
	P mid;
	For(i,1,n)
		if (a[i].c!=b[1].c)
			mid=a[i];
	For(i,1,m-1)
		ans[++top]=pii(b[i].id,b[i+1].id);
	//For(i,1,m) cout<<a[i].if<<endl;
	For(i,1,m){
		vector<P> tmp; tmp.resize(0);
		For(j,1,n) if (In(b[i],b[i%m+1],mid,a[j])) tmp.PB(a[j]);
		solve(b[i],b[i%m+1],mid,tmp);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		a[i].id=i-1;
	}
	bool flag=0;
	For(i,1,n) if (a[i].c!=a[1].c) flag=1;
	if (!flag){
		printf("%d\n",n-1);
		For(i,1,n-1) printf("0 %d\n",i);
		return 0;
	}
	if (n==2){
		puts("0");
		return 0;
	}
	Convex_Hull();
	int cnt=0;
	For(i,1,m)
		if (b[i].c!=b[i%m+1].c)
			++cnt;
	if (cnt>=4) return puts("Impossible"),0;
	//cout<<cnt<<endl;
	if (cnt==2) TRYITRY1();
	else TRYITRY2();
	printf("%d\n",top);
	For(i,1,top)
		printf("%d %d\n",ans[i].fi,ans[i].se);
}