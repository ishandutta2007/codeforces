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
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

struct fin {
	vector<int> T;
	fin() {}
	fin(int N) {T.resize(N+10, 0);}

	int lastone(int x) {return x&(x^(x-1));}

	void put(int pos, int val) {
		for(int i = pos+1; i < (int)T.size(); i += lastone(i))
			T[i] += val;
	}

	int get(int pos) {
		int ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += T[i];
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, MX = 100000;
	cin >> N;
	vector< pair<int, int> > A[2];
	for(int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		A[(x+y+100000000)%2].push_back(make_pair(x, y));
	}
	cat ans = 0;

	for(int k = 0; k < 2; k++) {
		if(A[k].empty()) continue; 
		vector<int> dist[4];
		for(int i = 0; i < 4; i++) dist[i].resize(2*MX+1, 0);
		vector< pair<int, int> > Ps[4];
		vector<int> P[4][2];
		for(int i = 0; i < (int)A[k].size(); i++) {
			Ps[0].push_back(make_pair(A[k][i].ff, i));
			Ps[2].push_back(make_pair(A[k][i].ff, i));
			Ps[1].push_back(make_pair(A[k][i].ss, i));
			Ps[3].push_back(make_pair(A[k][i].ss, i));
			P[0][0].push_back(abs(-MX-A[k][i].ss)-A[k][i].ff);
			P[0][1].push_back(abs(-MX-A[k][i].ss)+A[k][i].ff);
			P[2][0].push_back(abs(MX-A[k][i].ss)-A[k][i].ff);
			P[2][1].push_back(abs(MX-A[k][i].ss)+A[k][i].ff);
			P[1][0].push_back(abs(-MX-A[k][i].ff)-A[k][i].ss);
			P[1][1].push_back(abs(-MX-A[k][i].ff)+A[k][i].ss);
			P[3][0].push_back(abs(MX-A[k][i].ff)-A[k][i].ss);
			P[3][1].push_back(abs(MX-A[k][i].ff)+A[k][i].ss);
		}

		for(int j = 0; j < 4; j++) {
			int K = Ps[j].size();
			sort(begin(Ps[j]), end(Ps[j]));
			multiset<int> s[2];
			for(int i = 0; i < K; i++) s[1].insert(P[j][1][Ps[j][i].ss]);
			int a = 0;
			for(int i = -MX; i <= MX; i++) {
				while(a < K && Ps[j][a].ff < i) {
					s[0].insert(P[j][0][Ps[j][a].ss]);
					s[1].erase(s[1].find(P[j][1][Ps[j][a].ss]));
					a++;
				}
				dist[j][i+MX] = OVER9000;
				if(!s[0].empty()) dist[j][i+MX] = min(dist[j][i+MX], i+*begin(s[0]));
				if(!s[1].empty()) dist[j][i+MX] = min(dist[j][i+MX], -i+*begin(s[1]));
			}
		}

		vector< pair<int, int> > Ix(2*MX+1), Iy(2*MX+1);
		for(int i = -MX; i <= MX; i++) {
			Ix[i+MX] = make_pair(-MX+dist[1][i+MX]+1, MX-dist[3][i+MX]-1);
			Iy[i+MX] = make_pair(-MX+dist[0][i+MX]+1, MX-dist[2][i+MX]-1);
			if((Ix[i+MX].ff+i-k)%2 == 0) Ix[i+MX].ff++;
			if((Ix[i+MX].ss+i-k)%2 == 0) Ix[i+MX].ss--;
			if((Iy[i+MX].ff+i-k)%2 == 0) Iy[i+MX].ff++;
			if((Iy[i+MX].ss+i-k)%2 == 0) Iy[i+MX].ss--;
		}
		vector< pair<int, int> > Iy_st, Iy_end;
		for(int i = 0; i < 2*MX+1; i++) if(Iy[i].ff <= Iy[i].ss) {
			Iy_st.push_back(make_pair(Iy[i].ff, i-MX));
			Iy_end.push_back(make_pair(Iy[i].ss+1, i-MX));
		}
		sort(begin(Iy_st), end(Iy_st));
		sort(begin(Iy_end), end(Iy_end));

		fin F[2] = {fin(2*MX+1), fin(2*MX+1)};

		int a_st = 0, a_end = 0, K = (int)Iy_st.size();
		for(int i = -MX; i <= MX; i++) if(Ix[i+MX].ff <= Ix[i+MX].ss) {
			while(a_st < K && Iy_st[a_st].ff <= i) {
				F[(Iy_st[a_st].ss+MX)%2].put(Iy_st[a_st].ss+MX, 1);
				a_st++;
			}
			while(a_end < K && Iy_end[a_end].ff <= i) {
				F[(Iy_end[a_end].ss+MX)%2].put(Iy_end[a_end].ss+MX, -1);
				a_end++;
			}
			ans += max(0, F[(i+MX+1-k)%2].get(Ix[i+MX].ss+MX)-F[(i+MX+1-k)%2].get(Ix[i+MX].ff+MX-1));
		}
	}

	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing