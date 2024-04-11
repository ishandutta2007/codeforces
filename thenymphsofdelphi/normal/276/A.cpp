#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 10000000000;

signed main(){
	int n, k, a, b, mn = -INF;
	cin >> n >> k;
	while (n--){
		cin >> a >> b;
		if (b <= k){
			mn = max(mn, a);
		}
		else{
			mn = max(mn, a - b + k);
		}
	}
	cout << mn;
}