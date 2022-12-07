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

struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
	P operator -(const P &a)const{
		return P(x-a.x,y-a.y);
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
}a[5005],b[5005];
int top,n;
ll ans;
bool in(P a){
	if (a.x) return a.x>0;
	return a.y>0;
}
bool cmp(P a,P b){
	if (in(a)!=in(b)) return in(a);
	return a*b>0;
}
void Func(int id){
	int top=0;
	For(i,1,n) if (i!=id) b[++top]=a[i]-a[id];
	ans+=1ll*(n-1)*(n-2)*(n-3)*(n-4)/24;
	//printf("%d\n",ans);
	sort(b+1,b+top+1,cmp);
	For(i,1,top) b[i+top]=b[i];
	int p=0;
	For(i,1,top){
		p=max(p,i);
		for (;p<i+top&&b[i]*b[p]>=0;++p);
		//printf("%d %d\n",i,p);
		ans-=1ll*(p-i-1)*(p-i-2)*(p-i-3)/6;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	For(i,1,n) Func(i);
	printf("%lld\n",ans);
}