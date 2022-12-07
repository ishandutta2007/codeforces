#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

void solve(){
	ll n;
	scanf("%lld",&n);
	n=max(n,6ll); n+=n&1;
	cout<<n/2*5<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}