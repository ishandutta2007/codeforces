
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9, M=1e9+7;
int N = 1e3+5;

int derangements[5]={1,0,1,2,9};

ll choose(ll a, ll b) {
	if(b) {
		return a * choose(a - 1, b - 1) / b;
	} else {
		return 1;
	}
}
void solve() {
	int N, K;
	cin >> N >> K;
	ll ans=1;
	for(int i=2; i<=K;i++) {
		ans+=choose(N,i)*derangements[i];
	}
	cout << ans << "\n";

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int test_case=1;
	
	while(test_case--) {
		solve();
	}
}