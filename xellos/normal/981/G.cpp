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

const cat mod = 998244353;

struct intervalac {
	struct node {
		int son[2];
		int z, k;
		cat sum, mul, add;
	};
	vector<node> T;

	void constI(int akt) {
		node n = T[akt];
		if(n.z+1 == n.k) return;
		for(int i = 0; i < 2; i++) {
			if(i == 0) n.k = (n.z+n.k) / 2;
			else {n.z = n.k; n.k = T[akt].k;}
			T[akt].son[i] = T.size();
			T.push_back(n);
			constI(T[akt].son[i]);
		}
	}

	intervalac(int N) {
		node n;
		n.z = 0, n.k = N;
		n.son[0] = n.son[1] = -1;
		n.sum = n.mul = n.add = 0;
		T.dibs(2*N);
		T.resize(1, n);
		constI(0);
	}

	void upd(int akt) {
		node & n = T[akt];
		if(n.son[0] == -1) return;
		if(n.mul == 1 && n.add == 0) return;
		for(int i = 0; i < 2; i++) {
			int sz = T[n.son[i]].k - T[n.son[i]].z;
			T[n.son[i]].sum = (T[n.son[i]].sum * n.mul + n.add * sz) % mod;
			T[n.son[i]].mul = (T[n.son[i]].mul * n.mul) % mod;
			T[n.son[i]].add = (T[n.son[i]].add * n.mul + n.add) % mod;
		}
		n.mul = 1;
		n.add = 0;
	}

	void upd(int akt, cat mul, cat add) {
		node & n = T[akt];
		int sz = n.k - n.z;
		n.sum = (n.sum * mul + add * sz) % mod;
		n.mul = (n.mul * mul) % mod;
		n.add = (n.add * mul + add) % mod;
	}

	void add(int akt, int zac, int kon, cat val) {
		upd(akt);
		node & n = T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && kon == n.k) {
			upd(akt, 1, val);
			upd(akt);
			return;
		}
		add(n.son[0], zac, min(kon, (n.z+n.k)/2), val);
		add(n.son[1], max(zac, (n.z+n.k)/2), kon, val);
		n.sum = (T[n.son[0]].sum + T[n.son[1]].sum) % mod;
	}

	void mul(int akt, int zac, int kon, cat val) {
		upd(akt);
		node & n = T[akt];
		if(n.z >= kon || zac >= n.k) return;
		if(n.z == zac && kon == n.k) {
			upd(akt, val, 0);
			upd(akt);
			return;
		}
		mul(n.son[0], zac, min(kon, (n.z+n.k)/2), val);
		mul(n.son[1], max(zac, (n.z+n.k)/2), kon, val);
		n.sum = (T[n.son[0]].sum + T[n.son[1]].sum) % mod;
	}

	cat get(int akt, int zac, int kon) {
		upd(akt);
		node & n = T[akt];
		if(n.z >= kon || zac >= n.k) return 0;
		if(n.z == zac && kon == n.k) return n.sum;
		cat ret = (get(n.son[0], zac, min(kon, (n.z+n.k)/2))
					+ get(n.son[1], max(zac, (n.z+n.k)/2), kon)) % mod;
		return ret;
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N, Q;
	cin >> N >> Q;
	vector< set< pair<int, int> > > S(N);
	intervalac I(N);
	for(int i = 0; i < Q; i++) {
		int tp, l, r;
		cin >> tp >> l >> r;
		l--;
		if(tp == 2) {
			cat ans = I.get(0, l, r) % mod;
			if(ans < 0) ans += mod;
			cout << I.get(0, l, r) << "\n";
			continue;
		}
		int x;
		cin >> x;
		x--;
		auto it = S[x].lower_bound(make_pair(l, -1));
		int lt = l, rt = r;
		if(it != begin(S[x])) {
			auto jt = it; jt--;
			if(jt->ss >= rt) {
				I.mul(0, lt, rt, 2);
				continue;
			}
			if(jt->ss > lt) {
				lt = jt->ff;
				I.mul(0, l, jt->ss, 2);
				l = jt->ss;
				S[x].erase(jt);
			}
		}
		while(l < r && it != end(S[x])) {
			int r_nw = it->ff, l_nw = it->ss;
			if(r_nw >= r) break;
			I.add(0, l, r_nw, 1);
			l = r_nw;
			if(l_nw >= r) {
				I.mul(0, l, r, 2);
				l = r;
				rt = l_nw;
				S[x].erase(it);
			}
			else {
				I.mul(0, l, l_nw, 2);
				l = l_nw;
				auto jt = it;
				it++;
				S[x].erase(jt);
			}
		}
		if(l < r)
			I.add(0, l, r, 1);
		S[x].insert(make_pair(lt, rt));
	}
	return 0;}

// look at my code
// my code is amazing