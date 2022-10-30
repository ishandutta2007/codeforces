#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair <int, int> pii;

const int maxn = 2e5 + 5;

int n;
int a[maxn];
int g[maxn], l[maxn];
ll pg[maxn], pl[maxn];
int s;

signed main() {
    sync;
	cin >> n;
	cin >> s;
	F(i, 0, n)cin >> a[i];
	sort(a, a + n);
	ll ans = -1;
	int lt = 0, eq = 0, gr = 0;
	F(i, 0, n){
		if(a[i] < s){l[lt++] = a[i];}
		if(a[i] == s)++eq;
		if(a[i] > s){g[gr++] = a[i];}
	}
	if(a[n/2] == s){cout << 0; ret 0;}
	reverse(l, l + lt);
	F(i, 0, lt){
		pl[i] = i == 0 ? 0 : pl[i - 1];
		pl[i] += l[i];
	}
	F(i, 0, gr){
		pg[i] = i == 0 ? 0 : pg[i - 1];
		pg[i] += g[i];
	}
	ll wat = 0;
	F(i, 0, lt + 1){
		int cs = eq + i;
		int rpos = lt + eq;
		if(lt - i - 1 < n/2){
			ll curr = wat;
			if(rpos <= n/2)curr += pg[n/2 - rpos] - (n/2 - rpos + 1) * 1ll * s;
			if(ans == -1 || ans > curr)ans = curr;
		}
		if(i != lt)wat += s - l[i];
	}
	cout << ans;
    return 0;
}