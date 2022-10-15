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
	vi v(4);
	for(auto &x: v)cin >> x;
	int res = 0;
	sort(v.begin(), v.end());
	do{
		res = max(res, min(v[0], v[1]) * min(v[2], v[3]));
	}while(next_permutation(v.begin(), v.end()));
	cout << res << endl;
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