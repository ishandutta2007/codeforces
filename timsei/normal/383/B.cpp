#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;

struct NODE {
	int x , y;
	void input(void) {
		cin >> x >> y;
	}
}E[N];

map < int , int> Map , C;

int n , m , tot , id[N];

vector <int> G[N];

set < pair <int , int> > S;
set <int> B;

main(void) {
	cin >> n >> m;
	++ Map[1]; ++ Map[n];
	for(int i = 1;i <= m;++ i) {
		E[i].input();
		++ Map[E[i].x];
		if(E[i].x + 1 <= n) ++ Map[E[i].x + 1];
	}
	for(map <int , int> ::iterator it = Map.begin();it != Map.end();++ it) {
		C[it -> first] = ++ tot;
		id[tot] = it -> first;
	}
	for(int i = 1;i <= m;++ i) {
		G[C[E[i].x]].push_back(E[i].y);
	}
	for(int i = 1;i <= tot;++ i) {
		G[i].push_back(0) , G[i].push_back(n + 1);
		sort(G[i].begin() , G[i].end());
	}
	S.insert(make_pair(1 , 1));
	for(int i = 1;i <= tot;++ i) {
		if(!S.size()) {
			puts("-1"); return 0;
		}
		B.clear();
		int j = 0 , L , R;
		for(set < pair <int , int> > ::iterator it = S.begin(); it != S.end();++ it) {
			L = it -> first , R = it -> second;
			while(j < G[i].size() && G[i][j] <= R) {
				if(G[i][j] < L) {
					++ j;
					continue;
				}
				else {
					B.insert(L);
					L = G[i][j] + 1;
					++ j;
				}
			}
			if(L <= R) B.insert(L);
		}
		S.clear();
		for(int j = 0;j < (int) G[i].size();++ j) {
			B.erase(G[i][j]);
		}
		if(!B.size()) {
			puts("-1");
			return 0;
		}
		for(int j = 1;j < (int) G[i].size();++ j) {
			if(upper_bound(B.begin() , B.end(), G[i][j - 1]) == B.end()) continue;
			int now = *(upper_bound(B.begin() , B.end() , G[i][j - 1]));
			if(now < G[i][j]) {
				S.insert(make_pair(now , G[i][j] - 1));
			}
		}
	}
	for(set < pair <int , int> > ::iterator it = S.begin(); it != S.end();++ it) {
		int L = it -> first , R = it -> second;
		if(R == n) {
			cout << n * 2 - 2;
			return 0;
		}
	}
	puts("-1");
}