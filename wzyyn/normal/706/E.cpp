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
const int N=1010000;
int n,m,Q,a[N],ri[N],dn[N];
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n+1) For(j,1,m+1){
		int id=(i-1)*(m+1)+j;
		ri[id]=id+1; dn[id]=id+m+1;
		if (i!=1&&j!=1) scanf("%d",&a[id]); 
	}
	while (Q--){
		int a,b,c,d,h,w;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
		int x=1,y=1,xx,yy;
		For(i,1,a-1) x=dn[x];
		For(i,1,b-1) x=ri[x];
		For(i,1,c-1) y=dn[y];
		For(i,1,d-1) y=ri[y];
		//cout<<x<<' '<<y<<endl;
		xx=x; yy=y;
		For(i,1,w) xx=ri[xx],yy=ri[yy],swap(dn[xx],dn[yy]);
		//cout<<xx<<' '<<yy<<endl;
		For(i,1,h) xx=dn[xx],yy=dn[yy],swap(ri[xx],ri[yy]);
		//cout<<xx<<' '<<yy<<endl;
		xx=x; yy=y;
		For(i,1,h) xx=dn[xx],yy=dn[yy],swap(ri[xx],ri[yy]);
		For(i,1,w) xx=ri[xx],yy=ri[yy],swap(dn[xx],dn[yy]);
	}
	int x=1;
	For(i,1,n){
		int y=x=dn[x];
		For(j,1,m) printf("%d ",a[y=ri[y]]);
		puts("");
	}
}