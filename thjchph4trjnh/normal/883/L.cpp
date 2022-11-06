//This is getting accepted!
// I HATE BUG
// God Of The Bugs
// 12/11/2016
#include<bits/stdc++.h>

using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FI first
#define SE second
#define pb push_back
#define mp make_pair
#define ll long long
#define sz(a) ((int)(a).size())
#define __builtin_popcount __builtin_popcounll
#define ld long double

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<int, pii> ppi;
typedef pair<ll, int> pli;

const double PI = acos(0) * 2;
const double EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll oo = 1e18;
const double foo = 1e30;

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcounll(s);}
template<class T> T sqr(T x) { return x * x; }

inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}

int n, k, m, a[MAXN];
set<int> pos;
set<pli> house[MAXN];
priority_queue<pair<ll, pii> > st;

ll curT;

void addM(pair<ll, pii> now) {
	int id = now.SE.FI;
	pos.insert(id);
	if (house[id].empty()) {
		pos.insert(id);
	}
	house[id].insert(mp(-now.FI, now.SE.SE));
}

int cmp(pli a, pli b) {
	if (a.FI == b.FI) {
		return a.SE > b.SE;
	}
	return a.FI > b.FI;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

	cin >> n >> k >> m;
	
	for (int i=0; i<k; i++) {
		cin >> a[i];
		pos.insert(a[i]);
		house[a[i]].insert(mp(0ll, i + 1));
	}
	
	for (int i=0; i<m; i++) {
		ll t;
		int ss, ee;
		scanf("%I64d%d%d", &t, &ss, &ee);
		while (!st.empty() && -st.top().FI <= t) {
			addM(st.top());	
			st.pop();	
		}
		
		curT = max(curT, t);		
		if (!pos.empty()) {
			ll tw = curT - t;
			set<int>::iterator it = pos.lower_bound(ss);
			
			ll dis = oo;
			int now = -1;
			
			if (it != pos.end()) {
				dis = abs(*it - ss);
				now = *it;
			}
			
			if (it != pos.begin()) {
				it--;
				if (!~now || dis > abs(*it - ss)) {
					dis = abs(*it - ss);
					now = *it;
				}
				else if (~now && dis == abs(*it - ss)) {
					if (cmp(*house[now].begin(), *house[*it].begin()) == 1) {
						now = *it;
					}
				}
			}
			
			int car = (*house[now].begin()).SE;
			
			house[now].erase(house[now].begin());
						
			if (house[now].empty()) {
				pos.erase(now);
			}
			
			printf("%d %I64d\n", car, dis + tw);
			
			st.push(mp(-(t + tw + dis + (ll) abs(ee - ss)), mp(ee, car)));
		}
		else {
//			cout << "hrer" << endl;
			pair<ll, pii> cur = st.top();
			curT = max(curT, -cur.FI);
			st.pop();
			addM(cur);
			while (!st.empty() && st.top().FI == cur.FI) {
				addM(st.top());
				st.pop();
			}
			
			assert(!pos.empty());
			
			ll tw = curT - t; 
			set<int>::iterator it = pos.lower_bound(ss);
			
			ll dis = oo;
			int now = -1;
			
			if (it != pos.end()) {
				dis = abs(*it - ss);
				now = *it;
			}
			
			if (it != pos.begin()) {
				it--;
				if (!~now || dis > abs(*it - ss)) {
					dis = abs(*it - ss);
					now = *it;
				}
				else if (~now && dis == abs(*it - ss)) {
					if (cmp(*house[now].begin(), *house[*it].begin()) == 1) {
						now = *it;
					}
				}
			}

			int car = (*house[now].begin()).SE;
			
			house[now].erase(house[now].begin());
			
			if (house[now].empty()) {
				pos.erase(now);
			}
			
			printf("%d %I64d\n", car, dis + tw);
			
			st.push(mp(-(-cur.FI + dis + (ll) abs(ee - ss)), mp(ee, car)));
		}
	}

	return 0;
}