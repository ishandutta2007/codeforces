#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

// Hashing structs
// hasher_base contains common values (modules, etc) and is common for all strings.
// hasher contains hashes for a single string.
// Hashes are stored as two long long values 
// (two hashes by two modules where modules are prime values near 1 << 31).

// Use: 
// Fill c for hasher
// Calc n for hasher (as strlen(c))
// Call build_hash for hasher
// Call get_hash for getting hash

// Note! ll works as long long! Do not use unsigned long long, it does not work!!!

// String maximal length
const int MAXLEN = 2e3 + 5;

// Count of symbols
const ll MAXVALUE = 1e3;

// Commn values (modules, p, stp, etc.)
struct hasher_base{
	// Module
	ll mod[2];

	// P
	ll p[2];

	// Powers of p
	ll stp[MAXLEN][2];
	
	// Init modules, p, etc.
	hasher_base(){
		// mod
		mod[0] = 2020202071ll;
		mod[1] = 2000000011ll;
		
		// p
		p[0] = max(MAXVALUE, rand() % mod[0]);				
		p[1] = max(MAXVALUE, rand() % mod[1]);
		
		// stp		
		for(int i = 0; i < 2; i++){			
			stp[0][i] = 1ll;
			for(int j = 1; j < MAXLEN; j++){
				stp[j][i] = (stp[j - 1][i] * p[i]) % mod[i];
			}
		}
	}
};

hasher_base hsh_base;

struct hasher{
	// String
	char s[MAXLEN];
	
	// String length
	int n;
	
	// Hashes
	ll hash[MAXLEN][2];
		
	// Build hashes
	void build_hash(){		
		// Fill hashes
		for(int i = 0; i < 2; i++){
			hash[0][i] = 0;
			for(int j = 0; j < n; j++){
				hash[j + 1][i] = (hash[j][i] * hsh_base.p[i] + s[j]) % hsh_base.mod[i];
			}
		}
	}
	
	// Get hash
	ll get_hash(int l, int r){
		ll v0 = (hash[r + 1][0] - hash[l][0] * hsh_base.stp[r - l + 1][0]) % hsh_base.mod[0];
		if (v0 < 0){
			v0 += hsh_base.mod[0];
		}
		ll v1 = (hash[r + 1][1] - hash[l][1] * hsh_base.stp[r - l + 1][1]) % hsh_base.mod[1];
		if (v1 < 0){
			v1 += hsh_base.mod[1];
		}
		return (v0 << 32ll) | v1;
	}
};

hasher hsht, hshp, hshs;

set<ll> hh[MAXLEN];

int good_p[MAXLEN], good_s[MAXLEN];

void solve(){
	scanf("%s%s%s", &hsht.s[0], &hshp.s[0], &hshs.s[0]);
	hsht.n = strlen(hsht.s);
	hshp.n = strlen(hshp.s);
	hshs.n = strlen(hshs.s);
	hsht.build_hash();
	hshp.build_hash();
	hshs.build_hash();
	ll hp = hshp.get_hash(0, hshp.n - 1);
	ll hs = hshs.get_hash(0, hshs.n - 1);
	REP(i, 0, hsht.n) {
		int l = i + hshp.n - 1;
		if (l < hsht.n) {
			ll v_p = hsht.get_hash(i, l);
			if (v_p == hp) {
				good_p[i] = 1;
			}
		}
		int r = i - hshs.n + 1;
		if (r >= 0) {
			ll v_s = hsht.get_hash(r, i);
			if (v_s == hs) {
				good_s[i] = 1;
			}
		}
	}
	REP(i, 0, hsht.n) {
		REP(j, i, hsht.n) {
			int l = i + hshp.n - 1;
			int r = j - hshs.n + 1;
			if (l > j || r < i) {
				continue;
			}
			if (good_p[i] && good_s[j]) {
				hh[j - i + 1].insert(hsht.get_hash(i, j));
			}
		}
	}
	int ans = 0;
	REPN(i, 0, hsht.n) {
		ans += SZ(hh[i]);
	}
	printf("%d\n", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}