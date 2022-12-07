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

int main(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	if ((x+y)&1) return puts("-1"),0;
	if (x>y) return puts("-1"),0;
	ll dd=(y-x)/2;
	if (!y&&!dd) return puts("0\n"),0;
	if (!dd) return printf("1\n%lld",x),0;
	if (!(dd&x)) return printf("2\n%lld %lld\n",dd,x+dd),0;
	printf("3\n%lld %lld %lld\n",dd,dd,x),0;
}