/*input
7
1 0 0 1 0 1 0
9 2 9 2 2 9 9
2 6
1 2
4 2
6 5
3 6
7 4
2
1 3
7 5
*/
#include <bits/stdc++.h>

using namespace std;

struct uzklausa {
	int l, r, i, p;
};

int depth[100000] = {}, parent[17][100000];
int start[100000], endd[100000];

void dfs(int i, vector<int> gra[], vector<int> &tvark, vector<bool> &apl) {
	start[i] = tvark.size();
	tvark.push_back(i);
	apl[i] = true;

	for (auto && x : gra[i]) {
		if (!apl[x]) {
			depth[x] = depth[i] + 1;
			parent[0][x] = i;
			dfs(x, gra, tvark, apl);
		}
	}

	endd[i] = tvark.size();
	tvark.push_back(i);
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];

	for (int i = 0; i < 17; i++) {
		if ((diff >> i) & 1)
			u = parent[i][u];
	}

	if (u == v) return u;

	for (int i = 17 - 1; i >= 0; i--) {
		if (parent[i][u] != parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];
		}
	}

	return parent[0][u];
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	bool lyt[n];

	for (int i = 0; i < n; i++)
		cin >> lyt[i];

	map<int, int> numer;
	int myl[n];

	for (int i = 0; i < n; i++) {
		cin >> myl[i];

		if (numer.find(myl[i]) == numer.end())
			numer[myl[i]] = numer.size() - 1;

		myl[i] = numer[myl[i]];
	}

	vector<int> gra[n];

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	vector<int> tvark;
	{
		vector<bool> apl(n, false);
		dfs(0, gra, tvark, apl);


		for (int i = 1; i < 17; i++) {
			for (int j = 0; j < n; j++) {
				if (parent[i - 1][j] != -1)
					parent[i][j] = parent[i - 1][parent[i - 1][j]];
			}
		}
	}

	int q;
	cin >> q;

	uzklausa uzk[q];

	for (int i = 0; i < q; i++) {
		cin >> uzk[i].l >> uzk[i].r;
		uzk[i].l--, uzk[i].r--;
		uzk[i].i = i;

		if (start[uzk[i].l] > start[uzk[i].r]) swap(uzk[i].l, uzk[i].r);

		uzk[i].p = lca(uzk[i].l, uzk[i].r);

		if (uzk[i].p == uzk[i].l) {
			uzk[i].p = -1;
			uzk[i].l = start[uzk[i].l];
			uzk[i].r = start[uzk[i].r];
		}
		else {
			uzk[i].l = endd[uzk[i].l];
			uzk[i].r = start[uzk[i].r];
		}
	}

	long long k = sqrt(2 * n);

	sort(uzk, uzk + q, [&](const auto & i, const auto & j) -> bool {
		return make_pair(i.l / k, i.r) < make_pair(j.l / k, j.r);
	});

	long long ats[q];

	bool prid[n] = {};
	long long kiek[n][2] = {};
	int pl = 0, pr = 0;
	long long atst = 0;

	auto toggle = [&](int u) {
		atst -= kiek[myl[u]][0] * kiek[myl[u]][1];

		if (prid[u])
			kiek[myl[u]][lyt[u]]--;
		else
			kiek[myl[u]][lyt[u]]++;

		/*cout << endl;
		cout << u << " " << myl[u] << " " << lyt[u] << endl;
		cout << kiek[0][0] << " " << kiek[0][1] << endl;
		cout << kiek[1][0] << " " << kiek[1][1] << endl;
		cout << endl;*/

		prid[u] ^= 1;

		atst += kiek[myl[u]][0] * kiek[myl[u]][1];
	};

	toggle(0);

	for (int i = 0; i < q; i++) {
		//cout << uzk[i].l << " " << uzk[i].r << endl;

		while (pl > uzk[i].l)
			toggle(tvark[--pl]);

		while (pr < uzk[i].r)
			toggle(tvark[++pr]);

		while (pl < uzk[i].l)
			toggle(tvark[pl++]);

		while (pr > uzk[i].r)
			toggle(tvark[pr--]);

		if (uzk[i].p != -1) toggle(uzk[i].p);

		ats[uzk[i].i] = atst;

		if (uzk[i].p != -1) toggle(uzk[i].p);
	}

	for (int i = 0; i < q; i++)
		cout << ats[i] << "\n";


	return 0;
}