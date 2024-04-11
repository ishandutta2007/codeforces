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
#define double long double
using namespace std;

void solve(){
	ll a,b,s=0;
	scanf("%lld%lld",&a,&b);
	for (;a%2==0;a/=2,--s);
	for (;b%2==0;b/=2,++s);
	if (a!=b) puts("-1");
	else printf("%d\n",(abs(s)+2)/3);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}