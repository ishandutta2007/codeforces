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
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

typedef unsigned long long ll;

ll MOD =998244353LL; // prime, MOD-1 divisible by a large power of 2

ll pw(ll a, ll e) {
	if(e <= 0) return 1;
	ll x =pw(a,e/2);
	x =(x*x)%MOD;
	if(e%2 != 0) x =(x*a)%MOD;
	return x;}

ll proot =3; // primitive MOD-1th root of unity %MOD
vector< vector<ll> > OM;
vector<ll> DEP;

vector<ll> DFT(vector<ll> &A, int N, int d, int x, int dir) {
	vector<ll> ret(N,0);

	if(N == 1) {
		ret[0] =A[x];
		return ret;}
	if(N == 2) {
		ret[0] =(A[x]+A[x+d])%MOD;
		ret[1] =(A[x]+MOD-A[x+d])%MOD;
		return ret;}

	int dep =DEP[N];

	vector<ll> DFT0[2];
	DFT0[0] =DFT(A,N/2,d*2,x,dir);
	DFT0[1] =DFT(A,N/2,d*2,x+d,dir);
	for(int i =0; i < N/2; i++) {
		ll com =OM[dep][(N+dir*i)%N];
		ret[i] =(DFT0[0][i]+com*DFT0[1][i])%MOD;
		ret[i+N/2] =(DFT0[0][i]+(MOD-com)*DFT0[1][i])%MOD;}
	return ret;}

int SN =1<<20; // arbitrary power of 2 such that N <= SN

vector<ll> convolution(vector<ll> A, vector<ll> B) {
	if((int)A.size() < 50) {
		vector<ll> ret(A.size()*2-1);
		ll mod2 = MOD * MOD * 4;
		for(int i = 0; i < (int)A.size(); i++) for(int j = 0; j < (int)B.size(); j++) {
			ret[i+j] += A[i] * B[j];
			if(ret[i+j] >= mod2) ret[i+j] -= mod2;
		}
		for(int i = 0; i < (int)ret.size(); i++) ret[i] %= MOD;
		return ret;
	}

	int Smin =1;
	while(Smin < (int)A.size()*2) Smin *=2;

	// init na omegy
	if(OM.empty()) {
		OM.resize(21);
		for(int i =0; i < 21; i++) {
			ll root =pw(proot,(MOD-1)/(1<<i)); // prim. root modulo N=2**i
			OM[i].resize(1<<i,1);
			for(int j =1; j < (1<<i); j++) OM[i][j] =(OM[i][j-1]*root)%MOD;
			reverse(begin(OM[i])+1,end(OM[i]));} // see NOTE
		DEP.resize(SN+1);
		for(int i = 1; i <= SN; i++) {
			int dep = 0, n = i;
			while(n > 1) n /= 2, dep++;
			DEP[i] = dep;}
		}

	A.resize(Smin,0); B.resize(Smin,0);
	vector<ll> FA =DFT(A,A.size(),1,0,1);
	vector<ll> FB =DFT(B,B.size(),1,0,1);

	vector<ll> Fret(FA.size(),0);
	for(uint i =0; i < FA.size(); i++) Fret[i] =(FA[i]*FB[i])%MOD;

	vector<ll> ret =DFT(Fret,Fret.size(),1,0,-1);
	ll inv = pw(ret.size(),MOD-2);
	for(uint i =0; i < ret.size(); i++) ret[i] =(ret[i]*inv)%MOD; // normalise
	ret.resize(A.size()*2-1);

	return ret;}

vector<cat> poly_prod(vector<cat> V, int K, cat mod) {
	int N = V.size();
	if(N <= 10) {
		vector<cat> ret(min(K+1, N+1), 0);
		ret[0] = 1;
		for(int i = 0; i < N; i++) for(int j = min(K, i+1); j > 0; j--)
			ret[j] = (ret[j] + ret[j-1] * V[i]) % mod;
		return ret;
	}
	vector<cat> Vl, Vr;
	for(int i = 0; i < N/2; i++) Vl.push_back(V[i]);
	for(int i = N/2; i < N; i++) Vr.push_back(V[i]);
	vector<cat> Pl = poly_prod(Vl, K, mod), Pr = poly_prod(Vr, K, mod);
	vector<ll> Rl(min(K+1, (int) max(Pl.size(), Pr.size())), 0);
	vector<ll> Rr(min(K+1, (int) max(Pl.size(), Pr.size())), 0);
	for(int i = 0; i < min(K+1, (int)Pl.size()); i++) Rl[i] = Pl[i];
	for(int i = 0; i < min(K+1, (int)Pr.size()); i++) Rr[i] = Pr[i];
	vector<ll> R = convolution(Rl, Rr);
	vector<cat> ret(min(K+1, N+1), 0);
	for(int i = 0; i < min(K+1, N+1); i++) ret[i] = R[i];
	return ret;
}

vector<cat> poly_inv(vector<cat> & P, int deg, cat mod) {
	int deg_p2 = deg;
	while(deg_p2&(deg_p2-1)) deg_p2++;
	vector<ll> A(1, 1);
	for(int l = 1; l < deg_p2; l *= 2) {
		vector<ll> L(l), U(l);
		for(int i = 0; i < min((int)P.size(), l); i++) L[i] = P[i];
		vector<ll> C = convolution(L, A);
		C.push_back(0);
		for(int i = 0; i < l; i++) C[i] = C[i+l];
		C.resize(l);
		for(int i = l; i < min((int)P.size(), 2*l); i++) U[i-l] = P[i];
		vector<ll> R = convolution(A, U);
		R.resize(l, 0);
		for(int i = 0; i < l; i++) R[i] = (R[i] + C[i]) % mod;
		vector<ll> B = convolution(R, A);
		A.resize(2*l, 0);
		for(int i = 0; i < l; i++) A[i+l] = (mod - B[i]) % mod;
	}
	vector<cat> ret(deg);
	for(int i = 0; i < deg; i++) ret[i] = A[i];
	return ret;
}

vector<cat> poly_rem(vector<cat> & P, vector<cat> Q, cat mod) {
	// P % Q
	if(P.size() < Q.size()) return P;
	int deg = P.size() - Q.size() + 1;
	vector<cat> Pi = P;
	reverse(begin(Pi), end(Pi));
	Pi.resize(min((int)Pi.size(), deg));
	vector<cat> Qi = Q;
	reverse(begin(Qi), end(Qi));
	vector<cat> Qii = poly_inv(Qi, deg, mod);
	vector<ll> pi(max(Pi.size(), Qii.size()), 0);
	for(int i = 0; i < (int)Pi.size(); i++) pi[i] = Pi[i];
	vector<ll> qii(max(Pi.size(), Qii.size()), 0);
	for(int i = 0; i < (int)Qii.size(); i++) qii[i] = Qii[i];
	vector<ll> D = convolution(pi, qii);
	D.resize(deg, 0);
	reverse(begin(D), end(D));
	D.resize(max(Q.size(), D.size()), 0);
	vector<ll> q(max(Q.size(), D.size()), 0);
	for(int i = 0; i < (int)Q.size(); i++) q[i] = Q[i];
	vector<ll> sub = convolution(q, D);
	while(sub.size() > P.size() && sub.back() == 0) sub.pop_back();
	vector<cat> ret = P;
	for(int i = 0; i < (int)sub.size(); i++) {
		ret[i] = (ret[i] - (cat) sub[i]) % mod;
		if(ret[i] < 0) ret[i] += mod;
	}
	while((int)ret.size() > 1 && ret.back() == 0) ret.pop_back();
	assert(ret.size() < Q.size());
	return ret;
}

class poly_eval_tree {
	vector<cat> X;
	vector< vector<cat> > Q;
	vector< vector<int> > son;
	cat mod;

	void build_tree(int l, int r, int cur) {
		if(r-l <= 10) {
			Q[cur].resize(r-l+1, 0);
			Q[cur][0] = 1;
			for(int i = l; i < r; i++) for(int j = i-l+1; j >= 0; j--)
				Q[cur][j] = (((j == 0) ? 0 : Q[cur][j-1]) - X[i] * Q[cur][j]) % mod;
			for(int i = 0; i <= r-l; i++) if(Q[cur][i] < 0) Q[cur][i] += mod;
			return;
		}
		son[cur][0] = son.size();
		son.push_back(vector<int>(2, -1));
		Q.push_back(vector<cat>());
		build_tree(l, (l+r)/2, son[cur][0]);
		son[cur][1] = son.size();
		son.push_back(vector<int>(2, -1));
		Q.push_back(vector<cat>());
		build_tree((l+r)/2, r, son[cur][1]);
		vector<ll> Ql(max(Q[son[cur][0]].size(), Q[son[cur][1]].size()), 0);
		for(int i = 0; i < (int)Q[son[cur][0]].size(); i++)
			Ql[i] = Q[son[cur][0]][i];
		vector<ll> Qr(max(Q[son[cur][0]].size(), Q[son[cur][1]].size()), 0);
		for(int i = 0; i < (int)Q[son[cur][1]].size(); i++)
			Qr[i] = Q[son[cur][1]][i];
		vector<ll> C = convolution(Ql, Qr);
		int sz = Q[son[cur][0]].size() + Q[son[cur][1]].size() - 1;
		Q[cur].resize(sz);
		for(int i = 0; i < sz; i++) Q[cur][i] = C[i];
	}

public:
	poly_eval_tree(vector<cat> X, cat mod) : X(X), mod(mod) {
		son.dibs(2*X.size()+10);
		son.push_back(vector<int>(2, -1));
		Q.dibs(2*X.size()+10);
		Q.push_back(vector<cat>());
		build_tree(0, X.size(), 0);
	}

