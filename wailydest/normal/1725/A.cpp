//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n';
void solve(){
	ll n,m;
	cin>>n>>m;
	if (m==1){
		cout<<(n-1)<<endl;
		return;
	}
	m -= 1;
	cout<<n*m<<endl;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tt = 1;
//	cin>>tt;
	while(tt--){
		solve();
	}
}