#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <random>
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

int n, all, rep[4], val[4], deg[4];
std::vector<PR<PII, int> > A;

int find(int a){
	return (a == rep[a] ? a : (rep[a] = find(rep[a])));
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n;
	FOR(i, 4) rep[i] = i;
	FOR(i, n){
		int a, b, c;
		std::cin >> a >> c >> b;
		a--;b--;
		all += c;
		A.push_back(MP(MP(a, b), c));
		deg[a]++;
		deg[b]++;
		if(find(a) != find(b)) val[find(b)] += val[find(a)],rep[find(a)] = find(b);
		val[find(a)] += c;
	}
	if(find(0)==find(1)&&find(2)==find(3)&&find(1)==find(2)){
		if(deg[0]%2+deg[1]%2+deg[2]%2+deg[3]%2 <= 2){
			std::cout << all << "\n";
			return 0;
		}else{
			all = 0;
			FOR(block, n){
				if(A[block].X.X == A[block].X.Y) continue;
				FOR(i, 4) rep[i] = i, val[i] = 0;
				FOR(i, n){
					if(i == block) continue;
					int a = A[i].X.X, b = A[i].X.Y, c = A[i].Y;
					if(find(a) != find(b)) val[find(b)] += val[find(a)], rep[find(a)] = find(b);
					val[find(a)] += c;
				}
				FOR(i, 4) all = std::max(all, val[find(i)]);
			}
			std::cout << all << "\n";
		}
	}else{
		all = 0;
		FOR(i, 4) all = std::max(all, val[find(i)]);
		std::cout << all << "\n"; 
	}
	return 0;
}