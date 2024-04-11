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
	ll n, k;
	cin >> n >> k;
	ll a[n], b[n], sum = 0, sum2 = 0, cnt = 0, idx = 0;
	vll dif(n);
	for (int i = 0; i < n; i++){
	    cin >> a[i] >> b[i];
	    sum += b[i];
	    sum2 += a[i];
	    dif[i] = a[i] - b[i];
	}
	if (sum > k){
	    cout << -1;
	    return 0;
	}
	sort(dif.rbegin(), dif.rend());
	while (sum2 > k && idx < n){
	    cnt++;
	    sum2 -= dif[idx];
	    idx++;
	}
	cout << cnt;
}