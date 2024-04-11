#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

using cat = long long;

struct ww {
	cat s;
	int l, id;

	bool operator<(const ww & w) const {
		return s < w.s;
	}
};

template<typename T>
class FenwickTree {
	vector<T> V;

	int lastone(int x) {return x & (x ^ (x-1));}

public:
	FenwickTree(int N) : V(N+10, 0) {}

	void add(int pos, T val) {
		for(int i = pos+1; i < (int)V.size(); i += lastone(i)) V[i] += val;
	}

	T get(int l, int r) {
		T ret = 0;
		for(int i = r; i > 0; i -= lastone(i)) ret += V[i];
		for(int i = l; i > 0; i -= lastone(i)) ret -= V[i];
		return ret;
	}

};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, L, mul = 1000000000;
	cin >> N >> L;
	vector<ww> W;
	int last = 0;
	for(int i = 0; i < N; i++) {
		int x, y;
		double sd;
		cin >> x >> y >> sd;
		cat s = (cat)floor(sd*1e9+.1);
		if(x > last) W.push_back({mul, x-last, -1});
		W.push_back({mul+s, y-x, -1});
		last = y;
	}
	if(last < L) W.push_back({mul, L-last, -1});
	N = W.size();
	for(int i = 0; i < N; i++) W[i].id = i;
	sort(begin(W), end(W));
	vector<double> E(N, 0), E_max(N), E_nmin(N);
	for(int i = 0; i < N; i++) {
		E_nmin[i] = W[i].l*1e9/(W[i].s+mul);
		E_max[i] = (W[i].s == mul) ? 0 : (W[i].l*1e9/(W[i].s-mul));
	}
	FenwickTree<double> I(N);
	for(int i = 0; i < N; i++) I.add(W[i].id, E_max[i]);
	set<int> nonempty;
	for(int i = 0; i < N; i++) nonempty.insert(i);
	for(int i = 0; i < N; i++) {
		// energia -x: x <= E_nmin[i], sucet do tohto bodu >= x + E_max[i]
		double x = I.get(0, W[i].id+1);
		E[i] = E_max[i] - x;
		if(E_nmin[i] < x-E_max[i]) E[i] = -E_nmin[i];
		double d = E_max[i]-E[i];
		for(auto it = nonempty.upper_bound(W[i].id); it != begin(nonempty); ) {
			it--;
			if(double s = I.get(*it, (*it)+1); d > s) {
				d -= s;
				I.add(*it, -s);
				auto jt = it++;
				nonempty.erase(jt);
			}
			else {
				I.add(*it, -d);
				break;
			}
		}
		if(auto it = nonempty.find(W[i].id); it != end(nonempty))
			nonempty.erase(it);
	}
	double ans = 0;
	for(int i = 0; i < N; i++) ans += (E[i]+W[i].l) * 1e9 / W[i].s;
	cout << fixed << setprecision(12) << ans << "\n";
}