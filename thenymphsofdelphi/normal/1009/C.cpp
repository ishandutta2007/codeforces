#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, m, s = 0, x, a, b, mid;
	cin >> n >> m;
	while (m--){
	    cin >> a >> b;
	    s += a * n;
	    if (b >= 0){
	        s += b * (n * (n - 1) / 2);
	    }
	    else{
	        mid = n / 2;
	        s += b * (mid * (mid + 1) / 2);
	        s += b * ((n - mid - 1) * (n - mid) / 2);
	    }
	}
	if (s == 0){
	    cout << "0.0000000";
	    return 0;
	}
	cout << fixed << setprecision(7) << (1.0 * s) / n;
}