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
int s[40005];
void solve(){
	int a,b,q;
	scanf("%d%d%d",&a,&b,&q);
	For(i,1,a*b) s[i]=(s[i-1]+(i%a%b!=i%b%a));
	while (q--){
		ll l,r;
		scanf("%lld%lld",&l,&r); l--;
		ll ans=s[a*b]*(r/a/b)+s[r%(a*b)];
		ans-=s[a*b]*(l/a/b)+s[l%(a*b)];
		printf("%lld ",ans);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}