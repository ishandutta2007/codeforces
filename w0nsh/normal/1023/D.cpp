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

const int INF = 2000000666;

int n, q;
VI A, close;
VI strip;

struct Tree{
	int BOTTOM;
	VI t;

	Tree(){}

	void up(int v=1){
		if(v < BOTTOM){
			up(v<<1);
			up((v<<1)+1);
			t[v] = std::min(t[v<<1], t[(v<<1)+1]);
		}
	}
	
	void build(std::vector<int> &vec){
		BOTTOM = 1;
		while(BOTTOM < vec.size()) BOTTOM *= 2;
		t.resize(BOTTOM*2);
		FOR(i, SZ(vec)) t[BOTTOM+i] = vec[i];
		up();
	}

	int query(int a, int b, int v=1, int lo=0, int hi=-1){
		if(hi == -1) hi = BOTTOM-1;
		if(a > b) return INF;
		if(a == lo && b == hi) return t[v];
		int mid = (lo+hi)/2;
		return std::min(query(a, std::min(b, mid), v<<1, lo, mid),
						query(std::max(a, mid+1), b, (v<<1)+1, mid+1, hi));
	}
};

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> q;
	A.resize(n);
	FOR(i, n) std::cin >> A[i];
	int last_zero = -1;
	FOR(i, n) if(A[i] == 0) last_zero = i;
	int max = 0;
	FOR(i, n) max = std::max(max, A[i]);
	if(max == 0){
		std::cout << "YES\n";
		FOR(i, n) std::cout << q << " ";
		return 0;
	}
	if(max < q){
		if(last_zero != -1){
			A[last_zero] = q;
		}else{
			std::cout << "NO\n";
			return 0;
		}
	}else last_zero = -1;
	close.resize(n);
	close[n-1] = A[n-1];
	for(int i = n-2; i >= 0; --i){
		if(A[i] != 0) close[i] = A[i];
		else close[i] = close[i+1];
	}
	int last_good = 0;
	FOR(i, n){
		if(A[i] != 0) last_good = A[i];
		if(close[i] == 0) close[i] = last_good;
	}
	//check
	FOR(i, n) if(A[i] != 0) strip.push_back(A[i]);
	Tree tree = Tree();
	tree.build(strip);
	std::unordered_map<int, PII> map;
	FOR(i, q+1) map[i] = {-1, -1};
	FOR(i, SZ(strip)) map[strip[i]].Y = i;
	for(int i = SZ(strip)-1; i >= 0; --i) map[strip[i]].X = i;
	REP(i, 1, q+1){
		if(map[i].X == -1) continue;
		if(tree.query(map[i].X, map[i].Y) < i){
			std::cout << "NO\n";
			return 0;
		}
	}
	// end check
	std::cout << "YES\n";
	FOR(i, n){
		if(A[i] == 0 && i != last_zero){
			std::cout << close[i] << " ";
		}else{
			std::cout << A[i] << " ";
		}
	}
	return 0;
}