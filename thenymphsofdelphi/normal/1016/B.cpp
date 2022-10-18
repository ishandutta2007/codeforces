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
	ll n, m, q, x, y;
	cin >> n >> m >> q;
	string a, b;
	cin >> a >> b;
	if (m > n){
	    while (q--){
	        cout << 0 << endl;
	    }
	    return 0;
	}
	ll cnt[n - m + 2];
	cnt[0] = 0;
	for (int i = 0; i < n - m + 1; i++){
	    cnt[i + 1] = cnt[i];
	    bool ck = 1;
	    for (int j = 0; j < m; j++){
	        if (a[i + j] != b[j]){
	            ck = 0;
	            break;
	        }
	    }
	    if (ck){
	        cnt[i + 1]++;
	    }
	    //cout << cnt[i + 1] << ' ';
	}
	while (q--){
	    cin >> x >> y;
	    if (y - x + 1 < m){
	        cout << 0 << endl;
	        continue;
	    }
	    x--;
	    cout << cnt[y - m + 1] - cnt[x] << endl;
	}
}