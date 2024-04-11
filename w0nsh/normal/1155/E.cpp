#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;
	

std::mt19937 _gen;
std::uniform_int_distribution<int> _u_i_d(0, 1<<30);
inline int los(int a, int b){
	return a + _u_i_d(_gen)%(b-a+1);
}

const int MOD = 1000003;

int modpow(int a, int e){
	if(e == 0) return 1;
	int t = modpow(a, e/2);
	t = (1ll*t*t)%MOD;
	if(e % 2 == 1) t = (1ll*t*a)%MOD;
	return t;
}

struct P{
	std::vector<ll> a;
	ll row;
	P(){
		a.resize(12);
		row = 0;
	}
};

P operator +(const P &a, const P &b){
	P ret;
	FOR(i, 12) ret.a[i] = (a.a[i]+b.a[i])%MOD;
	FOR(i, 12) if(ret.a[i] < 0) ret.a[i] += MOD;
	ret.row = (a.row + b.row)%MOD;
	return ret;
}
P operator -(const P &a, const P &b){
	P ret;
	FOR(i, 12) ret.a[i] = (a.a[i]-b.a[i])%MOD;
	FOR(i, 12) if(ret.a[i] < 0) ret.a[i] += MOD;
	ret.row = (a.row - b.row)%MOD;
	if(ret.row < 0) ret.row += MOD;
	return ret;
}
P operator -(const P &a){
	P ret;
	FOR(i, 12) ret.a[i] = -a.a[i];
	FOR(i, 12) if(ret.a[i] < 0) ret.a[i] += MOD;
	ret.row = -a.row;
	if(ret.row < 0) ret.row += MOD;
	return ret;
}
P operator /(const P&a, const int d){
	P ret;
	FOR(i, 12) ret.a[i] = (1ll*a.a[i]*modpow(d, MOD-2))%MOD;
	FOR(i, 12) if(ret.a[i] < 0) ret.a[i] += MOD;
	ret.row = (1ll*a.row*modpow(d, MOD-2))%MOD;
	if(ret.row < 0) ret.row += MOD;
	return ret;
}
P operator *(const P&a, const int d){
	P ret;
	FOR(i, 12) ret.a[i] = (1ll*a.a[i]*d)%MOD;
	FOR(i, 12) if(ret.a[i] < 0) ret.a[i] += MOD;
	ret.row = (1ll*a.row*d)%MOD;
	if(ret.row < 0) ret.row += MOD;
	return ret;
}

void wypisz(P v){
	FOR(i, 12) std::cout << v.a[i] << " ";
	std::cout << " = " << v.row << std::endl;
}

P my;

void wyz(int pos, std::vector<P> vec){
	P v = vec.back();
	// wypisz(v);
	if(pos == 11){
		ll ile = v.a[pos];
		assert(ile != 0);
		v = v/ile;
		my.a[pos] = v.row;
		return;
	}
	vec.pop_back();
	ll ile = v.a[pos];
	assert(ile != 0);
	v = v/ile;
	FOR(i, SZ(vec)){
		// std::cout << "mam ";
		// wypisz(vec[i]);
		ile = vec[i].a[pos];
		assert(ile != 0);
		vec[i] = vec[i] / ile;
		vec[i] = vec[i] - v;
		// std::cout << "teraz ";
		// wypisz(vec[i]);
	}
	wyz(pos+1, vec);
	ll ths = v.row;
	REP(i, pos+1, 12){
		ths = (1ll*ths-1ll*v.a[i]*my.a[i])%MOD;
	}
	if(ths < 0) ths += MOD;
	my.a[pos] = ths;
}

int main(){
	_gen.seed(std::chrono::steady_clock::now().time_since_epoch().count());
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<P> vec;
	REP(i, 1, 15){
		std::cout << "? " << i << std::endl;
		P xd;
		std::cin >> xd.row;
		if(xd.row == 0){
			std::cout << "! " << i << std::endl;
			return 0;
		}
		FOR(j, 12){
			xd.a[j] = modpow(i, j);
		}
		vec.push_back(xd);
		// FOR(j, 12) std::cout << vec.back().a[j] << " ";
		// std::cout << std::endl;
	}
	wyz(0, vec);
	// wypisz(my);
	FOR(i, 1000003){
		ll have = 0;
		FOR(j, 12){
			have = (have + my.a[j]*modpow(i, j))%MOD;
		}
		if(have < 0) have += MOD;
		if(have == 0){
			std::cout << "! " << i << std::endl;
			return 0;
		}
	}
	std::cout << "! " << -1 << std::endl;
	return 0;
}