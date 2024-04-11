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
#define soclose 1e-7
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
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

vector<ll> DFT(vector<ll> &A, int N, int d, int x, int dir) {
	vector<ll> ret(N,0);

	if(N == 1) {
		ret[0] =A[x];
		return ret;}
	if(N == 2) {
		ret[0] =(A[x]+A[x+d])%MOD;
		ret[1] =(A[x]+MOD-A[x+d])%MOD;
		return ret;}

	int dep =0, n =N;
	while(n > 1) {n /=2; dep++;}

	vector<ll> DFT0[2];
	DFT0[0] =DFT(A,N/2,d*2,x,dir);
	DFT0[1] =DFT(A,N/2,d*2,x+d,dir);
	for(int i =0; i < N/2; i++) {
		ll com =OM[dep][(N+1LL*dir*i)%N];
		ret[i] =(DFT0[0][i]+com*DFT0[1][i])%MOD;
		ret[i+N/2] =(DFT0[0][i]+(MOD-com)*DFT0[1][i])%MOD;}
	return ret;}

int SN =1<<20; // arbitrary power of 2 such that N <= SN

vector<ll> convolution(vector<ll> A, vector<ll> B) {
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

void DFS(int R, vector<int> & par, vector< vector<int> > & G, vector<int> & dep, vector<int> & S, vector< vector<int> > & path, vector<int> & id_path) {
	S[R] = 1;
	int id_son = -1, sz_son = -1;
	ALL_THE(G[R], it) if(par[*it] == -1) {
		par[*it] = R;
		dep[*it] = dep[R] + 1;
		DFS(*it, par, G, dep, S, path, id_path);
		S[R] += S[*it];
		if(S[*it] > sz_son) {
			sz_son = S[*it];
			id_son = id_path[*it];
		}
	}
	if(id_son == -1) {
		id_path[R] = path.size();
		path.push_back(vector<int>());
	}
	else id_path[R] = id_son;
	path[id_path[R]].push_back(R);
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = (x * x) % mod;
	if(e&1) x = (x * a) % mod;
	return x;
}

pair< vector<cat>, vector<cat> > solve_path(vector< vector<cat> > & V, cat mod) {
	int sz = V.size();
	if(sz == 0) return {vector<cat>(1, 1), vector<cat>(1, 1)};
	if(sz == 1) {
		vector<cat> ret = V[0];
		// ret[0] = 1;
		return {ret, V[0]};
	}
	int sum = 0; // final. degree
	for(int i = 0; i < sz; i++) sum += (int)V[i].size()-1;
	int cur = 0, cur_sum = 0;
	while(cur < sz && 2*(cur_sum+(int)V[cur].size()-1) <= sum) {
		cur_sum += (int)V[cur].size()-1;
		cur++;
	}
	if(cur < sz && abs(2*(cur_sum+(int)V[cur].size()-1)-sum) <= abs(2*cur_sum-sum)) {
		cur_sum += (int)V[cur].size()-1;
		cur++;
	}
	vector< vector<cat> > Vl(cur), Vr(sz-cur);
	for(int i = 0; i < cur; i++) Vl[i] = V[i];
	for(int i = cur; i < sz; i++) Vr[i-cur] = V[i];		
	pair< vector<cat>, vector<cat> > pret = solve_path(Vl, mod);
	pair< vector<cat>, vector<cat> > p2 = solve_path(Vr, mod);
	vector<cat> ret = pret.ff;
	int csz = max(p2.ff.size(), pret.ss.size());
	vector<ll> c1(csz, 0), c2(csz, 0), c3(csz, 0);
	for(int i = 0; i < (int)p2.ff.size(); i++) c1[i] = p2.ff[i];
	for(int i = 0; i < (int)pret.ss.size(); i++) c2[i] = pret.ss[i];
	for(int i = 0; i < (int)p2.ss.size(); i++) c3[i] = p2.ss[i];
	vector<ll> r1 = convolution(c1, c2);
	ret.resize(max(ret.size(), r1.size()), 0);
	for(int i = 0; i < (int)r1.size(); i++) ret[i] += r1[i];
	vector<ll> r2 = convolution(c2, c3);
	vector<cat> prod(r2.size());
	for(int i = 0; i < (int)r2.size(); i++) prod[i] = r2[i];
	while(prod.size() > 1 && prod.back() == 0) prod.pop_back();
	while(ret.size() > 1 && ret.back() == 0) ret.pop_back();
	prod.resize(max(prod.size(), ret.size()), 0);
	ret.resize(max(prod.size(), ret.size()), 0);
	return {ret, prod};
}

vector< vector<cat> > V_by_sz[20];

vector<cat> solve_multiconv(vector< vector<cat> > & V) {
	int mxe = 0;
	for(int i = 0; i < (int)V.size(); i++) {
		int sz = V[i].size();
		int e = 0;
		while((1<<e) <= sz) e++;
		mxe = max(mxe, e);
		V_by_sz[e].push_back(V[i]);
	}
	vector<cat> ret = vector<cat>(1, 1);
	for(int i = 0; i <= mxe; i++) {
		int a = 0;
		while(a+1 < (int)V_by_sz[i].size()) {
			vector<ll> v1(2<<i, 0), v2(2<<i, 0);
			for(int j = 0; j < (int)V_by_sz[i][a].size(); j++) v1[j] = V_by_sz[i][a][j];
			for(int j = 0; j < (int)V_by_sz[i][a+1].size(); j++) v2[j] = V_by_sz[i][a+1][j];
			vector<ll> vr = convolution(v1, v2);
			vector<cat> wr(vr.size());
			for(int j = 0; j < (int)vr.size(); j++) wr[j] = vr[j];
			while(wr.size() > 1 && wr.back() == 0) wr.pop_back();
			int e_nw = i;
			while((1<<e_nw) <= (int)wr.size()) e_nw++;
			V_by_sz[e_nw].push_back(wr);
			mxe = max(mxe, e_nw);
			a += 2;
		}
		if(a < (int)V_by_sz[i].size()) {
			if(i == mxe) ret = V_by_sz[i][a];
			else V_by_sz[i+1].push_back(V_by_sz[i][a]);
		}
	}
	for(int i = 0; i <= mxe; i++) V_by_sz[i].clear();
	return ret;
}

vector<cat> DFS_paths(int R, vector< vector< pair<int, int> > > & G, vector<int> & path_len, cat mod) {
	vector< vector< vector<cat> > > V_all(path_len[R]);
	ALL_THE(G[R], it) {
		V_all[it->ss].push_back(DFS_paths(it->ff, G, path_len, mod));
		V_all[it->ss].back()[0] = 1;
	}
	vector< vector<cat> > V_conv(path_len[R]);
	for(int i = 0; i < path_len[R]; i++) V_conv[i] = solve_multiconv(V_all[i]);
	for(int i = 0; i < path_len[R]; i++) V_conv[i].insert(begin(V_conv[i]), 0);
	return solve_path(V_conv, mod).ff;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat X, mod = 998244353;
	cin >> N >> X;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> S(N), id_path(N), par(N, -1), dep(N, 0);
	vector< vector<int> > path;
	par[0] = 0;
	DFS(0, par, G, dep, S, path, id_path);
	int P = path.size();
	vector< vector< pair<int, int> > > Gp(P);
	for(int i = 0; i < P; i++) {
		int v = path[i].back();
		if(v == 0) continue;
		v = par[v];
		Gp[id_path[v]].push_back({i, dep[v]-dep[path[id_path[v]].back()]});
	}
	vector<int> path_len(P);
	for(int i = 0; i < P; i++) path_len[i] = path[i].size();
	vector<cat> cnt = DFS_paths(id_path[0], Gp, path_len, mod);
	cat ans = 0;
	X %= mod;
	vector<cat> inv(N, 1);
	for(int i = 1; i < N; i++) inv[i] = inv[i-1] * pw(i, mod-2, mod) % mod;
	for(int i = N; i >= 1; i--)
		ans = (ans * (X+i) + cnt[i] * inv[i-1]) % mod;
	if(ans < 0) ans += mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing