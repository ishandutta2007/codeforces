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
const int N=20005;
int n,mat[N];
struct P{
	int x,y,id;
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
}a[N],bas;
bool cmp(P x,P y){
	x.x-=bas.x; x.y-=bas.y;
	y.x-=bas.x; y.y-=bas.y;
	return 1ll*x.x*y.y-1ll*y.x*x.y>0;
}
void solve(int l,int r){
	if (l>r) return;
	int p=min_element(a+l,a+r+1)-a;
	swap(a[l],a[p]); bas=a[l];
	sort(a+l+1,a+r+1,cmp);
	int c0=0,c1=0,k=0;
	//printf("solve %d %d\n",l,r);
	//For(i,l,r) printf("%d %d\n",a[i].x,a[i].y); 
	For(i,l,r){
		(a[i].id<=n?++c0:++c1);
		if (c1==c0){
			k=i; break;
		}
	}
	if (a[k].id<a[l].id) swap(a[k],a[l]);
	mat[a[l].id]=a[k].id-n;
	solve(l+1,k-1);
	solve(k+1,r);
}
int main(){
	scanf("%d",&n);
	For(i,1,n*2){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	solve(1,n*2);
	For(i,1,n) printf("%d\n",mat[i]);
}