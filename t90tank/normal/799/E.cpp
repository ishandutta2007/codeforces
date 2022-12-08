#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int maxn = 200006; 
const ll oo = 0x3f3f3f3f3f3f3f3fll;

int n, m, k; 
int cost[maxn]; 
int d[maxn]; 
vector<ll> q[4]; 
int c[4];
ll sum; 

void addminp() {
	int x = 0; 
	for (int i = 1; i <= 2; ++i) 
		if (q[i][c[i]] < q[x][c[x]]) x = i; 
	sum += q[x][c[x]++]; 
}

int main() {
	scanf( "%d%d%d", &n, &m, &k ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &cost[i] ); 
	int a; 
	scanf( "%d", &a ); 
	for (int i = 1; i <= a; ++i) {
		int x; 
		scanf( "%d", &x ); d[x] += 1; 
	}
	scanf( "%d", &a ); 
	for (int i = 1; i <= a; ++i) {
		int x; 
		scanf( "%d", &x ); d[x] += 2; 
	}
	for (int i = 1; i <= n; ++i) 
		q[d[i]].pb(cost[i]); 
	for (int i = 0; i <= 3; ++i) sort(q[i].begin(), q[i].end()); 
	sum = 0; 
	int t1 = 0; 
	for (int i = 0; i < (int)q[3].size() && i < m; ++i) {
		sum += q[3][i]; 
		t1++; 
	}
	//cout<<q[1].size()<<' '<<q[2].size()<<' '<<q[3].size()<<endl; 
	if (k-t1 > (int)q[1].size() || k-t1 > (int)q[2].size()) {
		cout<<-1<<endl; 
		return 0; 
	}
	int t2 = t1; 
	for (int i = 0; i < k-t1; ++i) {
		sum += q[1][i]; 
		sum += q[2][i]; 
		t2 += 2; 
	}
	if (t2 > m) {
		cout<<-1<<endl; 
		return 0; 
	}
	ll ans = sum; 
	q[0].pb(oo); 
	q[1].pb(oo); 
	q[2].pb(oo); 
	c[1] = c[2] = max(0,k-t1);  
	while (t2 < m) {
		addminp(); 
		//if (q[1][c[1]] < q[2][c[2]]) 
			//sum += q[1][c[1]++]; 
		//else sum += q[2][c[2]++]; 
		t2++; 
	}
	ans = max(ans, sum); 
	for (int i = t1-1; i >= 0; --i) {
		sum -= q[3][i]; 
		if (c[1]+i < k && c[2]+i < k) {
			if (c[0] == 0) break; 
			if (c[1] == (int)q[1].size()-1) break; 
			if (c[2] == (int)q[2].size()-1) break; 
			sum -= q[0][--c[0]]; 
			sum += q[1][c[1]++]; 
			sum += q[2][c[2]++]; 
		}
		else if (c[1]+i < k) {
			if (c[1] == (int)q[1].size()-1) break; 
			sum += q[1][c[1]++]; 
		}
		else if (c[2]+i < k) {
			if (c[2] == (int)q[2].size()-1) break; 
			sum += q[2][c[2]++]; 
		}
		else {
			//if (c[1] == (int)q[1].size()-1 && c[2] == (int)q[2].size()-1) break; 
			//if (q[1][c[1]] < q[2][c[2]]) 
				//sum += q[1][c[1]++]; 
			//else sum += q[2][c[2]++]; 
			if (c[0] == (int)q[0].size()-1 && c[1] == (int)q[1].size()-1 && c[2] == (int)q[2].size()-1) break; 
			addminp(); 
		}
		//cout<<sum<<endl; 
		ans = min(ans, sum); 
	}
	cout<<ans<<endl; 
}