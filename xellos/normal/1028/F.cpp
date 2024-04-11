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

struct pt {
	cat x, y;

	pt operator+(const pt & P) const {
		return {x + P.x, y + P.y};
	}

	bool operator!=(const pt & P) const {
		return (x != P.x) || (y != P.y);
	}

	pt gcd_reduce() const {
		cat a = x, b = y;
		if(a > b) swap(a, b);
		while(a > 0) {
			cat c = a;
			a = b % a;
			b = c;
		}
		// b == gcd
		return {x/b, y/b};
	}

	cat dist() const {
		return x * x + y * y;
	}

	cat to_int() const {
		return x * 1000000 + y;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int Q;
	cin >> Q;
	int cnt = 0;
	map<cat, vector<pt> > dist_group;
	unordered_map<cat, cat> cnt_sym;
	for(int q = 0; q < Q; q++) {
		int tp;
		pt P;
		cin >> tp >> P.x >> P.y;
		if(tp == 3) {
			cat pt_idx = P.gcd_reduce().to_int();
			auto it = cnt_sym.find(pt_idx);
			cout << cnt - ((it == end(cnt_sym)) ? 0 : it->ss) << "\n";
			continue;
		}
		auto it = dist_group.find(P.dist());
		if(it == end(dist_group)) {
			dist_group[P.dist()] = vector<pt>();
			it = dist_group.find(P.dist());
		}
		vector<pt> & pts = it->ss;
		if(tp == 1) {
			ALL_THE(pts, jt) cnt_sym[(P+(*jt)).gcd_reduce().to_int()] += 2;
			cnt_sym[P.gcd_reduce().to_int()]++;
			pts.push_back(P);
			cnt++;
		}
		else {
			int idx = 0;
			while(P != pts[idx]) {
				cnt_sym[(P+pts[idx]).gcd_reduce().to_int()] -= 2;
				idx++;
			}
			for(int i = idx+1; i < (int)pts.size(); i++)
				cnt_sym[(P+pts[i]).gcd_reduce().to_int()] -= 2;
			cnt_sym[P.gcd_reduce().to_int()]--;
			pts.erase(begin(pts)+idx);
			cnt--;
		}
	}
	return 0;
}

// look at my code
// my code is amazing