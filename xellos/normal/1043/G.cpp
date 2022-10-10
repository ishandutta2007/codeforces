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

bool is_equal(int p1, int p2, int L, vector<uint64_t> & H0, auto & H,
				vector<uint64_t> & pw0, auto & pw, cat mod1, cat mod2) {
	uint64_t h01 = H0[p1+L] - H0[p1] * pw0[L];
	uint64_t h02 = H0[p2+L] - H0[p2] * pw0[L];
	if(h01 != h02) return false;
	cat h11 = H[p1+L].ff - H[p1].ff * pw[L].ff;
	cat h21 = H[p2+L].ff - H[p2].ff * pw[L].ff;
	if((h11-h21) % mod1 != 0) return false;
	cat h12 = H[p1+L].ss - H[p1].ss * pw[L].ss;
	cat h22 = H[p2+L].ss - H[p2].ss * pw[L].ss;
	return ((h12-h22) % mod2 == 0);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	string s;
	cin >> N >> s >> Q;
	vector< vector<int> > occ(N+1, vector<int>(26, 0));
	for(int i = 0; i < N; i++) for(int j = 0; j < 26; j++)
		occ[i+1][j] = occ[i][j] + (s[i] == 'a'+j);

	cat mod1 = 1000000007, mod2 = 1000000009, p = 999983;
	vector< pair<cat, cat> > H(N+1, {0, 0});
	vector<uint64_t> H0(N+1, 0);
	for(int i = 0; i < N; i++) {
		H0[i+1] = H0[i] * (uint64_t) p + s[i]-'a'+1;
		H[i+1].ff = (H[i].ff * p + s[i]-'a'+1) % mod1;
		H[i+1].ss = (H[i].ss * p + s[i]-'a'+1) % mod2;
	}
	vector< pair<cat, cat> > pw(N+1, {1, 1});
	for(int i = 1; i <= N; i++) {
		pw[i].ff = pw[i-1].ff * p % mod1;
		pw[i].ss = pw[i-1].ss * p % mod2;
	}
	vector<uint64_t> pw0(N+1, 1);
	for(int i = 1; i <= N; i++) pw0[i] = pw0[i-1] * (uint64_t) p;
	vector< vector< pair<cat, cat> > > sum_pw(N+1);
	vector< vector<uint64_t> > sum_pw0(N+1);
	for(int L = 1; L <= N; L++) {
		sum_pw[L].resize(N/L+1, {0, 0});
		sum_pw0[L].resize(N/L+1, 0);
		for(int i = 1; i <= N/L; i++) {
			sum_pw[L][i].ff = (sum_pw[L][i-1].ff * pw[L].ff + 1) % mod1;
			sum_pw[L][i].ss = (sum_pw[L][i-1].ss * pw[L].ss + 1) % mod2;
			sum_pw0[L][i] = sum_pw0[L][i-1] * pw0[L] + 1;
		}
	}

	vector<int> min_dup_l(N+1, 0), min_dup_r(N+1, 0);
	for(int dir = 0; dir < 2; dir++) {
		string W = s;
		if(dir == 1) reverse(begin(W), end(W));
		vector< vector<int> > V1(256);
		V1[0].push_back(N);
		for(int i =0; i < N; i++) V1[W[i]].push_back(i);
		int K =5;
		while(1<<(K-1) < N) K++;
		vector<int> isB(N+1+(1<<(K-1)),0);
		vector<int> SA(N+1,N); // order of suffixes
		vector<int> Bs(N+2,N+1); // bucket start
		Bs[0] =0;
		int Btot =-1, q =0; // buckets total
		for(int j =0; j < 256; j++) {
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
			for(int j =0; j <= Btot; j++) Bs1[j] =0; 									// t=1
			for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];							// t=12
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 
				Bs1[nxtB[k]]++;									// t=9
			// transform Bs1 to bucket start (tmp)
			int s =0;
			for(int j =0; j <= Btot; j++) {												// t=1
				int s2 =Bs1[j]+s;
				Bs1[j] =s;
				s =s2;}
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) 			// t=22
				pos[k] =Bs1[nxtB[k]]++;
			for(int j =0; j <= Btot; j++) if(Bs[j+1]-Bs[j] > 1) for(int k =Bs[j]; k < Bs[j+1]; k++) {			// t=14
				tmp[pos[k]].ff =SA[k];
				tmp[pos[k]].ss =j;}
			for(int j =0; j < s; j++) pos[j] =Bs[tmp[j].ss]++;							// t=14
			for(int j =0; j < s; j++) SA[pos[j]] =tmp[j].ff;							// t=7
			for(int j =0; j <= N; j++) nxtB[j] =isB[SA[j]+q];							// t=11
			// split buckets
			Btot =0;
			Bs[0] =0;
			for(int j =1; j <= N; j++) {
				if(isB[SA[j]] != isB[SA[j-1]] || nxtB[j] != nxtB[j-1]) pos[j] =++Btot;	// t=14
				else pos[j] =pos[j-1];
			}
	//		clock_t ta =clock();
			int p =0;
			for(int j =1; j <= N; j++) {												// t=19
				if(p+1 == pos[j]) Bs[++p] =j;
				isB[SA[j]] =p;}
	//		clock_t tb =clock();
	//		cout << i << " " << (int)(tb-ta) << endl;
			}

		vector<int> LCP(N+1,0);
		int L =0;
		for(int i =0; i < N; i++) {
			int k =SA[isB[i]-1];
			while(i+L < N && k+L < N && W[i+L] == W[k+L]) L++;
			LCP[isB[i]] =L;
			if(L > 0) L--;}

		vector< vector<int> > merges(N+1);
		for(int i = 0; i < N; i++) merges[LCP[i+1]].push_back(i);
		vector< set<int> > group(N+1);
		vector<int> in_group(N+1);
		for(int i = 0; i <= N; i++) {
			group[i].insert(i);
			in_group[i] = i;
		}
		vector< pair<cat, int> > merge_order;
		for(int i = N; i > 0; i--) ALL_THE(merges[i], it) {
			int g1 = in_group[SA[*it]], g2 = in_group[SA[(*it)+1]];
			if(group[g1].size() < group[g2].size()) swap(g1, g2);
			merge_order.push_back({g1*mod1+g2, i});
			ALL_THE(group[g2], jt) {
				group[g1].insert(*jt);
				in_group[*jt] = g1;
			}
		}

		vector< set<int> > group_uncomp = group;
		reverse(begin(merge_order), end(merge_order));
		ALL_THE(merge_order, it) {
			int g1 = it->ff/mod1, g2 = it->ff%mod1, i = it->ss;
			group_uncomp[g2].clear();
			ALL_THE(group[g2], jt) {
				auto kt = group_uncomp[g1].lower_bound((*jt)-i);
				while(kt != end(group_uncomp[g1])) {
					if(*kt >= *jt) break;
					auto lt = group[g1].upper_bound(*kt);
					if(dir == 0) min_dup_l[*kt] = (*lt)-(*kt);
					else min_dup_r[*kt] = (*lt)-(*kt);
					lt = kt;
					kt++;
					group_uncomp[g1].erase(*lt);
				}
				if(kt != end(group_uncomp[g1]) && *kt == *jt) {
					auto lt = group[g1].upper_bound(*jt);
					if(lt != end(group[g1]) && (*lt) <= (*jt)+i) {
						if(dir == 0) min_dup_l[*jt] = (*lt)-(*jt);
						else min_dup_r[*jt] = (*lt)-(*jt);
						group_uncomp[g1].erase(kt);
					}
				}
			}
			ALL_THE(group[g2], jt) {
				group[g1].erase(*jt);
				if(group_uncomp[g1].count(*jt)) {
					group_uncomp[g1].erase(*jt);
					group_uncomp[g2].insert(*jt);
				}
			}
		}
	}
	reverse(begin(min_dup_r), end(min_dup_r));

	vector<int> min_min_dup_l(N+1, N+1);
	for(int i = N-1; i >= 0; i--) {
		if(min_dup_l[i] != 0) min_min_dup_l[i] = 2*min_dup_l[i]+i;
		min_min_dup_l[i] = min(min_min_dup_l[i], min_min_dup_l[i+1]);
	}

	map< tuple<uint64_t, cat, cat>, set<int> > pos_THR;
	constexpr int L_THR = 400;
	for(int i = 0; i <= N-L_THR; i++) {
		cat h1 = (H[i+L_THR].ff - H[i].ff * pw[L_THR].ff) % mod1;
		if(h1 < 0) h1 += mod1;
		cat h2 = (H[i+L_THR].ss - H[i].ss * pw[L_THR].ss) % mod2;
		if(h2 < 0) h2 += mod2;
		cat h0 = H0[i+L_THR] - H0[i] * pw0[L_THR];
		pos_THR[{h0, h1, h2}].insert(i);
	}

	for(int q = 0; q < Q; q++) {
		int l, r;
		cin >> l >> r;
		l--;
		bool possible = false;
		for(int i = 0; i < 26; i++) if(occ[r][i]-occ[l][i] > 1) possible = true;
		if(!possible) {
			cout << "-1\n";
			continue;
		}
		if(occ[r][s[l]-'a']-occ[l][s[l]-'a'] + occ[r][s[r-1]-'a']-occ[l][s[r-1]-'a'] == 2) {
			// 3 or 4
			if(min_min_dup_l[l] <= r) cout << "3\n";
			else cout << "4\n";
		}
		else {
			bool ans1 = false;
			if(min_dup_l[l]*2 <= r-l && min_dup_l[l] != 0) for(int i = 1; ; i++) {
				if(i*i > r-l) break;
				if((r-l)%i != 0) continue;
				int L = i, rep = (r-l)/i;
				if(rep > 1 && L >= min_dup_l[l]) {
					uint64_t h0 = (H0[l+L] - H0[l] * pw0[L]) * sum_pw0[L][rep];
					if(h0 == H0[r] - H0[l] * pw0[r-l]) {
						cat h1 = (H[l+L].ff - H[l].ff * pw[L].ff) % mod1 * sum_pw[L][rep].ff % mod1;
						cat h2 = (H[l+L].ss - H[l].ss * pw[L].ss) % mod2 * sum_pw[L][rep].ss % mod2;
						if((H[r].ff-H[l].ff*pw[r-l].ff-h1)%mod1 == 0 && (H[r].ss-H[l].ss*pw[r-l].ss-h2)%mod2 == 0) {
							ans1 = true;
							break;
						}
					}
				}
				swap(L, rep);
				if(rep > 1 && L >= min_dup_l[l]) {
					uint64_t h0 = (H0[l+L] - H0[l] * pw0[L]) * sum_pw0[L][rep];
					if(h0 == H0[r] - H0[l] * pw0[r-l]) {
						cat h1 = (H[l+L].ff - H[l].ff * pw[L].ff) % mod1 * sum_pw[L][rep].ff % mod1;
						cat h2 = (H[l+L].ss - H[l].ss * pw[L].ss) % mod2 * sum_pw[L][rep].ss % mod2;
						if((H[r].ff-H[l].ff*pw[r-l].ff-h1)%mod1 == 0 && (H[r].ss-H[l].ss*pw[r-l].ss-h2)%mod2 == 0) {
							ans1 = true;
							break;
						}
					}
				}
			}
			if(ans1) {
				cout << "1\n";
				continue;
			}
			// 2 or 3
			if(min_dup_l[l] < r-l && min_dup_l[l] != 0) {
				cout << "2\n";
				continue;
			}
			if(min_dup_r[r] < r-l && min_dup_r[r] != 0) {
				cout << "2\n";
				continue;
			}
			bool ans2 = false;
			for(int i = 1; i <= min((r-l)/2, L_THR); i++)
				if(is_equal(l, r-i, i, H0, H, pw0, pw, mod1, mod2)) {
					ans2 = true;
					break;
				}
			if(!ans2 && r-l > 2*L_THR) {
				uint64_t h0 = H0[l+L_THR] - H0[l] * pw0[L_THR];
				cat h1 = (H[l+L_THR].ff - H[l].ff * pw[L_THR].ff) % mod1;
				if(h1 < 0) h1 += mod1;
				cat h2 = (H[l+L_THR].ss - H[l].ss * pw[L_THR].ss) % mod2;
				if(h2 < 0) h2 += mod2;
				set<int> & S = pos_THR[{h0, h1, h2}];
				auto it = S.upper_bound(l);
				while(it != end(S)) {
					if(*it+L_THR > r) break;
					if(r-(*it) > (*it)-l) {
						it++;
						continue;
					}
					if(is_equal(l, *it, r-(*it), H0, H, pw0, pw, mod1, mod2)) {
						ans2 = true;
						break;
					}
					it++;
				}
			}
			cout << (ans2 ? "2\n" : "3\n");
		}
	}
	return 0;
}

// look at my code
// my code is amazing