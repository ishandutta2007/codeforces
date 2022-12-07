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
const int N=100005;
struct P{
	ll x,y;
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	bool operator <(const P &a)const{
		return x==a.x?y<a.y:x<a.x;
	}
}a[N];
int n;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].y-=1ll*a[i].x*a[i].x;
	}
	sort(a+1,a+n+1);
	int top=1;
	For(i,2,n){
		for (;top>1&&(a[top]-a[top-1])*(a[i]-a[top-1])>=0;--top);
		a[++top]=a[i];
	}
	int ans=0;
	For(i,2,top) ans+=(a[i].x!=a[i-1].x);
	printf("%d\n",ans);
}