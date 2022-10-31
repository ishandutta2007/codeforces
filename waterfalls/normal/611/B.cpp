#include <bits/stdc++.h>
using namespace std;

long long a,b;
vector<long long> has;

int main() {
	for (int i=2;i<=60;i++) {
		for (int j=0;j<i-1;j++) {
			long long cur = 0;
			for (int k=0;k<i;k++) if (k!=j) {
				cur = cur+(1LL<<k);
			}
			has.push_back(cur);
		}
	}
	sort(has.begin(),has.end());
	cin >> a >> b;
	cout << (upper_bound(has.begin(),has.end(),b)-lower_bound(has.begin(),has.end(),a));

	return 0;
}