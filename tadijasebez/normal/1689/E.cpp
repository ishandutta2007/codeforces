#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int a[N];

void DFS(int u, vector<bool>& was, vector<vector<int>>& E, vector<int>& now) {
	was[u] = true;
	now.push_back(u);
	for (int v : E[u]) {
		if (!was[v])
			DFS(v, was, E, now);
	}
}

int best = -1;
bool Try(int n) {
	vector<bool> exists(30, false), was(30, false);
	vector<vector<int>> E(30);
	for (int i = 1; i <= n; ++i) {
		int last = -1;
		for (int j = 0; j < 30; ++j) {
			if ((a[i] >> j) & 1) {
				if (last != -1) {
					E[last].push_back(j);
					E[j].push_back(last);
				}
				exists[j] = true;
				last = j;
			}
		}
	}
	vector<int> ans, now;
	for (int i = 0; i < 30; ++i) {
		if (exists[i]) {
			if (!was[i]) {
				now.clear();
				DFS(i, was, E, now);
				ans.push_back(-1);
			}
		}
	}

	return ans.size() == 1;
}

int main() {
	int tc;
	scanf("%i",&tc);
	while (tc--) {
		int n;
		scanf("%i", &n);
		vector<bool> exists(30, false), was(30, false);
		vector<vector<int>> E(30);
		//vector<int> zero;
		int sol = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%i", &a[i]);
			if (a[i] == 0) {
				a[i]++;
				sol++;
			}
			int last = -1;
			for (int j = 0; j < 30; ++j) {
				if ((a[i] >> j) & 1) {
					if (last != -1) {
						E[last].push_back(j);
						E[j].push_back(last);
					}
					exists[j] = true;
					last = j;
				}
			}
			//if (a[i] == 0)
			//	zero.push_back(i);
		}
		vector<int> ans, now, cand;
		for (int i = 0; i < 30; ++i) {
			if (exists[i]) {
				if (!was[i]) {
					now.clear();
					cand.clear();
					DFS(i, was, E, now);
					int best1 = -1, best2 = -1, best3 = -1;
					for (int j = 1; j <= n; ++j) {
						bool ok = false;
						for (int k : now)
							if ((a[j] >> k) & 1)
								ok = true;
						if (!ok)
							continue;

						cand.push_back(j);

						if (!((a[j] >> i) & 1))
							best1 = j;
						else if (a[j] != (1 << i))
							best2 = j;
						else if (best == -1)
							best3 = j;
					}
					if (best1 == -1 && best2 == -1)
						ans.push_back(best3);
					else if (best1 == -1)
						ans.push_back(best2);
					else
						ans.push_back(best1);
				}
			}
		}

		/*if (ans.size() == 0) {
			printf("%i\n", n);
			for(int i = 1; i <= n; ++i)
				printf("1 ");
			printf("\n");
			continue;
		}

		if (ans.size() == 1 && zero.size() == 0) {
			printf("0\n");
			for (int i = 1; i <= n; ++i)
				printf("%i ",a[i]);
			printf("\n");
			continue;
		}

		if (ans.size() == 1) {
			int sol = zero.size();
			if (!exists[0]) {
				sol++;
				for (int i = 1; i <= n; ++i) {
					if (a[i] != 0) {
						a[i]++;
						break;
					}
				}
			}
			printf("%i\n",sol);
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 0)
					printf("1 ");
				else
					printf("%i ",a[i]);
			}
			printf("\n");
			continue;
		}*/

		/*
		//int sol = 1 + zero.size();
		a[ans.back()]--;
		sol++;
		//for (int i : zero)
		//	a[i]++;

		{
			vector<bool> exists(30, false), was(30, false);
			vector<vector<int>> E(30);
			vector<int> zero;
			for (int i = 1; i <= n; ++i) {
				int last = -1;
				for (int j = 0; j < 30; ++j) {
					if ((a[i] >> j) & 1) {
						if (last != -1) {
							E[last].push_back(j);
							E[j].push_back(last);
						}
						exists[j] = true;
						last = j;
					}
				}
				if (a[i] == 0)
					zero.push_back(i);
			}
			vector<int> ans;
			for (int i = 0; i < 30; ++i) {
				if (exists[i]) {
					if (!was[i]) {
						vector<int> now;
						DFS(i, was, E, now);
						int best = -1;
						for (int j = 1; j <= n; ++j) {
							bool ok = false;
							for (int k : now)
								if ((a[j] >> k) & 1)
									ok = true;
							if (!ok)
								continue;

							//if (!((a[j] >> i) & 1))
							if (a[j] != (1 << i))
								best = j;
							else if (best == -1)
								best = j;
						}
						ans.push_back(best);
					}
				}
			}
			assert(ans.size() == 1 || ans.size() == 2);
			if (ans.size() > 1) {
				sol++;
				a[ans.back()]++;
			}
		}*/

		if (ans.size() != 1) {
			best = -1;
			bool super = false;
			for (int c : cand) {
				a[c]++;
				if (Try(n)) {
					super = true;
					break;
				}
				a[c]-=2;
				if (Try(n)) {
					super = true;
					break;
				}
				a[c]++;
			}

			if (super) {
				sol++;
			} else {
				a[ans.back()]--;
				sol++;
				vector<bool> exists(30, false), was(30, false);
				vector<vector<int>> E(30);
				vector<int> zero;
				for (int i = 1; i <= n; ++i) {
					int last = -1;
					for (int j = 0; j < 30; ++j) {
						if ((a[i] >> j) & 1) {
							if (last != -1) {
								E[last].push_back(j);
								E[j].push_back(last);
							}
							exists[j] = true;
							last = j;
						}
					}
					if (a[i] == 0)
						zero.push_back(i);
				}
				vector<int> ans;
				for (int i = 0; i < 30; ++i) {
					if (exists[i]) {
						if (!was[i]) {
							vector<int> now;
							DFS(i, was, E, now);
							int best = -1;
							for (int j = 1; j <= n; ++j) {
								bool ok = false;
								for (int k : now)
									if ((a[j] >> k) & 1)
										ok = true;
								if (!ok)
									continue;

								//if (!((a[j] >> i) & 1))
								if (a[j] != (1 << i))
									best = j;
								else if (best == -1)
									best = j;
							}
							ans.push_back(best);
						}
					}
				}
				assert(ans.size() == 1 || ans.size() == 2);
				if (ans.size() > 1) {
					sol++;
					a[ans.back()]++;
				}
			}
		}

		printf("%i\n", sol);
		for (int i = 1; i <= n; ++i)
			printf("%i ", a[i]);
		printf("\n");
	}
    return 0;
}