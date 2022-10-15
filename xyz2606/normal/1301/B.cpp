#include<bits/stdc++.h>
using namespace std;
const int N = 100011;
int a[N];
int main() {
	int t;
	cin >>t;
	for(int qq = 1; qq <= t; qq++) {
		int n;
		cin >> n;
		vector<int> vec;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
			if(i > 1 && (a[i] == -1 || a[i - 1] == -1) && !(a[i] == -1 && a[i - 1] == -1)) {
				vec.push_back(a[i] + a[i - 1] + 1);
			}
		}
		sort(vec.begin(), vec.end());
		int k = vec.empty() ? 1 : (vec.front() + vec.back()) / 2;
		for(int i = 1; i <= n; i++) if(a[i] == -1) a[i] = k;
		
		int ans = 0;
		for(int i = 1; i <= n; i++) if(i > 1) ans = max(ans, abs(a[i] - a[i - 1]));
		printf("%d %d\n", ans, k);
	}
}