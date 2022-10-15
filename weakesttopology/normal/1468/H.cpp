#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define EPS 1e-9
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef unsigned long long ull;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

void test_case(){
	int n, k, m, x;
	cin >> n >> k >> m;
	vi v(n);
	for(int i = 0; i < m; i++){
		cin >> x;
		v[x-1] = 1;
	}
	bool ok = true;
	if((n-m)%(k-1))ok = false;
	bool flag1 = 1, flag2 = 1;
	int pos = 0;
	while(v[pos])pos++;
	for(int i = 0; i < n-m && i + pos < n; i++)
		if(v[pos+i])flag1 = 0;
	int l = 0;
	for(int i = 0; i < n; i++){
		if(!v[i])l++;
		else if(min(l, n-m-l) >= k/2)flag2 = false;
	}
	if(ok && !flag1 && !flag2)cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}