#include<bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;
typedef long long int ll;
typedef long double dbl;
typedef unsigned long long uli;
typedef pair<int, int> pii;

#define X first
#define Y second
#define F(i, l, r) for(int i = l; i < r; i++)
#define DF(i, l, r) for(int i = l; i > r; i--)
#define I(i, a) for(auto i : a)
#define pb push_back
#define rs resize
#define mp make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase
#define fi0(x) memset(x, 0, sizeof(x))
#define finf(x) memset(x, 127, sizeof(x))
#define y1 adjf
#define tm dhgdg

const int MAXN = 1e5 + 5;
const ll inf = 1e14 + 14;

int n;
ll k;
int a[MAXN];
ll rr[MAXN];
int id[MAXN], w[MAXN];
int t[MAXN];

inline int get(int pos){
	int res = 0;
	while(pos){
		res += t[pos];
		pos -= pos&-pos;
	}
	ret res;
}

inline void inc(int pos){
	while(pos <= 1 + n){
		t[pos]++;
		pos += pos&-pos;
	}
}

ll f(ll T){
	ll res = 0;
	ll pref = 0ll;
	fi0(t);
	inc(1 + id[0]);
	F(i, 0, n + 1)rr[i] += T;
	F(i, 0, n){
		pref += a[i];
		int pos = upper_bound(rr, rr + n + 1, pref) - rr;
		res += get(pos);
		inc(1 + id[i + 1]);
	}
	F(i, 0, n + 1)rr[i] -= T;
	ret res;
}

void prepare(){
	ll p = 0;
	rr[0] = 0;
	F(i, 0, n){
		p += a[i];
		rr[i + 1] = p;
	}
	F(i, 0, n + 1)w[i] = i;
	sort(w, w + n + 1, [&](const int & l, const int & r){return rr[l] < rr[r];});
	F(i, 0, n + 1)id[w[i]] = i;
	sort(rr, rr + n + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	F(i, 0, n)cin >> a[i];
	prepare();
	ll l = -inf, r = inf;
	while(r - l > 1){
		ll mid = (l + r)/2;
		if(f(mid) >= k)l = mid;
		else r = mid - 1;
	}
	if(f(r) >= k)l = r;
	cout << l;
	return 0;
}