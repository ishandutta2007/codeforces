#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,tree-vectorize,no-inline-functions")
#pragma GCC target("popcnt,mmx,sse,sse2,sse3,sse4.1,sse4.2,avx,tune=native")
#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//


constexpr uint32_t SEG = 1<<15;

uint32_t n, A, B, C, D, ans = 0;

void countPrime(uint32_t p) {
	uint64_t x = p;
	uint32_t count = 0;
	while (x <= n) {
		count += uint32_t(n/x);
		x *= p;
	}

	uint32_t p2 = p*p;
	uint32_t p3 = p2*p;
	ans += count * (A*p3 + B*p2 + C*p + D);
}

void run() {
	cin >> n >> A >> B >> C >> D;

	vector<pair<uint32_t, uint32_t>> small;
	bitset<SEG> primes;
	primes.set();

	for (uint32_t i = 2; i < min(SEG, n+1); i++) if (primes[i]) {
		uint32_t j;
		for (j = i*i; j < min(SEG, n+1); j += i) {
			primes[j] = 0;
		}

		small.pb({i, j});
		countPrime(i);
	}

	for (uint32_t i = SEG; i <= n; i += SEG) {
		uint32_t limit = min(n+1, i+SEG);
		primes.set();

		each(p, small) {
			uint32_t j;
			for (j = p.y; j < limit; j += p.x) {
				primes[j-i] = 0;
			}
			p.y = j;
		}

		for (uint32_t j = i; j < limit; j++) if (primes[j-i]) {
			countPrime(j);
		}
	}

	cout << ans << endl;
}