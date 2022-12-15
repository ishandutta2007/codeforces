#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;
const int INF = int(1e9) + 99;

int t, n;
int a[N];
int l[N], r[N];
int dp[N];

int main() {
	scanf("%d", &t);
	for(int tc = 0; tc < t; ++tc){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			l[i] = INF;
			r[i] = -INF;
			dp[i] = 0;
		}

		vector <int> v;	
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			--a[i];
			v.push_back(a[i]);
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	
		int res = n;
		for(int i = v.size() - 1; i >= 0; --i){
			if(i + 1 == v.size() || r[v[i]] >= l[v[i + 1]]) dp[i] = 1;
			else dp[i] = 1 + dp[i + 1];
			res = min(res, int(v.size())- dp[i]);
		}

		printf("%d\n", res);
	}	

	return 0;
}