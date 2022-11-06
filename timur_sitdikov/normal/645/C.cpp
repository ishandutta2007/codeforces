#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<long double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for((i) = (a); (i) < (int)(b); (i)++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

#define file "cycle"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;

char c[MAXN];

int dpl[MAXN], dpr[MAXN];

void solve(){
	int n, k, i, j;
	scanf("%d%d%s", &n, &k, &c[0]);
	dpl[0] = (c[0] =='0' ? 0 : -1);
	for(i = 1; i < n; i++){
		dpl[i] = dpl[i - 1];
		if (c[i] == '0'){
			dpl[i] = i;
		}
	}
	dpr[n - 1] = (c[n - 1] == '0' ? n - 1 : n);
	for(i = n - 2; i >= 0; i--){
		dpr[i] = dpr[i + 1];
		if (c[i] == '0'){
			dpr[i] = i;
		}
	}
	int cnt = 0;
	for(j = 0; j < n; j++){
		if (c[j] == '0'){
			cnt++;
			if (cnt == k + 1){
				break;
			}
		}
	}
	for(i = 0; c[i] != '0'; i++);
	int ans = n;
	for(; j < n; ){
		int l = i, r = j;
		int mid1 = (l + r) / 2, mid2 = (l + r) / 2 + 1;
		int v1 = dpl[mid1], v2 = dpr[mid1], v3 = dpl[mid2], v4 = dpr[mid2];
		int cur = max(v1 - l, r - v1);
		cur = min(cur, max(v2 - l, r - v2));
		cur = min(cur, max(v3 - l, r - v3));
		cur = min(cur, max(v4 - l, r - v4));
		ans = min(ans, cur);
		for(i++; c[i] != '0'; i++);
		for(j++; j < n && c[j] != '0'; j++);
	}
	cout << ans << endl;
}	

int main(){

	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}