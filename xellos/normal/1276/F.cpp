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

void DFS(int R, auto & son, auto & sz, auto & path, auto & paths, int & n_paths) {
	sz[R] = 1;
	int best_son = -1;
	for(auto v : son[R]) {
		DFS(v, son, sz, path, paths, n_paths);
		if(best_son == -1 || sz[v] > sz[best_son])
			best_son = v;
		sz[R] += sz[v];
	}
	if(best_son == -1) {
		path[R] = n_paths++;
		paths.push_back({R});
	}
	else {
		path[R] = path[best_son];
		paths[path[R]].push_back(R);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	cin >> S;
	vector<int> par[2], L_range[2], id_v[2];
	{
		string W = S;
		int N =W.length();
		vector< vector<int> > V1(256);
		V1[0].push_back(N);
		for(int i =0; i < N; i++) V1[W[i]].push_back(i);
		int K =5;
		while(1<<(K-1) < N) K++;
		vector<int> isB(N+1+(1<<(K-1)),0);
		vector<int> SA(N+1,N); // order of suffixes
		vector<int> Bs(N+2,N+1); // bucket start
		Bs[0] =0;
		int Btot =-1; // buckets total
		for(int j =0, q = 0; j < 256; j++) {
			if(!V1[j].empty()) Bs[++Btot] =q;
			for(uint i =0; i < V1[j].size(); i++) {
				SA[q] =V1[j][i];
				isB[V1[j][i]] =Btot;
				q++;}
			}
		vector< pair<int,int> > tmp(N+1);
		vector<int> Bs1(N+1,0); // bucket size (tmp)
		vector<int> nxtB(N+1,0), pos(N+1,0);
		for(int i =1; i < K; i++) {
			int q =1<<(i-1);
			for(int j =0; j <= Btot; j++) Bs1[j] =0;
			for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 
				Bs1[nxtB[k]]++;
			// transform Bs1 to bucket start (tmp)
			int s =0;
			for(int j =0; j <= Btot; j++) {
				int s2 =Bs1[j]+s;
				Bs1[j] =s;
				s =s2;}
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++)
				pos[k] =Bs1[nxtB[k]]++;
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) {
				tmp[pos[k]].ff =SA[k];
				tmp[pos[k]].ss =j;}
			for(int j =0; j < s; j++) pos[j] =Bs[tmp[j].ss]++;
			for(int j =0; j < s; j++) SA[pos[j]] =tmp[j].ff;
			for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];
			// split buckets
			Btot =0;
			Bs[0] =0;
			for(int j =1; j <= N; j++) {
				if(isB[SA[j]] != isB[SA[j-1]] || nxtB[j] != nxtB[j-1]) pos[j] =++Btot;
				else pos[j] =pos[j-1];
			}
			int p =0;
			for(int j =1; j <= N; j++) {
				if(p+1 == pos[j]) Bs[++p] =j;
				isB[SA[j]] =p;}
			}
		vector<int> LCP(N+1,0);
		int L =0;
		for(int i =0; i < N; i++) {
			int k =SA[isB[i]-1];
			while(i+L < N && k+L < N && W[i+L] == W[k+L]) L++;
			LCP[isB[i]] =L;
			if(L > 0) L--;}

		vector< vector<int> > LCP_ids(N+1);
		for(int i = 1; i <= N; i++) LCP_ids[LCP[i]].push_back(i);
		map< pair<int, int>, int> I;
		id_v[0].resize(N+1);
		vector<int> id_SA(N+1);
		for(int i = 0; i <= N; i++) id_SA[SA[i]] = i;
		int V = 0;
		for(int l = N; l >= 0; l--) {
			id_v[0][l] = V;
			I[{id_SA[N-l], id_SA[N-l]+1}] = V++;
			par[0].push_back(-1);
			L_range[0].push_back(l);
			for(auto x : LCP_ids[l]) {
				auto it = I.lower_bound({x, -1});
				auto jt = it; jt--;
				par[0][jt->ss] = par[0][it->ss] = V;
				I[{jt->ff.ff, it->ff.ss}] = V++;
				L_range[0][jt->ss] -= l;
				L_range[0][it->ss] -= l;
				I.erase(it);
				I.erase(jt);
				par[0].push_back(-1);
				L_range[0].push_back(l);
			}
		}
		if(I.size() != 1) return 1;
	}
	{
		string W = S;
		reverse(begin(W), end(W));
		int N =W.length();
		vector< vector<int> > V1(256);
		V1[0].push_back(N);
		for(int i =0; i < N; i++) V1[W[i]].push_back(i);
		int K =5;
		while(1<<(K-1) < N) K++;
		vector<int> isB(N+1+(1<<(K-1)),0);
		vector<int> SA(N+1,N); // order of suffixes
		vector<int> Bs(N+2,N+1); // bucket start
		Bs[0] =0;
		int Btot =-1; // buckets total
		for(int j =0, q = 0; j < 256; j++) {
			if(!V1[j].empty()) Bs[++Btot] =q;
			for(uint i =0; i < V1[j].size(); i++) {
				SA[q] =V1[j][i];
				isB[V1[j][i]] =Btot;
				q++;}
			}
		vector< pair<int,int> > tmp(N+1);
		vector<int> Bs1(N+1,0); // bucket size (tmp)
		vector<int> nxtB(N+1,0), pos(N+1,0);
		for(int i =1; i < K; i++) {
			int q =1<<(i-1);
			for(int j =0; j <= Btot; j++) Bs1[j] =0;
			for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 
				Bs1[nxtB[k]]++;
			// transform Bs1 to bucket start (tmp)
			int s =0;
			for(int j =0; j <= Btot; j++) {
				int s2 =Bs1[j]+s;
				Bs1[j] =s;
				s =s2;}
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++)
				pos[k] =Bs1[nxtB[k]]++;
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) {
				tmp[pos[k]].ff =SA[k];
				tmp[pos[k]].ss =j;}
			for(int j =0; j < s; j++) pos[j] =Bs[tmp[j].ss]++;
			for(int j =0; j < s; j++) SA[pos[j]] =tmp[j].ff;
			for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];
			// split buckets
			Btot =0;
			Bs[0] =0;
			for(int j =1; j <= N; j++) {
				if(isB[SA[j]] != isB[SA[j-1]] || nxtB[j] != nxtB[j-1]) pos[j] =++Btot;
				else pos[j] =pos[j-1];
			}
			int p =0;
			for(int j =1; j <= N; j++) {
				if(p+1 == pos[j]) Bs[++p] =j;
				isB[SA[j]] =p;}
			}
		vector<int> LCP(N+1,0);
		int L =0;
		for(int i =0; i < N; i++) {
			int k =SA[isB[i]-1];
			while(i+L < N && k+L < N && W[i+L] == W[k+L]) L++;
			LCP[isB[i]] =L;
			if(L > 0) L--;}

		vector< vector<int> > LCP_ids(N+1);
		for(int i = 1; i <= N; i++) LCP_ids[LCP[i]].push_back(i);
		map< pair<int, int>, int> I;
		id_v[1].resize(N+1);
		vector<int> id_SA(N+1);
		for(int i = 0; i <= N; i++) id_SA[SA[i]] = i;
		int V = 0;
		for(int l = N; l >= 0; l--) {
			id_v[1][l] = V;
			I[{id_SA[N-l], id_SA[N-l]+1}] = V++;
			par[1].push_back(-1);
			L_range[1].push_back(l);
			for(auto x : LCP_ids[l]) {
				auto it = I.lower_bound({x, -1});
				auto jt = it; jt--;
				par[1][jt->ss] = par[1][it->ss] = V;
				I[{jt->ff.ff, it->ff.ss}] = V++;
				L_range[1][jt->ss] -= l;
				L_range[1][it->ss] -= l;
				I.erase(it);
				I.erase(jt);
				par[1].push_back(-1);
				L_range[1].push_back(l);
			}
		}
		if(I.size() != 1) return 1;
	}

	vector< vector<int> > son[2];
	int N[2], R[2], P[2];
	vector<int> sz[2], path[2], path_idx[2], path_top[2];
	vector< vector<int> > path_sums[2];
	cat ans = 1;
	for(int k = 0; k < 2; k++) {
		N[k] = par[k].size();
		son[k].resize(N[k]);
		for(int i = 0; i < N[k]; i++) {
			if(k) ans += L_range[k][i];
			if(par[k][i] == -1) R[k] = i;
			else son[k][par[k][i]].push_back(i);
		}
		sz[k].resize(N[k]);
		path[k].resize(N[k]);
		vector< vector<int> > paths;
		P[k] = 0;
		DFS(R[k], son[k], sz[k], path[k], paths, P[k]);
		path_idx[k].resize(N[k]);
		path_top[k].resize(N[k]);
		path_sums[k].resize(P[k]);
		L_range[k][R[k]]++;
		for(int i = 0; i < P[k]; i++) {
			reverse(begin(paths[i]), end(paths[i]));
			path_sums[k][i].resize(paths[i].size()+1, 0);
			for(int j = 0; j < (int)paths[i].size(); j++) {
				path_sums[k][i][j+1] = path_sums[k][i][j] + L_range[k][paths[i][j]];
				path_idx[k][paths[i][j]] = j;
			}
			path_top[k][i] = paths[i][0];
		}
	}

	vector< vector<cat> > pairs(P[0]);
	set< pair<int,int> > Mm;
	for(int i = 0; i < (int)S.length(); i++) {
		int v[2] = {id_v[0][S.length()-1-i], id_v[1][i]};
		vector< pair<int, int> > V[2];
		for(int k = 0; k < 2; k++) {
			while(true) {
				int p = path[k][v[k]];
				V[k].push_back({p, path_idx[k][v[k]]});
				v[k] = path_top[k][p];
				if(par[k][v[k]] == -1) break;
				v[k] = par[k][v[k]];
			}
		}
		for(auto [a, b] : V[0]) for(auto [c, d] : V[1])
			pairs[a].push_back(((1LL*c)<<40)+((1LL*b)<<20)+d);
	}
	for(int i = 0; i < P[0]; i++) {
		sort(begin(pairs[i]), end(pairs[i]));
		for(int j = 0; j < (int)pairs[i].size(); j++) {
			if(j > 0 && (pairs[i][j]>>40) == (pairs[i][j-1]>>40)) continue;
			int p = pairs[i][j]>>40;
			vector< pair<int, int> > best;
			for(int k = j; k < (int)pairs[i].size(); k++) {
				if((pairs[i][k]>>40) != p) break;
				int x = (pairs[i][k]>>20)&((1<<20)-1), y = pairs[i][k]&((1<<20)-1);
				while(!best.empty() && best.back().ss <= y) best.pop_back();
				best.push_back({x, y});
			}
			int x_prev = 0;
			for(auto [x, y] : best) {
				ans += 1LL * (path_sums[0][i][x+1]-path_sums[0][i][x_prev]) * path_sums[1][p][y+1];
				x_prev = x+1;
			}
		}
	}

	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing