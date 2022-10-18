#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define ld   long double
#define ull  unsigned long long
#define fi   first
#define se   second
#define pb   push_back
#define pob  pop_back
#define mp   make_pair
#define pque priority_queue
#define endl '\n'
typedef vector <int> 	vi;
typedef vector <ll>		vll;
typedef pair <int, int> ii;
typedef pair <int, int> llll;
typedef vector <vi > 	vvi;
typedef vector <vll > 	vvll;
typedef vector <ii > 	vii;
typedef vector <llll > 	vllll;

const ll N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string s, t, s1, t1;
	cin >> s >> t;
	s1 = s;
	t1 = t;
	sort(s1.begin(), s1.end());
	sort(t1.begin(), t1.end());
	if (s1 != t1){
	    cout << -1;
	    return 0;
	}
	vi ans;
	for (int i = 0; i < n - 1; i++){
	    if (s[i] == t[i]){
	        continue;
	    }
	    for (int j = i + 1; j < n; j++){
	        if (s[j] == t[i]){
	            for (int k = j - 1; k >= i; k--){
	                ans.pb(k);
	                swap(s[k], s[k + 1]);
	            }
	            break;
	        }
	    }
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++){
	    cout << ans[i] + 1 << ' ';
	}
}