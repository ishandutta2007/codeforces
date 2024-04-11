#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;

int n, k, l;
vector <int> a;

signed main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> l;
	for (int i = 0; i < n * k; i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int last = upper_bound(a.begin(), a.end(), a[0] + l) - a.begin() - 1;
	last = min(last, (n - 1) * k);
	if (last < n - 1){
	    cout << 0 << endl;
	    return 0;
	}
	int res = 0, cur = 1;
	for (int i = last; i >= 0; i--){
		if (n * k - i >= cur * k){
			res += a[i];
			cur++;
		}
		if (cur == n + 1){
		    break;
		}
	}
	cout << res << endl;
}