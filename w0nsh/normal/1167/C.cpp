#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m;
int repr[500005];
int size[500005];

int Find(int a){
	if(repr[a] == a) return a;
	return repr[a] = Find(repr[a]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a != b){
		repr[a] = b;
		size[b] += size[a];
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	FOR(i, n) repr[i] = i, size[i] = 1;
	FOR(i, m){
		int ile;
		std::cin >> ile;
		int last = -1;
		FOR(j, ile){
			int a;
			std::cin >> a;
			a--;
			if(last != -1) Union(last, a);
			last = a;
		}
	}
	FOR(i, n){
		std::cout << size[Find(i)] << " ";
	}
	return 0;
}