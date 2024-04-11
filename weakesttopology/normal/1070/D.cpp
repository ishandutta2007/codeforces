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
	int n, k;
	cin >> n >> k;
	vi v(n);
	for(auto &x: v)cin >> x;
	reverse(v.begin(), v.end());
	ll res = 0, sum = 0;
	for(int i = 0; i < n; i++){
		if(v[i]%k){
			res++;
			if(i+1 < n){
				v[i+1]=max(v[i+1]+v[i]%k-k, 0);
			}
		}
		res+=v[i]/k;
	}
	cout << res << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}