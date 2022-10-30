#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1505;

int n;

vector<int> edge[N], redge[N];

bool vis[N];

int include_count(int l0, int r0, int l1, int r1) {
	assert(l0 <= l1 && l1 <= r1 && r1 <= r0);
	return (l1 - l0 + 1) * (r0 - r1 + 1);
}

struct Tuple4 {
	int lx, ux, ly, uy;

	Tuple4() {};

	Tuple4(int x, int y) : lx(x), ux(x), ly(y), uy(y) {}

	Tuple4(int lx, int ux, int ly, int uy) : lx(lx), ux(ux), ly(ly), uy(uy) {}

	Tuple4 intersect(const Tuple4 b) const {
		return Tuple4(max(lx, b.lx), min(ux, b.ux), max(ly, b.ly), min(uy, b.uy));
	}

	Tuple4 join(const Tuple4 b) const {
		return Tuple4(min(lx, b.lx), max(ux, b.ux), min(ly, b.ly), max(uy, b.uy));
	}

	bool operator == (const Tuple4 b) const {
		return lx == b.lx && ux == b.ux && ly == b.ly && uy == b.uy;
	}

	long long vdiff(const Tuple4 b) const {
		int xlen = include_count(lx, ux, b.lx, b.ux),
			ylen = include_count(ly, uy, b.ly, b.uy);
		return (long long)xlen * ylen;
	}
};

long long ans = 0;

Tuple4 g[N << 1][N << 1];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		v -= n;
		edge[u].push_back(v);
		redge[v].push_back(u);
	}
	Tuple4 total(0, n - 1, 0, n - 1);
	for (int u = 0; u < n; ++u) {
		if (!vis[u]) {
			vector<int> loop;
			vis[u] = true;
			loop.push_back(u);
			int curu = u, curv = edge[curu][0], nxtu = redge[curv][0] ^ redge[curv][1] ^ curu;
			loop.push_back(curv);
			while (nxtu != u) {
				curu = nxtu;
				vis[curu] = true;
				loop.push_back(nxtu);
				curv = edge[curu][0] ^ edge[curu][1] ^ curv;
				loop.push_back(curv);
				nxtu = redge[curv][0] ^ redge[curv][1] ^ curu;
			}
			for (int i = 0; i < (int)loop.size(); ++i) {
				if (i % 2 == 0) {
					g[i][1] = Tuple4(loop[i], loop[(i + 1) % loop.size()]);
				} else {
					g[i][1] = Tuple4(loop[(i + 1) % loop.size()], loop[i]);
				}
				for (int j = 2; j <= (int)loop.size(); ++j) {
					if ((i + j) % 2 == 0) {
						g[i][j] = g[i][j - 1].join(Tuple4(loop[(i + j) % loop.size()],
														  loop[(i + j - 1) % loop.size()]));
					} else {
						g[i][j] = g[i][j - 1].join(Tuple4(loop[(i + j - 1) % loop.size()],
														  loop[(i + j) % loop.size()]));
					}
				}
			}
			for (int i = 0; i < (int)loop.size(); ++i) {
				for (int j = 1; j < (int)loop.size(); ++j) {
					int w = (j + 1) / 2;
					long long cnt;
					Tuple4 fa0 = g[i][j + 1], fa1 = g[(i + loop.size() - 1) % loop.size()][j + 1];
					if (fa0 == g[i][j] || fa1 == g[i][j]) {
						// no extensions
						continue;
					}
					int lenx, leny;
					if (j % 2 == 0) {
						// extensions on the same side
						if (i % 2 == 0) {
							// extensions on y
							lenx = include_count(0, n - 1, g[i][j].lx, g[i][j].ux);
							if (!(fa0.intersect(fa1) == g[i][j])) {
								// in the same direction
								Tuple4 fa = fa0.intersect(fa1);
								leny = include_count(fa.ly == g[i][j].ly ? 0 : fa.ly + 1,
										             fa.uy == g[i][j].uy ? n - 1 : fa.uy - 1,
													 g[i][j].ly, g[i][j].uy);
							} else {
								// in opposite directions
								Tuple4 fa = fa0.join(fa1);
								leny = include_count(fa.ly + 1, fa.uy - 1, g[i][j].ly, g[i][j].uy);
							}
						} else {
							// extensions on x
							leny = include_count(0, n - 1, g[i][j].ly, g[i][j].uy);
							if (!(fa0.intersect(fa1) == g[i][j])) {
								// in the same direction
								Tuple4 fa = fa0.intersect(fa1);
								lenx = include_count(fa.lx == g[i][j].lx ? 0 : fa.lx + 1,
										             fa.ux == g[i][j].ux ? n - 1 : fa.ux - 1,
													 g[i][j].lx, g[i][j].ux);
							} else {
								// in opposite directions
								Tuple4 fa = fa0.join(fa1);
								lenx = include_count(fa.lx + 1, fa.ux - 1, g[i][j].lx, g[i][j].ux);
							}
						}
					} else {
						// extensions on different sides
						if (i % 2 == 0) {
							// fa0 from on x
							lenx = include_count(fa0.lx == g[i][j].lx ? 0 : fa0.lx + 1,
												 fa0.ux == g[i][j].ux ? n - 1 : fa0.ux - 1,
												 g[i][j].lx, g[i][j].ux);
							// fa1 from on y
							leny = include_count(fa1.ly == g[i][j].ly ? 0 : fa1.ly + 1,
												 fa1.uy == g[i][j].uy ? n - 1 : fa1.uy - 1,
												 g[i][j].ly, g[i][j].uy);
						} else {
							// fa0 from on y 
							leny = include_count(fa0.ly == g[i][j].ly ? 0 : fa0.ly + 1,
												 fa0.uy == g[i][j].uy ? n - 1 : fa0.uy - 1,
												 g[i][j].ly, g[i][j].uy);
							// fa1 from on x 
							lenx = include_count(fa1.lx == g[i][j].lx ? 0 : fa1.lx + 1,
												 fa1.ux == g[i][j].ux ? n - 1 : fa1.ux - 1,
												 g[i][j].lx, g[i][j].ux);
						}
					}
					cnt = (long long)lenx * leny;
					/*
					cout << loop[i] << ' ' << i << ' ' << j << ' ' << w << ' ' << cnt << endl;
					cout << g[i][j].lx << ' ' << g[i][j].ux << ' ' << g[i][j].ly << ' ' << g[i][j].uy << endl;
					cout << fa0.lx << ' ' << fa0.ux << ' ' << fa0.ly << ' ' << fa0.uy << endl;
					cout << fa1.lx << ' ' << fa1.ux << ' ' << fa1.ly << ' ' << fa1.uy << endl;
					*/
					ans += cnt * w;
				}
			}
			ans += (loop.size() / 2) * (total.vdiff(g[0][loop.size()]));
		}
	}
	cout << ans << endl;
	return 0;
}