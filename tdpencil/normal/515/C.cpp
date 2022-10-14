#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define gen generate
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define V vector
#define nl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define trav(x,y) for(auto &x:y)
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F0R(i,N) rep(i,0,N)
#define P pair


const int mxN=1e5,M=998244353,mod=1e9+7;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


inline ll nxt() {
	ll x; cin >> x;
	return x;
}
template<class T> bool umax(T &x, T y) {
	if(x < y) {
		x = y;
		return 1;
	}
	return 0;
}
template<class T> bool umin(T &x, T y) {
	if(x > y) {
		x = y;
		return 1;
	}
	return 0;
}


/*
when stuck:
        dp, see as ranges, greedy
        maybe intuition? ad-hoc?
        bs? bs with bitmasks?
        go backwards?
        solve for complement
        do stuff / write down
        draw? perhaps DAG or two pointers in disguise?
        template wrong?
        STOP PLAYING VALORANT
        STOP WATCHING TWITCH BOZO
    WA:
        input right?
        N, M or N, K?
        list[0] when doesn't exist?
        is right DS for problem?
        998244353 or 1000000007?
        overflow
    TLE:
        high constant factor? (switch to cpp bozo)
        while loop / for loop?
    RTE:
        divide 0 ? overflow? maybe empty ds
        forgot to remove com.company


*/
void solve(int test_case = 0) {
	int n; cin >> n;
	// casework
	// for 0 -> cant do anyathing
	// for 1 -> cant do anything
	// for 2 -> add a 2
	// for 3 -> add a 3
	// for 4 -> add a 3 and 2 and 2
	// for 5 -> add a 5
	// for 6 -> add a 3! and 5!
	// for 7 -> add a 7!
	// for 8 -> add a 2! * 2! * 2! and 7!
	// for 9 -> add 36 3s and 7!
	vector<int> lol;
	string s; cin >> s;
	for(char ch : s) {
		int num = ch - '0';
		if(num == 2)
			lol.pb(2);
		if(num == 3)
			lol.pb(3);
		if(num == 4)
			lol.pb(2), lol.pb(2), lol.pb(3);
		if(num == 5)
			lol.pb(5);
		if(num == 6)
			lol.pb(3), lol.pb(5);
		if(num == 7)
			lol.pb(7);
		if(num == 8)
			lol.pb(2), lol.pb(2), lol.pb(2), lol.pb(7);
		if(num == 9) {
			lol.pb(2), lol.pb(3), lol.pb(3), lol.pb(7);
		}
	}
	sort(lol.rbegin(), lol.rend());
	for(int i : lol)
		cout << i;
}

int main()
{
	//setup();
	cin.tie(0)->sync_with_stdio(0);
	// precalc();
	int T = 1;
	// cin >> T;
	for(int nt = 0, i; nt < T; nt++) {
		solve(nt);
		++i;
	}
}