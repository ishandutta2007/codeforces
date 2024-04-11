#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

bool check(ll n){
	ll x=n;
	for (;n;n/=10)
		if (n%10&&(x%(n%10)))
			return 0;
	return 1;
}
void solve(){
	ll n;
	scanf("%lld",&n);
	for (;!check(n);++n);
	printf("%lld\n",n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}