#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int MOD = 998244353;

int modpow(int a, int e){
	int ret = 1;
	while(e){
		if(e&1) ret = (1ll*ret*a)%MOD;
		a = (1ll*a*a)%MOD;
		e>>=1;
	}
	return ret;
}

int fact[200005];
int inv[200005];
int invfact[200005];

template<class T>
struct BIT{
	std::vector<T> t;
	inline int LSB(int a){ return a&(-a); }
	BIT(){}
	BIT(int sz){ t.resize(sz+1); }
	void add(int x, T val){
		x++;
		while(x < (int)t.size()) t[x] += val, x += LSB(x); // change operation here
	}
	T query(int x){
		x++;
		T r = 0;
		while(x > 0) r += t[x], x -= LSB(x); // change operation here
		return r;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	fact[0] = inv[0] = invfact[0] = 1;
	REP(i, 1, 200005){
		fact[i] = (1ll*fact[i-1] * i)%MOD;
		invfact[i] = modpow(fact[i], MOD-2);
		inv[i] = modpow(i, MOD-2);
	}

	int n, m;
	std::cin >> n >> m;
	VI A(n);
	VI B(m);
	FOR(i, n) std::cin >> A[i];
	FOR(i, m) std::cin >> B[i];

	BIT<int> bit(200005);
	std::map<int, int> cnt;
	TRAV(i, A) bit.add(i, 1), cnt[i]++;

	int val = fact[n];
	TRAV(pr, cnt){
		val = (1ll*val * invfact[pr.Y])%MOD;
	}

	int ans = 0;

	int kt = n;
	bool bad = false;

	FOR(i, SZ(A)){
		if(i >= SZ(B)) break;

		int x = B[i];
		val = (1ll * val * inv[kt--])%MOD;
		ans = (ans + 1ll * val * bit.query(x-1))%MOD;
		if(!cnt[x]){
			bad = true;
			break;
		}
		val = (1ll * val * cnt[x])%MOD;
		cnt[x]--;
		bit.add(x, -1);
	}

	if(!bad && (SZ(A) < SZ(B))){
		ans = (ans + val)%MOD;
	}

	std::cout << ans << "\n";

	return 0;
}