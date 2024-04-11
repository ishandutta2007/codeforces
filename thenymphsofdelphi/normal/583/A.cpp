#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, x, y;
    cin >> n;
    bool a[n], b[n];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n * n; i++){
    	cin >> x >> y;
    	if (!a[x - 1] && !b[y - 1]){
    		cout << i + 1 << " ";
    		a[x - 1] = 1;
    		b[y - 1] = 1;
		}
	}
}