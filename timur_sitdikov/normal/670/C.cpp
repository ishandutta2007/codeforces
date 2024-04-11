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

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
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

map<int, int> cnt;

pii pp[MAXN];

void solve(){
	int n, m, a;
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d",&a);
		cnt[a]++;
	}
	scanf("%d", &m);
	REP(i, 0, m){
		scanf("%d", &pp[i].first);
	}
	REP(i, 0, m){
		scanf("%d", &pp[i].second);
	}
	pii mx = mp(-1, -1);
	int maxi = 0;
	REP(i, 0, m){
		int tmp1 = 0;
		if (cnt.find(pp[i].first) != cnt.end()){
			tmp1 = cnt[pp[i].first];
		}
		int tmp2 = 0;
		if (cnt.find(pp[i].second) != cnt.end()){
			tmp2 = cnt[pp[i].second];
		}
		pii tmpp = mp(tmp1, tmp2);
		if(tmpp > mx){
			mx = tmpp;
			maxi = i + 1;
		}
	}
	printf("%d\n", maxi);	
}	

int main(){
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();	
	}
}