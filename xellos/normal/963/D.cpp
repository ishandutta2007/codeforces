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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct trie {
	vector< vector<int> > sons;
	vector<int> val;
	vector< pair<int, int> > son;
	trie() {
		sons.dibs(1000000);
		son.dibs(1000000);
		val.dibs(1000000);
		sons.resize(1);
		son.resize(1, make_pair(-1, -1));
		val.resize(1, -1);
	}

	void put(string &s, int id) {
		int akt = 0;
		for(int i = 0; i < (int)s.length(); i++) {
			if(sons[akt].empty() && son[akt].ff == -1) {
				son[akt] = make_pair(s[i]-'a', son.size());
				sons.push_back(vector<int>());
				son.push_back(make_pair(-1, -1));
				val.push_back(-1);
			}
			else if(sons[akt].empty() && son[akt].ff != s[i]-'a') {
				sons[akt].resize(26, -1);
				sons[akt][son[akt].ff] = son[akt].ss;
				sons[akt][s[i]-'a'] = sons.size();
				sons.push_back(vector<int>());
				son.push_back(make_pair(-1, -1));
				val.push_back(-1);
			}
			else if(!sons[akt].empty() && sons[akt][s[i]-'a'] == -1) {
				sons[akt][s[i]-'a'] = sons.size();
				sons.push_back(vector<int>());
				son.push_back(make_pair(-1, -1));
				val.push_back(-1);
			}
			if(sons[akt].empty()) akt = son[akt].ss;
			else akt = sons[akt][s[i]-'a'];
		}
		val[akt] = id;
	}

	int move(int akt, int chr) {
		if(sons[akt].empty()) return (son[akt].ff == chr) ? son[akt].ss : -1;
		return sons[akt][chr];
	}

	int get(int akt) {
		return val[akt];
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	cin >> S;
	int N = S.length(), Q, X = 200;

	trie T;

	cin >> Q;
	vector<int> ans(Q, -2), occ(Q), len(Q);
	for(int q = 0; q < Q; q++) {
		string sm;
		cin >> occ[q] >> sm;
		int L = sm.length();
		if(L < X) {
			T.put(sm, q);
			len[q] = L;
			continue;
		}
		vector<int> prev(L+1, 0);
		for(int i = 2; i <= L; i++) {
			prev[i] = prev[i-1];
			while(prev[i] > 0 && sm[prev[i]] != sm[i-1]) prev[i] = prev[prev[i]];
			if(sm[prev[i]] == sm[i-1]) prev[i]++;
		}
		vector<int> pos_occ;
		int pref = 0;
		for(int i = 0; i < N; i++) {
			while(pref > 0 && sm[pref] != S[i]) pref = prev[pref];
			if(sm[pref] == S[i]) pref++;
			if(pref == L) {
				pref = prev[pref];
				pos_occ.push_back(i);
			}
		}
		ans[q] = N+1000;
		for(int i = occ[q]-1; i < (int)pos_occ.size(); i++)
			ans[q] = min(ans[q], pos_occ[i]-pos_occ[i-occ[q]+1]+L);
		if(ans[q] > N) ans[q] = -1;
	}

	vector< vector<int> > pos_occ(Q);
	for(int i = 0; i < N; i++) {
		int akt = 0;
		for(int j = 0; j < X; j++) {
			if(i+j == N) break;
			akt = T.move(akt, S[i+j]-'a');
			if(akt == -1) break;
			int x = T.get(akt);
			if(x != -1) pos_occ[x].push_back(i);
		}
	}
	for(int q = 0; q < Q; q++) if(ans[q] == -2) {
		ans[q] = N+1000;
		for(int i = occ[q]-1; i < (int)pos_occ[q].size(); i++)
			ans[q] = min(ans[q], pos_occ[q][i]-pos_occ[q][i-occ[q]+1]+len[q]);
		if(ans[q] > N) ans[q] = -1;
	}

	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
	return 0;}

// look at my code
// my code is amazing