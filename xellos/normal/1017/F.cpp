#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

using bset = uint64_t;
using val = uint32_t;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, MX = 300000000;
	val coef[4];
	cin >> N >> coef[0] >> coef[1] >> coef[2] >> coef[3];
	vector<bset> is_prime(MX/3/64+1, 0);
	// small primes
	val ans = 0;
	for(int p = 2; p*p <= MX; p++) {
		bool ok = true;
		for(int i = 2; i*i <= p; i++) if(p%i == 0) {
			ok = false;
			break;
		}
		if(!ok) continue;
		if(p <= N) {
			val cnt = 0;
			int n = N;
			while(n > 0) {
				cnt += n/p;
				n /= p;
			}
			val cur = 0;
			for(int i = 0; i < 4; i++) cur = cur * p + coef[i];
			ans += cur * cnt;
		}
		if(p > 3) {
			int pos = p;
			while((pos-p)%6 != 0) pos++;
			for(int prod = pos*p/6; pos <= MX/p; pos += 6, prod += p) is_prime[prod>>5] |= 1ULL<<((prod&31)<<1);
			int neg = p;
			while((neg+p)%6 != 0) neg++;
			for(int prod = neg*p/6; neg <= MX/p; neg += 6, prod += p) is_prime[prod>>5] |= 1ULL<<((prod&31)*2+1);
		}
	}
	for(int k = 0; k <= MX/3; k++) if(((is_prime[k>>6]>>(k&63))&1) == 0) {
		int p = (k/2)*6 + ((k&1) ? 5 : 1);
		if(1LL*p*p <= MX || p > N) continue;
		val cnt = 0;
		int n = N;
		while(n > 0) {
			cnt += n/p;
			n /= p;
		}
		val cur = 0;
		for(int i = 0; i < 4; i++) cur = cur * p + coef[i];
		ans += cur * cnt;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing