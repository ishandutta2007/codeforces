#include<bits/stdc++.h>
using namespace std;
#define int long long
#define push_back pb
#define pop_back pob
#define make_pair mp
#define endl "\n"

const int N = 2005, mod = 1000000007, inf = 1000000000000;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, mx = 0, cnt = 0;
	cin >> n >> k;
	int a[n], b[n], c[k], idx[k];
	bool d[k];
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	if (k == 1){
	    int mx = -1;
	    for (int i = 0; i < n; i++){
	        mx = max(mx, a[i]);
	    }
	    cout << mx << endl << n;
	    return 0;
	}
	sort(b, b + n);
	for (int i = n - 1; i >= n - k; i--){
		c[i - n + k] = b[i];
		//cout << b[i] << " ";
		mx += b[i];
	}
	//cout << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < k; j++){
			if (a[i] == c[j] && d[j] == false){
				d[j] = true;
				idx[cnt] = i;
				cnt++;
				break;
			}
		}
	}
	cout << mx << endl;
	for (int i = 0; i < k; i++){
		if (i == 0) cout << idx[i] + 1 << " ";
		else if (i == k - 1) cout << n - idx[i - 1] - 1;
		else cout << idx[i] - idx[i - 1] << " ";
	}
}