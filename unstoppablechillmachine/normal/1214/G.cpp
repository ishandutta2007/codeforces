#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 2010;
bitset<N> cur, cur2, ones[N], bt[N];

inline bool is_good(int A, int B) {
	cur = (bt[A] ^ bt[B]);
	int x = cur.count();
	cur = (bt[A] & cur);
	int y = cur.count();
	return (y != 0 && y != x);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	set<pair<int, int>> st;
	set<pair<int, int>> good;
	for (int i = 1; i <= n; i++) {
		st.insert({0, i});
	}
	ones[1][1] = 1;
	for (int i = 2; i <= 2000; i++) {
		ones[i] = ones[i - 1];
		ones[i][i] = 1;
	}
	for (int i = 0; i < q; i++) {
		int a, l, r;
		cin >> a >> l >> r;
		auto it = st.find({bt[a].count(), a});
		auto it2 = it, it3 = it;
		it3++;
		if (it2 != st.begin() && it3 != st.end()) {
			it2--;
			if (good.find(make_pair(it2->S, it->S)) != good.end()) {
				good.erase(make_pair(it2->S, it->S));
			}
			if (good.find(make_pair(it->S, it3->S)) != good.end()) {
				good.erase(make_pair(it->S, it3->S));
			}
			if (is_good(it2->S, it3->S)) {
				good.insert(make_pair(it2->S, it3->S));
			}		
		}
		else if (it2 != st.begin()) {
			it2--;
			if (good.find(make_pair(it2->S, it->S)) != good.end()) {
				good.erase(make_pair(it2->S, it->S));
			}
		}
		else if (it3 != st.end()) {
			if (good.find(make_pair(it->S, it3->S)) != good.end()) {
				good.erase(make_pair(it->S, it3->S));
			}
		}
		st.erase(it);
		bt[a] ^= (ones[r - l + 1] << (l - 1));
		st.insert({bt[a].count(), a});
		it = st.find({bt[a].count(), a});
		it2 = it, it3 = it;
		it3++;
		if (it2 != st.begin() && it3 != st.end()) {
			it2--;
			if (good.find(make_pair(it2->S, it3->S)) != good.end()) {
				good.erase(make_pair(it2->S, it3->S));
			}
			if (is_good(it2->S, it->S)) {
				good.insert(make_pair(it2->S, it->S));
			}
			if (is_good(it->S, it3->S)) {
				good.insert(make_pair(it->S, it3->S));
			}
		}
		else if (it2 != st.begin()) {
			it2--;
			if (is_good(it2->S, it->S)) {
				good.insert(make_pair(it2->S, it->S));
			}
		}
		else if (it3 != st.end()) {
			if (is_good(it->S, it3->S)) {
				good.insert(make_pair(it->S, it3->S));
			}	
		}
		if (good.empty()) {
			cout << -1 << '\n';
		}	
		else {
			int A = good.begin()->F,  B = good.begin()->S;
			if (A > B) {
				swap(A, B);
			}
			cur = bt[A] ^ bt[B];
			cur2 = cur & bt[A];
			int pos1 = cur2._Find_first();
			cur2 = cur & bt[B];
			int pos2 = cur2._Find_first();
			if (pos1 > pos2) {
				swap(pos1, pos2);
			}
			cout << A << ' ' << pos1 << ' ' << B << ' ' << pos2 << '\n';
		}
	} 	
}