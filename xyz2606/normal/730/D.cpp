#include<bits/stdc++.h>
using namespace std;
const int N(222222);
long long l[N], t[N];
int main() {
	int n;
	long long r;
	cin >> n >> r;
	for(int i(0); i < n; i++) {
		cin >> l[i];
	}
	long long curt(0), rmn(0), tot(0);
	vector<long long> ans;
	bool flag(true);
	for(int i(0); i < n; i++) {
		cin >> t[i];
		if(t[i] < l[i]) {
			flag = false;
			break;
		}
		//k + (l - k) * 2 <= t
		//2l-k<=t
		//k >= 2l-t
		long long ned(max(0ll, 2 * l[i] - t[i]));
		if(rmn >= ned) {
			curt += min(rmn, l[i]) + 2 * (l[i] - min(rmn, l[i]));
			rmn = max(0ll, rmn - l[i]);
		}else {
			curt += t[i];
			ned -= rmn;
			rmn = (r - ned % r) % r;
			tot += (ned + r - 1) / r;
			while(ans.size() <= 100000) {
				ans.push_back(curt - ned);
				ned -= r;
				if(ned <= 0) {
					break;
				}
			}
		}
	}
	if(!flag) {
		cout << -1 << endl;
	}else {
		cout << tot << endl;
		if(ans.size() <= 100000) {
			for(int i(0); i < (int)ans.size(); i++) {
				printf("%I64d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
			}
		}
	}
}