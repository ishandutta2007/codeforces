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

void parse(string & S, auto & G, auto & SP, auto & v_id, int & l, int r, int cur = 0) {
	while(l != r) {
		if(S[l] == '(') {
			G[cur].push_back(G.size());
			G.push_back({});
			SP.push_back(0);
			l++;
			parse(S, G, SP, v_id, l, r, G.size()-1);
			continue;
		}
		if(S[l] == ')') {
			l++;
			return;
		}
		if(S[l] == '*') {
			G[cur].push_back(G.size());
			G.push_back({});
			SP.push_back(0);
			v_id.push_back(G.size()-1);
		}
		else if(S[l] == 'P' || S[l] == 'S')
			SP[cur] = S[l];
		l++;
		continue;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	string S;
	getline(cin, S);
	while(T--) {
		getline(cin, S);
		vector< vector<int> > G(1);
		vector<char> SP(1, 0);
		vector<int> v_id;
		int r = 0, l = 0;
		while(S[l] != ' ') r = r * 10 + S[l++]-'0';
		parse(S, G, SP, v_id, l, S.length());
		int N = G.size();
		vector<int> par(N, 0);
		for(int i = 0; i < N; i++) for(auto v : G[i]) par[v] = i;
		vector<cat> K(N, 1);
		cat max_K = sqrt(1e18/r);
		while(max_K*max_K*r > 1000000000000000000) max_K--;
		while((max_K+1)*(max_K+1)*r <= 1000000000000000000) max_K++;
		for(int i = N-1; i >= 0; i--) {
			if(G[i].empty()) continue;
			K[i] = K[G[i][0]];
			if(!SP[i]) continue;
			if(SP[i] == 'S')
				for(auto v : G[i]) K[i] = min(K[i], K[v]);
			if(SP[i] == 'P') {
				K[i] = 0;
				for(auto v : G[i]) K[i] += K[v];
				K[i] = min(K[i], max_K+1);
			}
		}
		if(K[0] >= max_K) {
			cout << "LOSS\n";
			continue;
		}
		vector<char> use(N, 0);
		use[0] = 1;
		for(int i = 0; i < N; i++) if(!G[i].empty() && use[i]) {
			if(!SP[i]) {
				use[G[i][0]] = 1;
				continue;
			}
			if(SP[i] == 'S') for(auto v : G[i]) if(K[i] == K[v]) {
				use[v] = 1;
				break;
			}
			if(SP[i] == 'P') for(auto v : G[i]) use[v] = 1;
		}
		cout << "REVOLTING";
		for(int i = 0; i < (int)v_id.size(); i++)
			cout << " " << (use[v_id[i]] ? K[0]*r : 0);
		cout << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing