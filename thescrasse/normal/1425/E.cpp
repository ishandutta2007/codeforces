#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<int> a, d;

bool cmp(int i, int j){return d[i] < d[j];}

int32_t main(){
	cin >> n >> k;
	a.resize(n); d.resize(n);
	for(int& i:a) cin >> i;
	for(int& i:d) cin >> i;

	int ans = 0, sum = 0, tot;
	for(int i:a) sum += i;
	if(k == 0){
		tot = sum;
		for(int i=0; i<n; ++i){
			ans = max(ans, tot - d[i]);
			tot -= a[i];
		}
	}
	else if(k == 1){
		tot = sum; // excite 1, get all except i > 1
		int mm = 1e6;
		for(int i=1; i<n; ++i) mm = min(mm, a[i]);
		ans = max(ans, tot - mm - d[0]);
		tot = sum - a[0]; // excite i > 1, get from i to n
		for(int i=1; i<n; ++i){
			ans = max(ans, tot - d[i]);
			tot -= a[i];
		}
		tot = sum - a[n-1]; // excite i < n, get all < n
		int mincost = 1e6;
		for(int i=0; i<n-1; ++i) mincost = min(mincost, d[i]);
		ans = max(ans, tot - mincost);
		tot = sum; // excite two atoms except (1, 2), get all
		vector<int> v(n); iota(v.begin(), v.end(), 0); // indices of minimum cost
		sort(v.begin(), v.end(), cmp); // unnecessary but whatever
		ans = max(ans, tot - d[v[0]] - d[v[1]]);
	}
	else { // k >= 2
		ans = max(ans, a[n-1] - d[n-1]); // excite n, get n
		int mincost = 1e6; // excite i < n, get all
		for(int i=0; i<n-1; ++i) mincost = min(mincost, d[i]);
		ans = max(ans, sum - mincost);
	}
	cout << ans << endl;
}