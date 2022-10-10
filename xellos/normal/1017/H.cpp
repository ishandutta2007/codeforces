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

struct query {
	int l, r, K, id;

	bool operator<(const query & Q) const {
		return r < Q.r;
	}
};

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

struct fin {
	vector<int> T;
	fin(int N) : T(N+10, 0) {}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i)) T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) ret += T[i];
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	map<int, vector<int> > queries_by_K;
	vector<query> QV(Q);
	for(int i = 0; i < Q; i++) {
		cin >> QV[i].l >> QV[i].r >> QV[i].K;
		QV[i].id = i;
		QV[i].l--;
	}
	sort(begin(QV), end(QV));
	for(int i = 0; i < Q; i++) queries_by_K[QV[i].K].push_back(i);
	int X = 300;
	vector<int> rare, common;
	vector< vector<int> > elems_by_occ(M);
	for(int i = 0; i < N; i++) elems_by_occ[--A[i]].push_back(i);
	for(int i = 0; i < M; i++) {
		if((int)elems_by_occ[i].size() >= X) common.push_back(i);
		else rare.push_back(i);
	}
	cat mod = 998244353;
	vector<cat> ans(Q, 1);
	ALL_THE(queries_by_K, it) {
		cat K = it->ff;
		vector<cat> cnt(N+1, 1);
		for(int i = 1; i <= N; i++) cnt[i] = cnt[i-1] * (M*K%mod + i) % mod;
		ALL_THE(it->ss, jt) {
			query q_cur = QV[*jt];
			ans[q_cur.id] = ans[q_cur.id] * cnt[N-(q_cur.r-q_cur.l)] % mod;
		}
	}
	for(int i = 0; i < (int)common.size(); i++) {
		int e = common[i];
		vector<int> cnt(N+1, 0);
		ALL_THE(elems_by_occ[e], it) cnt[(*it)+1]++;
		for(int j = 1; j <= N; j++) cnt[j] += cnt[j-1];
		vector<cat> prod(cnt[N]+1, 1);
		ALL_THE(queries_by_K, it) {
			int K = it->ff;
			for(int j = cnt[N]; j > 0; j--)
				prod[j-1] = prod[j] * (K + j) % mod;
			ALL_THE(it->ss, jt) {
				query q_cur = QV[*jt];
				int cnt_cur = cnt[q_cur.r] - cnt[q_cur.l];
				ans[q_cur.id] = ans[q_cur.id] * prod[cnt[N]-cnt_cur] % mod;
			}
		}
	}
	int MX = 110000;
	vector< vector<cat> > invfac_pw(MX+1, vector<cat>(20, 1));
	for(int i = 1; i <= MX; i++) invfac_pw[i][0] = invfac_pw[i-1][0] * pw(i, mod-2, mod) % mod;
	for(int i = 0; i <= MX; i++) for(int j = 1; j < 20; j++)
		invfac_pw[i][j] = invfac_pw[i][j-1] * invfac_pw[i][j-1] % mod;
	ALL_THE(queries_by_K, it) {
		int K = it->ff;
		cat prodc = 1;
		vector<cat> fac(K+X+1, 1);
		for(int i = 1; i <= K+X; i++) fac[i] = i * fac[i-1] % mod;
		ALL_THE(rare, jt) prodc = prodc * fac[K+elems_by_occ[*jt].size()] % mod;
		ALL_THE(it->ss, jt) ans[QV[*jt].id] = ans[QV[*jt].id] * prodc % mod;
	}
	vector< vector<int> > cnt_occ(Q, vector<int>(X, 0));
	vector<fin> F(X, fin(N));
	vector<int> Fsum(X, 0);
	ALL_THE(rare, it) for(int i = 0; i < (int)elems_by_occ[*it].size(); i++) {
		Fsum[i]++;
		F[i].put(elems_by_occ[*it][i], 1);
	}
	int a = 0;
	vector<int> b(M, 0);
	for(int i = 0; i < N; i++) {
		if((int)elems_by_occ[A[i]].size() < X) {
			int x = A[i], sz = elems_by_occ[A[i]].size();
			for(int j = 0; j < sz; j++) {
				F[j].put(elems_by_occ[x][(b[x]+j)%sz], -1);
				Fsum[j]--;
			}
			b[x]++;
			for(int j = 0; j < sz; j++) {
				F[j].put(elems_by_occ[x][(b[x]+j)%sz], 1);
				Fsum[j]++;
			}
		}
		while(a < Q && QV[a].r == i+1) {
			for(int j = 0; j < X; j++) cnt_occ[a][j] = Fsum[j]-F[j].get(QV[a].r-1)+F[j].get(QV[a].l-1);
			a++;
		}
	}
	for(int i = 0; i < Q; i++) {
		for(int j = 0; j <= X-2; j++) cnt_occ[i][j] -= cnt_occ[i][j+1];
		int zero = rare.size();
		for(int j = X-1; j > 0; j--) {
			cnt_occ[i][j] = cnt_occ[i][j-1];
			zero -= cnt_occ[i][j];
		}
		cnt_occ[i][0] = zero;
	}
	for(int i = 0; i < Q; i++) {
		for(int j = 0; j < X; j++) {
			int x = QV[i].K+j;
			int e = cnt_occ[i][j];
			for(int k = 0; k < 20; k++) {
				if(e == 0) break;
				if((e>>k)&1) {
					ans[QV[i].id] = ans[QV[i].id] * invfac_pw[x][k] % mod;
					e -= 1<<k;
				}
			}
		}
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
	return 0;
}

// look at my code
// my code is amazing