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

int n, m;
char t;
bool tab[200][200];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	int first = -1;
	int last = -1;
	int fy = -1;
	bool end = false;
	FOR(i, n){
		FOR(j, m){
			std::cin >> t;
			if(t == 'B'){
				tab[i][j] = true;
				if(first == -1) first = j;
				if(!end){
					fy = i;
					last = j;
				} 
			}
		}
		if(last != -1) end = true;
	}
	int mid = (last+first)/2;
	int fyl = -1;
	REP(i, fy, n) if(tab[i][mid]) fyl = i;
	std::cout << (fyl+fy)/2+1 << " " << mid+1 << "\n";
	return 0;
}