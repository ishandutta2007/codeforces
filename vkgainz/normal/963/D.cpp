#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, MOD = 1e9+7;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;
 
 
typedef uint64_t ull;
static int C; // initialized below
 
// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() { return x ^ (ull) b << 21; }
	bool operator==(A o){ return ull(*this) == ull(o); }
	bool operator!=(A o){ return ull(*this) != ull(o); }
};
typedef A<1000000009, unsigned> H;
H pw[MAXN];
 
struct HashInterval { //get hashes of any interval
	int n;
	vector<H> ha;
	string s;
	HashInterval(string& str) : ha(sz(str)+1), s(str) {
		n = sz(str);
		rep(i,0,n)
			ha[i+1] = ha[i] * C + str[i];
	}
	H get(int a, int b) { // hash for range [a, b]
		b++;
		return ha[b] - ha[a] * pw[b - a];
	}
};
H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;} //get hash of string
 
#include <sys/time.h>
void pre_hashes(){ //call pre before testcases
	timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);
	
	pw[0]=1;
	rep(i,0,MAXN-1)
		pw[i+1] = pw[i] * C;
}
#include<bits/extc++.h>
struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
 
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;
 
int n, q;
string s;
vector<pair<int, string>> a;
hash_map<ull, int> hm[MAXN];
vector<int> locs[MAXN], lens;
 
void solve(){
    pre_hashes();
    cin >> s >> q;
    n = sz(s);
    for (int i = 0; i < q; i++) {
        int k; string m; cin >> k >> m;
        a.emplace_back(k, m);
        lens.push_back(sz(m));
        hm[sz(m)][ull(hashString(m))] = i;
    }
    sort(lens.begin(), lens.end());
    lens.resize(unique(lens.begin(), lens.end())-lens.begin());
 
    HashInterval h(s);
    for (int i = 0; i < n; i++) for (auto l : lens) {
        if (i+l-1 < n) {
            ull c = ull(h.get(i, i+l-1));
            if (hm[l].find(c) != hm[l].end()) {
                locs[hm[l][c]].push_back(i);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int k = a[i].first;
        int len = sz(a[i].second);
 
        if (sz(locs[i]) < k){ cout << -1 << '\n'; continue; }
 
        int ans = n;
        for (int j = 0; j+k-1 < sz(locs[i]); j++) {
            int l = locs[i][j], r = locs[i][j+k-1]+len-1;
            ans = min(ans, r-l+1);
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}