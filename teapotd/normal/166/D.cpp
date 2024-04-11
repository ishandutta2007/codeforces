#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int main() {
	cin.sync_with_stdio(0);
	cout << fixed << setprecision(15);

	map<int, Pii> shoes; // size -> (cost, index)
	map<int, vector<Pii>> customers; // size -> (max cost, index)

	int n; cin >> n;
	rep(i, 0, n) {
		int c, s; cin >> c >> s;
		shoes[s] = {c, i};
	}

	int m; cin >> m;
	rep(i, 0, m) {
		int c, s; cin >> c >> s;
		customers[s].pb({c, i});
	}

	Vi tmp;
	vector<Pii> chosen; // (customer, shoe)
	ll profit = 0;

	auto sell = [&](int customer, int shoeSize) {
		chosen.pb({customer, shoes[shoeSize].y});
		profit += shoes[shoeSize].x;
		shoes.erase(shoeSize);
	};

	each(p, customers) {
		int size = p.x;
		auto& vec = p.y;
		sort(all(vec), [&](Pii& l, Pii& r) { return l.x > r.x; });

		while (!vec.empty()) {
			int maxCost = vec.back().x, ind = vec.back().y;
			tmp.clear();

			rep(i, size, size+2) {
				if (shoes.count(i)) {
					if (shoes[i].x <= maxCost) tmp.pb(i);
				}
			}

			if (sz(tmp) >= 2) break;
			if (!tmp.empty()) sell(ind, tmp[0]);
			vec.pop_back();
		}

		if (sz(vec) >= 2) {
			sell(vec[0].y, size);
			sell(vec[1].y, size+1);
			vec.clear();
		}
	}

	queue<int> que;
	each(p, customers) que.push(p.x);

	while (!que.empty()) {
		int size = que.front();
		auto& vec = customers[size];
		que.pop();
		if (vec.empty()) continue;

		int a = int(shoes.count(size)), b = int(shoes.count(size+1));

		if (!a && !b) {
			vec.clear();
		} else if (!a) {
			sell(vec[0].y, size+1);
			que.push(size+1);
			vec.clear();
		} else if (!b) {
			sell(vec[0].y, size);
			que.push(size-1);
			vec.clear();
		}
	}

	each(p, customers) if (!p.y.empty()) {
		int first = p.x, last = p.x+1;
		int worst = min(shoes[first].x, shoes[last].x);

		while (customers.count(last) && !customers[last].empty()) {
			last++;
			worst = min(worst, shoes[last].x);
		}

		int i = first;

		for (; i <= last; i++) {
			if (shoes[i].x == worst) break;
			sell(customers[i][0].y, i);
			customers[i].clear();
		}

		for (i++; i <= last; i++) {
			sell(customers[i-1][0].y, i);
			customers[i-1].clear();
		}
	}

	cout << profit << '\n' << sz(chosen) << '\n';
	each(p, chosen) cout << p.x+1 << ' ' << p.y+1 << '\n';
	return 0;
}