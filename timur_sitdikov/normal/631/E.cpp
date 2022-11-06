#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define REP(i, a, b) for((i) = (int)(a); (i) < (int)(b); (i)++)
#define REPN(i, a, b) for((i) = (int)(a); (i) <= (int)(b); (i)++)
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

struct point{
	ll x, y;
	point(){}
	point(ll _x, ll _y){
		x = _x, y = _y;
	}
};

bool operator < (const point &a, const point &b){
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

ll cross(point &o, point &a, point &b){
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

point pt[MAXN], pt1[MAXN], pt2[MAXN], pol[MAXN];
int n, top;
ll sum[MAXN], v[MAXN];
pii pp[MAXN];

// answer will be in pol
void convex_hull(){
	if (n == 1){
		pol[0] = pt[0];
		top = 1;
		return;
	}
	int i, top1, top2;
	sort(pt, pt + n);
	pt1[0] = pt2[0] = pt[0];
	top1 = top2 = 1;
	for(i = 1; i < n; i++){
		ll d = cross(pt[0], pt[n - 1], pt[i]);		
		if (i == n - 1 || d > 0){
			for(; top2 >= 2 && cross(pt2[top2 - 2], pt2[top2 - 1], pt[i]) >= 0; top2--);
			pt2[top2++] = pt[i];
		}
		if (i == n - 1 || d < 0){
			for(; top1 >= 2 && cross(pt1[top1 - 2], pt1[top1 - 1], pt[i]) <= 0; top1--);
			pt1[top1++] = pt[i];
		}
	}
	top = 0;
	for(i = 0; i < top1; i++){
		pol[top++] = pt1[i];
	}
	for(i = top2 - 2; i > 0; i--){
		pol[top++] = pt2[i];
	}
}

ll calc_dif(int s, int to){
	
	return (ll)(to - s) * v[s] + sum[s] - sum[to];
	
	/*s = max(s, 1);
	to = max(to, 1);
	if (s == to){
		return 0ll;
	}
	if (s < to){
		ll res = v[s] * (to - s) - (sum[to] - sum[s]);
		return res;
	}
	if (s > to){
		ll res = -v[s] * (s - to);
		if (s){
			res += sum[s - 1];
		}
		if (to){
			res -= sum[to - 1];
		}
		return res;
	}*/
}

void solve(){
	int i, ind, j, a;
	scanf("%d", &n);
	ll add = 0ll;
	pt[0] = point(0ll, 0ll);
	REPN(i, 1, n){
		scanf("%d", &a);
		
		pp[i - 1] = mp(a, i);
		add += (ll)a * (ll)i;
		v[i] = a;
		sum[i] = sum[i - 1] + a;
		
		pt[i] = point((ll)i, sum[i]);
	}
	n++;
	convex_hull();
	n--;
	sort(pp, pp + n);
	ll ans = add;
	REP(ind, 0, top){
		if (pt[ind].x == 0ll && pt[ind].y == 0ll){
			break;
		}
	}
	REP(i, 0, n){
		j = pp[i].second;
		ll cur1, cur2;
		while(1){
			cur1 = calc_dif(j, pol[ind].x);
			cur2 = calc_dif(j, pol[(ind + 1) % top].x);
			if (cur2 > cur1){
				ind = (ind + 1) % top;
			} else {
				break;
			}
		}
		// cout << j << " " << pol[ind].x << " " << cur1 << endl;
		ans = max(ans, add + cur1);
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