	vector<cat> eval(vector<cat> & P, int l, int r, int cur = 0) {
		int N = P.size();
		if(N <= 10 || son[cur][0] == -1) {
			vector<cat> ret(r-l, 0);
			for(int j = l; j < r; j++)
				for(int i = N-1; i >= 0; i--) ret[j-l] = (ret[j-l] * X[j] + P[i]) % mod;
			return ret;
		}
		vector<cat> Pl = poly_rem(P, Q[son[cur][0]], mod);
		vector<cat> Pr = poly_rem(P, Q[son[cur][1]], mod);
		vector<cat> retl = eval(Pl, l, (l+r)/2, son[cur][0]);
		vector<cat> retr = eval(Pr, (l+r)/2, r, son[cur][1]);
		ALL_THE(retr, it) retl.push_back(*it);
		return retl;
	}
};

vector<cat> poly_eval_dedup(vector<cat> P, vector<cat> X, cat mod) {
	int x = X.size();
	vector< pair<cat, int> > Xs(x);
	for(int i = 0; i < x; i++) Xs[i] = {X[i], i};
	sort(begin(Xs), end(Xs));
	vector<cat> Xu;
	for(int i = 0; i < x; i++) if(i == 0 || Xs[i].ff != Xs[i-1].ff)
		Xu.push_back(Xs[i].ff);
	poly_eval_tree T(Xu, mod);
	vector<cat> ret_dedup = T.eval(P, 0, Xu.size());
	int a = 0;
	vector<cat> ret(x);
	for(int i = 0; i < x; i++) if(i == 0 || Xs[i].ff != Xs[i-1].ff) {
		for(int j = i; j < x; j++) {
			if(Xs[j].ff != Xs[i].ff) break;
			ret[Xs[j].ss] = ret_dedup[a];
		}
		a++;
	}
	return ret;
}

void DFS(int R, vector< vector<int> > & G, vector<int> & par, vector<cat> & S) {
	S[R] = 1;
	ALL_THE(G[R], it) if(par[*it] == -1) {
		par[*it] = R;
		DFS(*it, G, par, S);
		S[R] += S[*it];
	}
}

void DFS2(int R, vector< vector<int> > & G, vector<int> & par, vector<cat> & val, vector<cat> & sum_val, cat mod) {
	sum_val[R] = val[R];
	ALL_THE(G[R], it) if(par[*it] == R) {
		DFS2(*it, G, par, val, sum_val, mod);
		sum_val[R] += sum_val[*it];
	}
	sum_val[R] %= mod;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	cat mod = 998244353;
	if(K == 1) {
		cout << 1LL*N*(N-1)/2 % mod << "\n";
		return 0;
	}
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> par(N, -1);
	vector<cat> S(N);
	par[0] = 0;
	DFS(0, G, par, S);

	vector<cat> inv(K+1, 1);
	for(int i = 1; i <= K; i++) inv[i] = inv[i-1] * pw(i, mod-2, mod) % mod;
	cat fac = 1;
	for(int i = 1; i <= K; i++) fac = fac * i % mod;

	vector<cat> cntK_down(N, 0), cntK_up(N, 0);
	for(int i = 0; i < N; i++) {
		vector<cat> V(G[i].size());
		for(int j = 0; j < (int)G[i].size(); j++) {
			if(par[G[i][j]] == i) V[j] = S[G[i][j]];
			else V[j] = N-S[i];
		}
		vector<cat> P = poly_prod(V, K, mod);
		int sz = P.size();
		vector<ll> Pu(sz, 0), Iu(sz, 0);
		for(int j = 0; j < sz; j++) Pu[j] = P[j];
		for(int j = 0; j < sz; j++) Iu[j] = inv[K+1-sz+j];
		vector<ll> C = convolution(Pu, Iu);
		for(int j = 0; j < sz; j++) P[j] = C[sz-1-j];
		vector<cat> X(V.size());
		for(int j = 0; j < (int)V.size(); j++) X[j] = (mod - V[j]) % mod;
		vector<cat> val = poly_eval_dedup(P, X, mod);
		for(int j = 0; j < (int)V.size(); j++) {
			cat val_cur = val[j];
			if(par[G[i][j]] == i) cntK_up[G[i][j]] = val_cur * fac % mod;
			else cntK_down[i] = val_cur * fac % mod;
		}
	}

	vector<cat> sum_val(N);
	DFS2(0, G, par, cntK_down, sum_val, mod);
	cat ans = 0;
	for(int i = 0; i < N; i++) {
		cat sum = 0;
		ALL_THE(G[i], it) if(par[*it] == i) {
			ans += sum_val[*it] * (sum+cntK_up[*it]) % mod;
			sum = (sum + sum_val[*it]) % mod;
		}
	}

	ans %= mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing