#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second
const ll oo = 0x3f3f3f3f3f3f3f3fll; 

int n; 
int num[5]; 
int a[5]; 
int b[5];
int t[5];  
ll ans; 

ll check() {
	ll sum = 0; 
	for (int i = 0; i < 5; ++i) {
		if (a[i] >= 0) sum += (t[i]+1)*(250-a[i]); 
		if (b[i] >= 0) sum -= (t[i]+1)*(250-b[i]); 
	}
	if (sum <= 0) return oo; 
	//ll l = n - 1, r = oo; 
	for (ll m = n; m <= n * 33; ++m) {
		bool flag = true; 
		for (int i = 0; i < 5; ++i) {
			if (a[i] < 0) {
				flag &= (m/(1<<t[i]) >= num[i]); 
				if (t[i] != 5) flag &= (m/(1<<(t[i]+1)) + 1 <= num[i]); 
			}
			else {
				flag &= (m/(1<<t[i]) >= num[i]); 
				ll tmp; 
				if (t[i] == 5) tmp = m; 
				else tmp = m - (m / (1<<(t[i]+1)) + 1); 
				flag &= (tmp >= n-num[i]); 
			}
		}
		if (flag) {
			//if (m == n + 2) {
				//for (int i = 0; i < 5; ++i) printf( "%d ", t[i] ); 
				//puts( "" ); 
				//cout<<m/(1<<t[2])<<' '<<num[2]<<endl; 
			//}
			return m; 
		}
	}
	return oo; 
}

void dfs(int dep) {
	if (dep >= 5) {
		ans = min(ans, check()); 
		return; 
	}
	for (int i = 0; i <= 5; ++i) {
		t[dep] = i; 
		dfs(dep + 1); 
	}
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 0; i < 5; ++i) scanf( "%d", &a[i] ); 
	for (int i = 0; i < 5; ++i) scanf( "%d", &b[i] ); 
	for (int i = 0; i < 5; ++i) 
		num[i] = (a[i] >= 0) + (b[i] >= 0); 
	for (int i = 3; i <= n; ++i) {
		for (int j = 0; j < 5; ++j) {
			int x; 
			scanf( "%d", &x ); 
			if (x >= 0) num[j]++; 
		}
	}
	ans = oo;
	dfs(0); 
	if (ans == oo) puts( "-1" ); 
	else cout<<ans-n<<endl; 
}