#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define IOS ios::sync_with_stdio(false);; cin.tie(NULL)
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100;
int main(){
	ll t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vi a(n);
		vector<int> arr[n];
		vector<int> ans(n,-1);
		F0R(i, n){
			int b;
			cin >> b;
			a[i] = b - 1;
			arr[a[i]].push_back(i);
			if(arr[a[i]].size() == 1){
			    ans[a[i]] = max(ans[a[i]], i + 1);
			}
			else{
				int val = arr[a[i]].size();
				ans[a[i]] = max(ans[a[i]], arr[a[i]][val - 1] - arr[a[i]][val - 2]);
			}
		}
		F0R(i, n){
			if(arr[i].size() == 0){
				continue;
			}
			else{
				int val = arr[i][arr[i].size() - 1];
				ans[i] = max(ans[i], ((n) - val));
			}
		}
		
		vector<int> total(n,1e9);
		int minimum_not_visited = n;
		F0R(i, n){
			int val = ans[i];
			if(val==-1)
			    continue;
			for(int x = val-1; x < minimum_not_visited; x++){
			    total[x] = min(total[x], i);
			}
			minimum_not_visited = min(minimum_not_visited, ans[i]-1);
		}
		F0R(i, n){
			if(total[i] == 1e9){
				total[i] = -2;
			}
		}
		F0R(i, n){
			cout << total[i]+1 << " ";
		}
		cout << endl;
	}
}