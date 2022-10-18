#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5;

bool query(const vi &a){
	cout << "? " << isz(a) << ' ';
	Fora(x, a){
		cout << x << ' ';
	} cout << endl;
	string s; cin >> s;
	return (s == "YES" ? true : false);
}

void answer(int x){
	cout << "! " << x << endl;
	string s; cin >> s;
	if (s == ":)"){
		exit(0);
	}
}

void solve(vi a){
	if (isz(a) >= 4){
		vi b[4];
		For(i, 0, isz(a)){
			b[i % 4].emplace_back(a[i]);
		}
		vi c[2];
		c[0].insert(c[0].end(), bend(b[0]));
		c[0].insert(c[0].end(), bend(b[1]));
		c[1].insert(c[1].end(), bend(b[0]));
		c[1].insert(c[1].end(), bend(b[2]));
		bool q1 = query(c[0]), q2 = query(c[1]);
		vi ta;
		For(i, 0, 4){
			int val = q1 * 2 + q2;
			if (i == val){
				continue;
			}
			ta.insert(ta.end(), bend(b[i]));
		}
		solve(ta);
	}
	if (isz(a) <= 2){
		Fora(x, a){
			answer(x);
		}
	}
	vi c[2];
	c[0] = {a[0], a[1]};
	c[1] = {a[0], a[2]};
	bool q1 = query(c[0]), q2 = query(c[1]);
	vi ta;
	For(i, 0, 3){
		int val = q1 * 2 + q2;
		if (i == val){
			continue;
		}
		ta.emplace_back(a[i]);
	}
	if (isz(ta) != isz(a)){
		solve(ta);
	}
	bool q3 = query({a[1]});
	if (q3 == false){
		ta = {c[1]};
		solve(ta);
	}
	answer(a[1]);
	bool q4 = query({a[0]});
	if (q4){
		answer(a[0]);
	}
	else{
		answer(a[2]);
	}
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// freopen("KEK.inp", "r", stdin);
	// freopen("KEK.out", "w", stdout);
	int n; cin >> n;
	vi a(n); iota(bend(a), 1);
	solve(a);
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/