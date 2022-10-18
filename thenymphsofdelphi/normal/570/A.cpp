#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n >> m;
    int x, b[n], mxrow, mxcol = -1, idx;
    memset(b, 0, sizeof(b));
    for (int i = 0; i < m; i++){
    	mxrow = -1;
    	for (int j = 0; j < n; j++){
    		cin >> x;
    		if (x > mxrow){
    			mxrow = x;
    			idx = j;
			}
		}
		b[idx]++;
	}
	for (int i = 0; i < n; i++){
		if (b[i] > mxcol){
			mxcol = b[i];
			idx = i;
		}
	}
	cout << idx + 1;
}