#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<iostream>
#include<algorithm>

using namespace std;

// SA

template<class T> void induce(const T *S, int N, int *SA, bool *is_s, int *base, int K){
	// get Ltype
	int it[K + 1];
	copy_n(base, K, it);
	for(int i = 0; i <= N; ++i){
		if(SA[i] >= 1 && (!is_s[SA[i] - 1])){
			SA[it[S[SA[i] - 1]]++] = SA[i] - 1;
		}
	}
	// get Stype
	copy_n(base + 1, K, it);
	for(int i = N; i > 0; --i){
		if(SA[i] >= 1 && is_s[SA[i] - 1]){
			SA[--it[S[SA[i] - 1]]] = SA[i] - 1;
		}
	}
}

template<class T> void getSA(const T *S, const int N, int *SA, int K){
	// S[SA[0]..] < S[SA[1]..] < ...
	// SA[0] = N
	// 0 <= S[i] < K
	// NOTE THAT size(SA) = N + 1

	bool is_s[N + 1]; // is Stype
	int lmss[N + 1];
	int lms_cnt = 0;
	int lms_id[N + 1]; // [i] = if i is lms then id else -1
	int cnt[K + 1] = {};
	int base[K + 1];
	fill_n(lms_id, N + 1, -1);
	fill_n(lmss, N + 1, -1);
	fill_n(is_s, N + 1, false);
	fill_n(SA, N + 1, -1);
	
	// calculate types
	is_s[N] = true;
	is_s[N - 1] = false;
	for(int i = N - 2; i >= 0; --i){
		if(S[i] > S[i + 1]){
			is_s[i] = false;
		}else if(S[i] == S[i + 1]){
			is_s[i] = is_s[i + 1];
		}else{
			is_s[i] = true;
		}
	}
	
	// enumerate LMS
	for(int i = 1; i <= N; ++i){
		if(is_s[i] & (!is_s[i - 1])){
			lms_id[i] = lms_cnt;
			lmss[lms_cnt++] = i;
		}
	}
	
	// get bucket size
	for(int i = 0; i < N; ++i){
		cnt[S[i]]++;
	}
	
	// get base
	base[0] = 1;
	for(int i = 1; i <= K; ++i){
		base[i] = base[i - 1] + cnt[i - 1];
	}
	
	if(lms_cnt > 1){
		// sort LMS prefixes
		SA[0] = N;
		int it[K];
		copy_n(base + 1, K, it);
		for(int i = N - 1; i >= 0; --i){
			if(lms_id[i] >= 0){
				SA[--it[S[i]]] = i;
			}
		}
		induce(S, N, SA, is_s, base, K);
		
		// create new string
		int lms_perm[N + 1];
		int c = 0;
		for(int i = 0; i <= N; ++i){
			if(lms_id[SA[i]] >= 0){
				lms_perm[c++] = SA[i];
			}
		}
		int nxtS[lms_cnt - 1];
		int nxtSA[lms_cnt];
		int val = 0;
		
		// lms_perm[0] : sentinel
		nxtS[lms_id[lms_perm[1]]] = val;
		for(int i = 2; i < lms_cnt; ++i){
			// compare S[lms_perm[i - 1]..] and S[lms_perm[i]..]
			int id1 = lms_perm[i - 1], id2 = lms_perm[i];
			while(true){
				if(id1 == N || id2 == N){
					val++;
					break;
				}
				if(S[id1] != S[id2]){
					val++;
					break;
				}
				id1++;
				id2++;
				if(lms_id[id1] >= 0 || lms_id[id2] >= 0){
					if(lms_id[id1] < 0 || lms_id[id2] < 0){
						val++;
					}
					break;
				}
			}
			nxtS[lms_id[lms_perm[i]]] = val;
		}
		
		// get LMS SA
		getSA(nxtS, lms_cnt - 1, nxtSA, val + 1);
		
		// restore LMS positions
		fill_n(SA, N + 1, -1);
		copy_n(base + 1, K, it);
		SA[0] = N;
		for(int i = lms_cnt - 1; i >= 1; --i){
			int id = lmss[nxtSA[i]];
			SA[--it[S[id]]] = id;
		}
	}else{
		fill_n(SA, N + 1, -1);
		SA[0] = N;
	}
	
	induce(S, N, SA, is_s, base, K);
}

template<class T> void getLCP(const T *S, const int N, const int *SA, int *LCP){
	// LCP[i] = lcp(S[SA[i]..], S[SA[i + 1]..])
	// size(SA) = N + 1
	// size(LCP) = N
	
	int iSA[N + 1];
	for(int i = 0; i <= N; ++i){
		iSA[SA[i]] = i;
	}
	
	int h = 0;
	for(int i = 0; i < N; ++i){
		int j = SA[iSA[i] - 1];
		if(h > 0) h--;
		while(i + h < N && j + h < N){
			if(S[i + h] != S[j + h]) break;
			h++;
		}
		LCP[iSA[i] - 1] = h;
	}
}

vector<int> ids[1000100];
set<int> se;

int hs[500500];

int get(vector<int> &vec, int ub){
	return (lower_bound(vec.begin(), vec.end(), ub) - vec.begin());
}

int get(vector<int> &vec, int lb, int ub){
	if(lb >= ub) return 0;
	return get(vec, ub) - get(vec, lb);
}

long long solve(char *ch, int N){
	int sa[500500];
	int lcp[500500];
	int isa[500500];

	getSA(ch, N, sa, 256);
	getLCP(ch, N, sa, lcp);
	
	for(int i = 0; i <= N; ++i){
		isa[sa[i]] = i;
	}
	
	hs[0] = 0;
	for(int i = 0; i < N; ++i){
		int x = ch[i] == '(' ? 1 : -1;
		hs[i + 1] = hs[i] + x;
	}
	for(int i = 0; i <= N; ++i){
		ids[hs[i] + N].push_back(i);
	}
	se.insert(N + 1);
	long long ans = 0;
	for(int h = 0; h <= N * 2; ++h){
		for(int i = 0; i < ids[h].size(); ++i){
			int id = ids[h][i];
			int x = isa[id];
			int lb = id + lcp[x - 1] + 1;
			int ub = *se.lower_bound(id);
			se.insert(id);
			// [lb, ub)
			int cur = get(ids[h], lb, ub);
			ans += cur;
		}
	}
	return ans;
}

char ch[500500];
int N;

void input(){
	scanf("%d", &N);
	scanf("%s", ch);
}

int main(){
	input();
	long long ans = solve(ch, N);
	cout << ans << "\n";
	return 0;
}