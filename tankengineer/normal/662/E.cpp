#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005, K = 6, INF = 1000000000;

int n;

int t[N][3], pass[3], hack[3];

bool ch[N][3];

int nhack[K][3];

int calcs(int lv, int t) {
	if (t == 0) {
		return 0;
	} else {
		return 500 * (lv + 1) * (250 - t) / 250;
	}
}

const int L = 105;

int dp[L][L][L];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp < 0) {
				//can hack
				t[i][j] = -tmp;
				ch[i][j] = true;
				++pass[j];
				++hack[j];
			} else if (tmp == 0) {
				//didn't solve
			} else { 
				//can't hack
				t[i][j] = tmp;
				ch[i][j] = false;
				++pass[j];
			}
		}
	}
	int ans = n;
	for (int i = 0; i < 6; ++i) {
		int c = 2 << i, minp = i == 5 ? 0 : n / c + 1, maxp = 2 * n / c;
		for (int j = 0; j < 3; ++j) {
			if (pass[j] >= minp && pass[j] - hack[j] <= maxp) {
				nhack[i][j] = min(hack[j], pass[j] - minp);
			} else {
				nhack[i][j] = -1;
			}
		}
	}
	for (int ai = 0; ai < 6; ++ai) {
		int la = nhack[ai][0];
		if (la != -1) {
			for (int bi = 0; bi < 6; ++bi) {
				int lb = nhack[bi][1];
				if (lb != -1) {
					for (int ci = 0; ci < 6; ++ ci) {
						int lc = nhack[ci][2];
						if (lc != -1) {
							int myscore = calcs(ai, t[0][0]) + calcs(bi, t[0][1]) + calcs(ci, t[0][2]) + (la + lb + lc) * 100;
							if (myscore >= calcs(ai, 1) + calcs(bi, 1) + calcs(ci, 1)) {
								ans = 1;
								printf("%d\n", ans);
								return 0;
							}
							for (int i = 0; i <= la; ++i) {
								for (int j = 0; j <= lb; ++j) {
									for (int k = 0; k <= lc; ++k) {
										dp[i][j][k] = 0;
									}
								}
							}
							int lv[3];
							lv[0] = ai, lv[1] = bi, lv[2] = ci;
							int buf = 0;
							for (int i = 1; i < n; ++i) {
								vector<int> sol;
								for (int j = 0; j < 8; ++j) {
									bool dup = false;
									for (int k = 0; k < (int)sol.size() && !dup; ++k) {
										int s = sol[k];
										dup = dup | ((s & j) == s);
									}
									if (dup) {
										continue;
									}
									int tmpscore = 0;
									for (int k = 0; k < 3; ++k) {
										if ((j >> k) & 1) {
											if (!ch[i][k]) {
												tmpscore = INF;
												break;
											}
										} else {
											tmpscore += calcs(lv[k], t[i][k]);
										}
									}
									if (tmpscore <= myscore) {
										sol.push_back(j);
									}
								}
								if (sol.size() == 0) {
									continue;
								} else if (sol[0] == 0) {
									++buf;
									continue;
								}
								{
									if (dp[la][lb][lc] == la + lb + lc) {
										continue;
									}
									for (int i = la; i >= 0; --i) {
										for (int j = lb; j >= 0; --j) {
											for (int k = lc; k >= 0; --k) {
												for (int l = 0; l < (int)sol.size(); ++l) {
													int ni = i + (sol[l] & 1),
														nj = j + ((sol[l] >> 1) & 1),
														nk = k + ((sol[l] >> 2) & 1);
													if (dp[ni][nj][nk] < dp[i][j][k] + 1) {
														dp[ni][nj][nk] = dp[i][j][k] + 1;
													}
												}
											}
										}
									}
								}
							}
							ans = min(ans, n - (dp[la][lb][lc] + buf));
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}