//Submitting someone else's code so that Lockout bot knows I tested this contest

#include <bits/stdc++.h>

using namespace std;

int n,m;

void solve(){
	cin >> n >> m;
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			char o;cin >> o;
			if(o == 'C')continue;
			if(i == n and o == 'D')ans++;
			if(j == m and o == 'R')ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--){
		solve();
	}
	return 0;
}