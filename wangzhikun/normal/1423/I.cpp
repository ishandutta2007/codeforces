/*
 * Author       : YangDavid
 * Created Time : 2020.10.05 22:35:59
 */

#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename... Args> auto ndim(size_t sz0, Args&&... args) {
    if constexpr(sizeof...(args) == 1) return vector(sz0, args...);
    else return vector(sz0, ndim(args...));
}

const int MAXPAGE = (1<<16)+100, MAXN = 202020, TF = (1<<16)-1;
int K, q, lsb[MAXPAGE], msb[MAXPAGE], lcc[MAXPAGE][16], mcc[MAXPAGE][16];
unsigned FULL;
ll lp[MAXN], rp[MAXN], vp[MAXN];

bool check() {
	rep(i, q) {
		ll lu = lp[i]>>K, ru = rp[i]>>K, ld = lp[i]&FULL, rd = rp[i]&FULL;
		if((lsb[lu] & msb[ld]) != vp[i]) return false;
		if(lu == ru) {
			for(int j = 0; j < 16; ++j) {
				bool req = lsb[lu] >> j & 1;
				int tot = mcc[rd][j] - (ld?mcc[ld-1][j]:0);
				bool same = tot == 0 || tot == rd-ld+1;
				if(req && !same) return false;
			}
		} else {
			for(int j = 0; j < 16; ++j) {
				bool req = lsb[lu] >> j & 1;
				if(!req) continue;
				int tot = mcc[FULL][j] - (ld?mcc[ld-1][j]:0);
				bool same = tot == 0 || tot == FULL-ld+1;
				if(!same) return false;
			}
			for(int j = 0; j < 16; ++j) {
				bool req = lsb[ru] >> j & 1;
				if(!req) continue;
				int tot = mcc[rd][j];
				bool same = tot == 0 || tot == rd+1;
				if(!same) return false;
			}
			if(lu + 1 == ru) continue;
			for(int j = 0; j < 16; ++j) {
				int req = lcc[ru-1][j] - lcc[lu][j];
				if(!req) continue;
				int tot = mcc[FULL][j];
				bool same = tot == 0 || tot == FULL+1;
				if(!same) return false;
				if(tot == FULL + 1 && req != ru-1-lu) return false;
			}
		}
	}
	return true;
}
signed main() {
	scanf("%lld%lld", &K, &q);
	FULL = (1ULL<<K) - 1;
	rep(i, q) {
		scanf("%lld%lld%lld", lp+i, rp+i, vp+i);
		ll lu = lp[i]>>K, ru = rp[i]>>K, ld = lp[i]&FULL, rd = rp[i]&FULL;
		for(int j = 0; j < 16; ++j) {
			if(~vp[i] >> j & 1) continue;
			lcc[lu][j]++, lcc[ru+1][j]--;// printf("LCC[%lld,%lld][%lld] += 1\n",lu,ru,j);
			if(lu == ru) {
				mcc[ld][j]++, mcc[rd+1][j]--;
			} else if(lu == ru-1) {
				mcc[0][j]++, mcc[FULL+2][j]--;
				if(rd < ld)
					mcc[rd+1][j]--, mcc[ld][j]++;
			} else mcc[0][j]++, mcc[FULL+2][j]--;
		}
	}
	for(ll i = 0; i <= FULL; ++i) {
		for(int j = 0; j < 16; ++j) {
			if(i) {
				lcc[i][j] += lcc[i-1][j];
				mcc[i][j] += mcc[i-1][j];
			}
			lsb[i] |= (lcc[i][j] > 0 ? 1ULL : 0ULL) << j;
			msb[i] |= (mcc[i][j] > 0 ? 1ULL : 0ULL) << j;
		}
	}
	for(ll i = 0; i <= FULL; ++i) {
		for(int j = 0; j < 16; ++j) {
			lcc[i][j] = (i?lcc[i-1][j]:0) + (lcc[i][j] > 0);
			mcc[i][j] = (i?mcc[i-1][j]:0) + (mcc[i][j] > 0);
		}
	}
	if(check()) {
		puts("possible");
		for(int i = 0; i <= FULL; ++i)
			printf("%lld\n", msb[i]);
		for(int i = 0; i <= FULL; ++i)
			printf("%lld\n", lsb[i]);
	} else puts("impossible");

    return 0;
}