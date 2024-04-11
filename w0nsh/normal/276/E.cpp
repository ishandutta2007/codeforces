#include <algorithm>
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
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = a; i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

inline int left(int i){
	return i << 1;
}
inline int right(int i){
	return (i<<1)+1;
}
inline int parent(int i){
	return i>>1;
}

struct Tree{
	VI t;
	int BOTTOM;

	void resize(int size){
		BOTTOM = 1;
		while(BOTTOM < size) BOTTOM <<= 1;
		t.resize(BOTTOM*2);
	}

	void update(int a, int b, int s){
		_update(a, b, s, 1, 0, BOTTOM-1);
	}

	void _update(int a, int b, int s, int v, int lo, int hi){
		if(a == lo && b == hi) t[v] += s;
		else if(a <= b){
			int mid = (lo+hi)>>1;
			_update(a, std::min(mid, b), s, left(v), lo, mid);
			_update(std::max(a, mid+1), b, s, right(v), mid+1, hi);
		}
	}

	int query(int v){
		v = BOTTOM+v;
		int sum = t[v];
		while(v > 1){
			v = parent(v);
			sum += t[v];
		}
		return sum;
	}
};

int n, q, ind, lengths[100005];
PII map[100005];
Tree all;
std::vector<Tree> single;
std::vector<VI> g;

void dfs(int v, int pos=0, int parent=0){
	map[v] = {ind, pos};
	lengths[ind] = pos+1;
	TRAV(ch, g[v]) if(ch != parent) dfs(ch, pos+1, v);
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	g.resize(n);
	FOR(i, n-1){
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	TRAV(ch, g[0]){
		dfs(ch);
		ind++;
	}
	int max = 0;
	single.resize(ind);
	FOR(i, ind){
		single[i].resize(lengths[i]);
		max = std::max(lengths[i], max);
	}
	all.resize(max+1);
	while(q--){
		int which;
		std::cin >> which;
		if(which == 1){
			int v;
			std::cin >> v;
			v--;
			if(v == 0) std::cout << all.query(0) << std::endl;
			//else std::cout << single[map[v].X].query(map[v].Y) << " + " <<  all.query(map[v].Y+1) << std::endl;
			else std::cout << single[map[v].X].query(map[v].Y) + all.query(map[v].Y+1) << std::endl;
		}else{
			int v, x, d;
			std::cin >> v >> x >> d;
			v--;
			if(v == 0){
				//std::cout << "all " << 0 << " " << d << std::endl;
				all.update(0, std::min(d, max), x);
			}else{
				int a = d - map[v].Y;
				if(a > 0){
					int to = std::min(a-1, max);
				//	std::cout << "a=" << a << ", to=" << to << std::endl;
				//	std::cout << "all " << 0 << " " << to << std::endl;
					all.update(0, to, x);
					// to = first to update
					if(to <= std::min(map[v].Y+d, lengths[map[v].X]-1)){
				//		std::cout << "single" << map[v].X << " " << to << " " << std::min(map[v].Y+d, lengths[map[v].X]-1) << std::endl;
						single[map[v].X].update(to, std::min(map[v].Y+d, lengths[map[v].X]-1), x);
					}
				}else{
				//	std::cout << "single" << map[v].X << " " << map[v].Y-d << " " << std::min(map[v].Y+d, lengths[map[v].X]-1) << std::endl;
					single[map[v].X].update(map[v].Y-d, std::min(map[v].Y+d, lengths[map[v].X]-1), x);
				}	
			}	
		}
	}
	return 0;
}