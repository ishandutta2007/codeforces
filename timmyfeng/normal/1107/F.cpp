#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 500;
const ll INF = 1e18;

ll d[MX][MX], labx[MX], laby[MX], mn[MX];
int matx[MX], maty[MX], mnx[MX];
bool cntx[MX], cnty[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b, k;
		cin >> a >> b >> k;
		for (int j = 0; j < n; ++j) {
			d[i][j] = max(0LL, a - (ll)b * min(j, k));
		}
	}

	memset(matx, -1, sizeof matx);
	memset(maty, -1, sizeof maty);
	for (int i = 0; i < n; ++i) {
		labx[i] = *max_element(d[i], d[i] + n);
	}

	for (int x = 0; x < n; ++x) {
		memset(cntx, false, sizeof cntx);
		memset(cnty, false, sizeof cnty);
		cntx[x] = true;
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			mn[i] = labx[x] + laby[i] - d[x][i];
			mnx[i] = x;
			if (!mn[i]) {
				q.push(i);
				cnty[i] = true;
			}
		}

		int cur = -1;
		while (true) {
			if (q.empty()) {
				ll delta = *min_element(mn, mn + n);
				for (int i = 0; i < n; ++i) {
					if (cntx[i]) {
						labx[i] -= delta;
					}
					if (cnty[i]) {
						laby[i] += delta;
					} else {
						mn[i] -= delta;
						if (!mn[i]) {
							q.push(i);
							cnty[i] = true;
						}
					}
				}
			} else {
				cur = q.front();
				q.pop();
				if (matx[cur] == -1)
					break;
				int p = matx[cur];
				cntx[p] = cnty[cur] = true;
				mn[cur] = INF;
				for (int i = 0; i < n; ++i) {
					if (!cnty[i]) {
						ll val = labx[p] + laby[i] - d[p][i];
						if (val < mn[i]) {
							mn[i] = val;
							mnx[i] = p;
						}
						if (!mn[i]) {
							q.push(i);
							cnty[i] = true;
						}
					}
				}
			}
		}

		while (cur != -1) {
			int nxt = maty[mnx[cur]];
			maty[mnx[cur]] = cur;
			matx[cur] = mnx[cur];
			cur = nxt;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += labx[i] + laby[i];
	}
	cout << ans << '\n';
}