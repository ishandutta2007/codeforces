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
const int d1[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
const int d2[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};
const int d3[4][2]={{0,0},{-1,0},{-1,-1},{0,-1}};
const int N=200005;
int n,m,top,ok[4];
map<int,int> mn,mx;
struct P{
	int x,y;
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
	ll dis(){
		return 1ll*x*x+1ll*y*y;
	}
}a[N],q[N*4];
bool cmp(P x,P y){
	if (x*y) return x*y>0;
	return x.dis()<y.dis();
}
void Convex_hull(){
	sort(q+1,q+top+1);
	top=unique(q+1,q+top+1)-q-1;
	P bas=a[1];
	//For(i,1,top) cout<<q[i].x<<' '<<q[i].y<<endl;
	For(i,1,top) q[i]=q[i]-bas;
	sort(q+2,q+top+1,cmp);
	//For(i,1,top) cout<<q[i].x<<' '<<q[i].y<<endl;
	n=top; top=1;
	For(i,2,n){
		for (;top>=2&&(q[top]-q[top-1])*(q[i]-q[top])<=0;top--);
		q[++top]=q[i];
	}
	For(i,1,top)
		q[i]=q[i]+bas;
}
bool chk(int x,int y){
	if (mn.find(x)==mn.end()) return 0;
	return mn[x]<=y&&mx[x]>=y;
}
void solve(){
	top=0;
	scanf("%d%d",&n,&m);
	if (!(n+m)) exit(0);
	mn.clear(); mx.clear();
	For(i,1,m) scanf("%d%d",&a[i].x,&a[i].y);
	For(i,1,m) mn[a[i].x]=n+1,mx[a[i].x]=0;
	For(i,1,m){
		mn[a[i].x]=min(mn[a[i].x],a[i].y);
		mx[a[i].x]=max(mx[a[i].x],a[i].y);
	}
	For(i,1,m){
		ok[0]=ok[1]=ok[2]=ok[3]=1;
		For(j,0,3)
			if (!chk(a[i].x+d1[j][0],a[i].y+d1[j][1]))
				ok[j]=ok[(j+1)%4]=0;
		For(j,0,3)
			if (!chk(a[i].x+d2[j][0],a[i].y+d2[j][1]))
				ok[j]=0;
		For(j,0,3) if (ok[j])
			q[++top]=P(a[i].x+d3[j][0],a[i].y+d3[j][1]);
	}
	//cout<<top<<endl;
	Convex_hull();
	reverse(q+2,q+top+1);
	printf("%d\n",top);
	For(i,1,top) printf("%d %d\n",q[i].x,q[i].y);
}
int main(){
	for (;;) solve();
}