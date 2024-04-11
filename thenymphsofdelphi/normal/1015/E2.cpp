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

const ll N = 1005, mod = 1e9 + 7, inf = 1e18;
bool a[N][N], ck[N][N];
vector <pair <ii, int> > ans;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; i++){
	    cin >> s;
	    for (int j = 1; j <= m; j++){
	        if (s[j - 1] == '*'){
	            a[i][j] = 1;
	            ck[i][j] = 1;
	        }
	    }
	}
	for (int i = 2; i < n; i++){
	    for (int j = 2; j < m; j++){
	        int sz = 0;
	        while (a[i - sz][j] && a[i + sz][j] && a[i][j - sz] && a[i][j + sz]){
	            sz++;
	        }
	        if (sz >= 2){
	            //cout << i << ' ' << j << ' ' << sz << endl;
	            ans.pb(mp(mp(i, j), sz - 1));
	            for (int k = 0; k < sz; k++){
	                ck[i - k][j] = 0;
	                ck[i + k][j] = 0;
	                ck[i][j - k] = 0;
	                ck[i][j + k] = 0;
	            }
	        }
	    }
	}
	for (int i = 1; i <= n; i++){
	    for (int j = 1; j <= m; j++){
	        if (ck[i][j]){
	            cout << -1 << endl;
	            //cout << i << ' ' << j;
	            return 0;
	        }
	    }
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++){
	    cout << ans[i].fi.fi << ' ' << ans[i].fi.se << ' ' << ans[i].se << endl;
	}
}