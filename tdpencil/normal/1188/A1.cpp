#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define vt vector
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back


void solve() {
	int n;
	scanf("%d", &n);
	vector<int> deg(n+1);
	
	for(int i=0;i<n-1;i++) {
		int x, y;scanf("%d%d", &x, &y);
		deg[x]++;
		deg[y]++;
	}
	
	for(int i = 1; i <= n; i++) {
		if(deg[i]==2) {
			puts("NO");
			return;
		}
	}
	puts("YES");
}
int main() {

	int t = 1, i = 1;
	while(t--) {
		// printf("Case #%d: ", i)
		solve();
		i++;
	}
}