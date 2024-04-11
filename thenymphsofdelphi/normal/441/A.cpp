#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, y, m, sum = 0;
    cin >> n >> m;
    bool a[n];
    int l;
    memset(a, 0, sizeof(a));
    for (int j = 0; j < n; j++){
    	cin >> l;
    	for (int i = 0; i < l; i++){
    		cin >> y;
    		if (y < m){
    			a[j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i]){
			sum++;
		}
	}
	cout << sum << endl;
	for (int i = 0; i < n; i++){
		if (a[i]){
			cout << i + 1 << " ";
		}
	}
}