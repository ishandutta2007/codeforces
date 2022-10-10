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

struct pt {
	cat x, y;
	pt() {}
	pt(cat x, cat y): x(x), y(y) {}

	pt operator+(const pt &P) const {
		return pt(x+P.x, y+P.y);
	}
	pt operator-(const pt &P) const {
		return pt(x-P.x, y-P.y);
	}
	pt operator*(const int d) const {
		return pt(x*d, y*d);
	}
	pt operator*(const dbl d) const {
		return pt(round(x*d), round(y*d));
	}
	bool operator==(const pt &P) const {
		return (P.x == x && P.y == y);
	}
	bool operator!=(const pt &P) const {
		return (P.x != x || P.y != y);
	}
	bool operator<(const pt &P) const {
		if(P.x == x) return y < P.y;
		return x < P.x;
	}
};

bool mult(pt &P, cat a, cat b, pt &R) {
	if((P.x*a)%b != 0 || (P.y*a)%b != 0) return false;
	R.x += P.x*a/b;
	R.y += P.y*a/b;
	return true;
}

cat gcd(cat x, cat y) {
	if(x > y) swap(x, y);
	return (x == 0) ? y : gcd(y%x, x);
}

cat vs(pt &P, pt &R, pt &O) {
	return (P.x-O.x)*(R.y-O.y)-(P.y-O.y)*(R.x-O.x);
}

cat vs2(pt P, pt R) {
	return P.x*R.y-P.y*R.x;
}

cat dist(pt P, pt R) {
	return (P.x-R.x)*(P.x-R.x)+(P.y-R.y)*(P.y-R.y);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	N *= 2;
	vector<pt> P(N);
	for(int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
	vector<pt> cand;
	srand(N+1237983);
	int R = (N < 2000) ? min(N, 5) : 2;
	for(int k = 0; k < R; k++) {
		int a = rand()%N, b = rand()%N;
		while(a == b) b = rand()%N;
		vector<pt> V, Pa, Pb;
		for(int i = 0; i < N; i++) {
			if(vs(P[a], P[b], P[i]) == 0) continue;
			pt p = P[i]-P[a];
			cat d = gcd(abs(p.x), abs(p.y));
			p.x /= d, p.y /= d;
			if(p.x < 0) p.x *= -1, p.y *= -1;
			if(p.x == 0 && p.y < 0) p.y *= -1;
			if(p.x > 200000 || abs(p.y) > 200000) if(N > 2000) {
				for(int j = -10; j <= 10; j++) if(j != 0)
					if(p.x*j+P[a].x >= -1000000 && p.x*j+P[a].x <= 1000000)
					if(p.y*j+P[a].y >= -1000000 && p.y*j+P[a].y <= 1000000)
						V.push_back(P[a]+p*j);
				continue;
			}
			Pa.push_back(p);
		}
		sort(begin(Pa), end(Pa));
		Pa.resize(unique(begin(Pa), end(Pa))-begin(Pa));
		for(int i = 0; i < N; i++) {
			if(vs(P[a], P[b], P[i]) == 0) continue;
			pt p = P[i]-P[b];
			cat d = gcd(abs(p.x), abs(p.y));
			p.x /= d, p.y /= d;
			if(p.x < 0) p.x *= -1, p.y *= -1;
			if(p.x == 0 && p.y < 0) p.y *= -1;
			if(p.x > 200000 || abs(p.y) > 200000) if(N > 2000) {
				for(int j = -10; j <= 10; j++) if(j != 0)
					if(p.x*j+P[b].x >= -1000000 && p.x*j+P[b].x <= 1000000)
					if(p.y*j+P[b].y >= -1000000 && p.y*j+P[b].y <= 1000000)
						V.push_back(P[b]+p*j);
				continue;
			}
			Pb.push_back(p);
		}
		sort(begin(Pb), end(Pb));
		Pb.resize(unique(begin(Pb), end(Pb))-begin(Pb));
		pt vba = P[b]-P[a];
		for(int i = 0; i < (int)Pa.size(); i++) for(int j = 0; j < (int)Pb.size(); j++) {
			cat v = vs2(Pa[i], Pb[j]);
			if(v == 0) continue;
			pt c = P[a];
			if(!mult(Pa[i], vs2(vba, Pb[j]), v, c)) continue;
			if(abs(c.x) > 1000000 || abs(c.y) > 1000000) continue;
			V.push_back(c);
		}
		int a2 = 0;
		while(a2 == a || a2 == b) a2++;
		for(int j = 0; j < N; j++) if(j != a2 && j != a && j != b) {
			cat v = vs2(P[b]-P[a], P[j]-P[a2]);
			if(v == 0) continue;
			dbl r = (dbl) vs2(P[a2]-P[a], P[j]-P[a2]) / v;
			pt c = P[a] + (P[b]-P[a]) * r;
			if(vs(P[a], c, P[b]) != 0) continue;
			if(vs(P[a2], c, P[j]) != 0) continue;
			if(abs(c.x) > 1000000 || abs(c.y) > 1000000) continue;
			if(vs(P[a], P[b], P[a2]) == 0 || vs(P[a], P[b], P[j]) == 0) continue;
			V.push_back(c);
		}
		sort(begin(V), end(V));
		V.resize(unique(begin(V), end(V)) - begin(V));
		if(k == 0) {
			cand = V;
			continue;
		}
		vector<pt> cand_nw;
		a = b = 0;
		while(a < (int)cand.size() && b < (int)V.size()) {
			if(cand[a] == V[b]) {
				cand_nw.push_back(cand[a]);
				a++, b++;
				continue;
			}
			if(cand[a] < V[b]) a++;
			else b++;
		}
		cand = cand_nw;
	}
	ALL_THE(cand, it) {
		map<pt, int> M2;
		bool ok = true;
		for(int i = 0; i < N; i++) {
			pt dir = P[i]-(*it);
			cat d = gcd(abs(dir.x), abs(dir.y));
			if(d == 0) {
				ok = false;
				break;
			}
			if(d != 0) dir.x /= d, dir.y /= d;
			if(dir.x < 0) dir.x *= -1, dir.y *= -1;
			if(dir.x == 0 && dir.y < 0) dir.y *= -1;
			M2[dir]++;
		}
		ALL_THE(M2, it) if(it->ss != 2) ok = false;
		if(ok) {
			cout << "Yes\n" << it->x << " " << it->y << "\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;}

// look at my code
// my code is amazing