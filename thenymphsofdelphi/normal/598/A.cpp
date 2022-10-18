#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
    	int x, ans;
    	cin >> x;
    	ans = x * (x + 1) / 2;
    	int l2 = log2(x);
    	l2 = pow(2, l2 + 2);
    	ans -= l2 - 2;
    	cout << ans << endl;
	}
}