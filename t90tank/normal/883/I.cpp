#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int N = 3e5L + 11;

int v[N], pre[N];

bool check(int n, int k, int lim) {
	for(int i = 0; i < k; i ++)
		pre[i] = 1;
	int j = 1;
	for(int i = k; i <= n; i ++) {
		while(v[i] - v[j] > lim)
			j ++;
		int l = j - 1, r = i - k;
		int sum = pre[r];
		if(l) sum -= pre[l - 1];
		pre[i] = (sum > 0);
		pre[i] += pre[i - 1];
	}
	return pre[n] - pre[n - 1];
}

int main() {
	int n, k; cin >> n >> k;
	
	for(int i = 1; i <= n; i ++) {
		scanf("%d", v + i);
	}
	sort(v + 1, v + n + 1);
	
	int l = 0, r = 1e9L + 1;
	while(l + 1 < r) {
		int m = (l + r) / 2;
		if(check(n, k, m - 1))
			r = m;
		else
			l = m;
	}
	cout << l << '\n';	

	return 0;
}