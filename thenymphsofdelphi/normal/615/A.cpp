#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, x, y;
    cin >> n >> x;
    bool a[x];
    int l;
    memset(a, 0, sizeof(a));
    for (int j = 0; j < n; j++){
    	cin >> l;
    	for (int i = 0; i < l; i++){
    		cin >> y;
    		a[y - 1] = true;
		}
	}
	for (int i = 0; i < x; i++){
		if (!a[i]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}