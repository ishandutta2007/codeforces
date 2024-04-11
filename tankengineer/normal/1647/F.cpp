#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 500005, UP = 1, DOWN = -1, NONE = 0;

int n;

int a[N];

int ans;

int pre[N], post[N];

pair<int, int> dpf[N], dpb[N];

struct BQ {

	int size, direction, mins, maxs;

	BQ() {
		size = 0;
		direction = NONE;
	}

	void push_front(int x) {
		if (size == 0) {
			size = 1;
			mins = maxs = x;
		} else if (size == 1) {
			size = 2;
			if (x < mins) {
				direction = UP;
				mins = x;
			} else {
				direction = DOWN;
				maxs = x;
			}
		} else {
			++size;
			if (direction == UP) {
				if (x < mins) {
					mins = x;
				} else {
					direction = NONE;
				}
			} else if (direction == DOWN) {
				if (x > maxs) {
					maxs = x;
				} else {
					direction = NONE;
				}
			}
		}
	}

	void push_back(int x) {
		if (size == 0) {
			size = 1;
			mins = maxs = x;
		} else if (size == 1) {
			size = 2;
			if (x < mins) {
				direction = DOWN;
				mins = x;
			} else {
				direction = UP;
				maxs = x;
			}
		} else {
			++size;
			if (direction == DOWN) {
				if (x < mins) {
					mins = x;
				} else {
					direction = NONE;
				}
			} else if (direction == UP) {
				if (x > maxs) {
					maxs = x;
				} else {
					direction = NONE;
				}
			}
		}
	}

	bool ismonoup() const {
		return size < 2 || direction == UP;
	}
	
	bool ismonodown() const {
		return size < 2 || direction == DOWN;
	}
};

bool solveP(vector<pair<int, int> > &rnk, int l, int r, int lub, int llb, int rub, int rlb) {
	assert(lub >= rlb && llb <= rub);
	if (l > r) {
		return true;
	}
	assert (rnk.size() >= r - l + 1);
	while (rnk.back().second < l || rnk.back().second > r) {
		rnk.pop_back();
	}
	int mini = rnk.back().second;
	if ((a[mini] >= llb && pre[mini] <= l) && (a[mini] >= rlb && r <= post[mini])) {
		return true;
	} else if (a[mini] >= llb && pre[mini] <= l) {
		int nlub = mini == l ? lub : a[mini - 1];
		return nlub > rlb && solveP(rnk, mini + 1, r, nlub, a[mini], rub, rlb);
	} else if (a[mini] >= rlb && r <= post[mini]) {
		int nrub = mini == r ? rub : a[mini + 1];
		return nrub > llb && solveP(rnk, l, mini - 1, lub, llb, nrub, a[mini]);
	} else {
		return false;
	}
}

bool solve(int l, int r, int lub, int llb, int rub, int rlb) {
	assert(lub >= rlb && llb <= rub);
	if (l > r) {
		return true;
	}
	vector<pair<int, int> > b(r - l + 1);
	for (int i = l; i <= r; ++i) {
		b[i - l] = make_pair(-a[i], i);
	}	
	sort(b.begin(), b.end());
	return solveP(b, l, r, lub, llb, rub, rlb);
}

int main() {
	scanf("%d", &n);
	vector<pair<int, int> > rnk;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		rnk.push_back(make_pair(-a[i], i));
	}
	sort(rnk.begin(), rnk.end());
	for (int i = 0; i < n; ++i) {
		pre[i] = i;
		if (i && a[i - 1] > a[i]) {
			pre[i] = pre[i - 1];
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		post[i] = i;
		if (i + 1 < n && a[i] < a[i + 1]) {
			post[i] = post[i + 1];
		}
	}
	pair<int, int> invalid = make_pair(-1, -1);
	dpf[0] = make_pair(0, 0);
	for (int i = 0; i < n; ++i) {
		if (dpf[i] == invalid) {
			dpf[i + 1] = invalid;
		} else {
			if (a[i] > dpf[i].first) {
				dpf[i + 1] = make_pair(a[i], dpf[i].second);
			} else if (a[i] > dpf[i].second) {
				dpf[i + 1] = make_pair(dpf[i].first, a[i]);
			} else {
				dpf[i + 1] = invalid;
			}
		}
	}
	dpb[n] = make_pair(0, 0);
	for (int i = n - 1; i >= 0; --i) {
		if (dpb[i + 1] == invalid) {
			dpb[i] = invalid;
		} else {
			if (a[i] > dpb[i + 1].first) {
				dpb[i] = make_pair(a[i], dpb[i + 1].second);
			} else if (a[i] > dpb[i + 1].second) {
				dpb[i] = make_pair(dpb[i + 1].first, a[i]);
			} else {
				dpb[i] = invalid;
			}
		}
	}
	ans = 0;
	BQ q;
	int maxi = rnk[0].second, l = maxi, r = maxi;
	for (int _ = 1; _ < n; ++_) {
		int i = rnk[_].second;
		//cout << _ << ' ' << i << ' ' << a[i] << endl;
		if (i < l) {
			if (dpf[i] != invalid && dpb[r + 1] != invalid && q.ismonodown() &&
				(q.size == 0 || q.mins > dpb[r + 1].second)) {
				int lub = a[i], llb = dpf[i].second,
					rub = a[l], rlb = q.size == 0 ? dpb[r + 1].second : q.maxs;
				if (solve(i + 1, l - 1, lub, llb, rub, rlb)) {
					++ans;
				}
			}
			while (i < l) {
				--l;
				if (a[l] < a[i]) {
					q.push_front(a[l]);
				}
			}
		} else if (r < i) {
			if (dpf[l] != invalid && dpb[i + 1] != invalid && q.ismonoup() &&
				(q.size == 0 || q.mins > dpf[l].second)) {
				int lub = a[r], llb = q.size == 0 ? dpf[l].second : q.maxs,
					rub = a[i], rlb = dpb[i + 1].second;
				if (solve(r + 1, i - 1, lub, llb, rub, rlb)) {
					++ans;
				}
			}
			while (r < i) {
				++r;
				if (a[r] < a[i]) {
					q.push_back(a[r]);
				}
			}
		} else {
			if (i < maxi) {
				if (dpf[i + 1] != invalid && dpb[maxi] != invalid) {
					bool valid = true;
					int cur = a[i];
					for (int j = i + 1; j < maxi && valid; ++j) {
						if (a[j] > a[i]) {
							continue;
						} else if (a[j] > cur) {
							valid = false;
						} else {
							cur = a[j];
						}
					}
					if (cur < dpb[maxi].second) {
						valid = false;
					}
					if (valid) {
						++ans;
					}
				}
			} else {
				if (dpf[maxi] != invalid && dpb[i] != invalid) {
					bool valid = true;
					int cur = a[i];
					for (int j = i - 1; j > maxi && valid; --j) {
						if (a[j] > a[i]) {
							continue;
						} else if (a[j] > cur) {
							valid = false;
						} else {
							cur = a[j];
						}
					}
					if (cur < dpf[maxi].second) {
						valid = false;
					}
					if (valid) {
						++ans;
					}
				}
			}
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}