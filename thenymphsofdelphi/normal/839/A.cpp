#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k, x, c = 0, c2 = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
    	cin >> x;
    	c2 += x;
    	c += min(8LL, c2);
    	c2 -= min(8LL, c2);
    	if (c >= k){
    		cout << i + 1;
    		return 0;
		}
	}
	cout << -1;
	return 0;
}