#include <iostream>
#include <algorithm>
#include <vector>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")
#include <cmath>

using namespace std;

struct Node{
	int x = 0;
	Node *left = 0, *right = 0;
	Node() {}
};

const int MAX_N = 1 << 19, K = 20;
int sparse2[K][MAX_N];
int suff[MAX_N], whereis[MAX_N], eq_class[MAX_N], n_eq_class[MAX_N], dp[MAX_N], dpl[MAX_N], dpr[MAX_N], lcp[MAX_N];
vector <int> cnt[MAX_N];
Node *head[MAX_N];
string s;
int n;

void relax(Node *t) {
	t->x = t->left->x + t->right->x;
}

Node *build_do(int l, int r) {
	Node *t = new Node();
	if (l == r) return t;
	int m = (l + r) / 2;
	t->left = build_do(l, m);
	t->right = build_do(m + 1, r);
	return t;
}

Node *update(Node *t, int l, int r, int need) {
	Node *new_t = new Node();
	new_t->left = t->left;
	new_t->right = t->right;
	if (l == r) {
		new_t->x = 1;
		return new_t;
	}
	int m = (l + r) / 2;
	if (need <= m) new_t->left = update(t->left, l, m, need);
	else new_t->right = update(t->right, m + 1, r, need);
	relax(new_t);
	return new_t;
}

int find_nearest(Node *tl, Node *tr, int l, int r, int pos) {
	if (r < pos) return -1;
	if (l == r) {
		if (tl->x != tr->x) return l;
		return -1;
	}
	if (pos <= l) {
		if (tl->x == tr->x) return -1;
		int m = (l + r) / 2;
		if (tl->left->x != tr->left->x) return find_nearest(tl->left, tr->left, l, m, pos);
		return find_nearest(tl->right, tr->right, m + 1, r, pos);
	}
	int m = (l + r) / 2;
	int ans = find_nearest(tl->left, tr->left, l, m, pos);
	if (ans != -1) return ans;
	return find_nearest(tl->right, tr->right, m + 1, r, pos);
}

bool cmp(int a, int b) {
    return (s[a] < s[b]);
}

void build_sparse() {
    for (int i = 0; i < MAX_N; i++) sparse2[0][i] = lcp[i];
    for (int i = 1; i < K; i++) {
        for (int l = 0; l < MAX_N; l++) {
            int r = l + (1 << i);
            if (r >= MAX_N) break;
            int m = l + (1 << (i - 1));
            sparse2[i][l] = min(sparse2[i - 1][l], sparse2[i - 1][m]);
        }
    }
}

int get2(int l, int r) {
    if (r < l) return 0;
    int len = r - l + 1;
    int lg = 31 - __builtin_clz(len);
    int d = (1 << lg);
    return min(sparse2[lg][l], sparse2[lg][r - d + 1]);
}

bool check(int l, int r, int rr) {
    if (r >= n - 2) return 0;
    int now = whereis[l];
    int l_g = now, r_g = n + 1, m;
    int best = -1;
    while (r_g - l_g > 1) {
        m = (l_g + r_g) / 2;
        if (get2(now, m - 1) > r - l) l_g = m;
        else r_g = m;
    }
	int nearest = find_nearest(head[now - 1], head[l_g], 1, MAX_N, rr + 1);
    if (nearest != -1) best = max(best, dp[nearest]);
    l_g = 0, r_g = now;
    while (r_g - l_g > 1) {
        m = (l_g + r_g) / 2;
        if (get2(m, now - 1) > r - l) r_g = m;
        else l_g = m;
    }
	nearest = find_nearest(head[r_g - 1], head[now], 1, MAX_N, rr + 1);
    if (nearest != -1) best = max(best, dp[nearest]);
    return (best >= (r - l + 1));
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    cin >> s;
    s += "#";
    n++;
    for (int i = 0; i < n; i++) suff[i] = i;
    sort(suff, suff + n, cmp);
    eq_class[suff[0]] = 0;
    for (int i = 1; i < n; i++) {
        eq_class[suff[i]] = eq_class[suff[i - 1]];
        if (s[suff[i]] != s[suff[i - 1]]) eq_class[suff[i]]++;
    }
    for (int i = 0; i < K; i++) {
        if ((1 << i) >= n) break;
        for (int j = 0; j <= n; j++) cnt[j].clear();
        for (int j = 0; j < n; j++) {
            int left = suff[j] - (1 << i);
            if (left < 0) left += n;
            cnt[eq_class[left]].push_back(left);
        }
        int tail = 0;
        for (int j = 0; j <= n; j++) {
            for (int elem : cnt[j]) {
                suff[tail++] = elem;
            }
        }
        n_eq_class[suff[0]] = 0;
        for (int j = 1; j < n; j++) {
            int right = (suff[j] + (1 << i)) % n;
            int right2 = (suff[j - 1] + (1 << i)) % n;
            n_eq_class[suff[j]] = n_eq_class[suff[j - 1]];
            if (eq_class[suff[j]] != eq_class[suff[j - 1]] || eq_class[right] != eq_class[right2]) n_eq_class[suff[j]]++;
        }
        for (int j = 0; j < n; j++) {
            eq_class[j] = n_eq_class[j];
        }
    }
    for (int i = 0; i < n; i++) {
        whereis[suff[i]] = i;
    }
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (whereis[i] == n - 1) {
            len = 0;
            continue;
        }
        int a = i, b = suff[whereis[i] + 1];
        while (s[a + len] == s[b + len]) len++;
        lcp[whereis[i]] = len;
        if (len != 0) len--;
    }
	head[0] = build_do(1, MAX_N);
	for (int i = 1; i < n; i++) {
		if (suff[i] != 0) head[i] = update(head[i - 1], 1, MAX_N, suff[i]);
		else head[i] = head[i - 1];
	}
    build_sparse();
    dp[n - 1] = 0;
    dp[n - 2] = 1;
	dpl[n - 2] = 1;
    int ans = 1;
    for (int i = n - 3; i >= 0; i--) {
        dp[i] = 1;
        int l = 1, r = 2 * ceil(sqrt(n - i)) + 3, m;
		dpr[i] = dpl[i + 1];
		if (check(i + 1, i + dpr[i], i + dpr[i])) dpr[i]++;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (check(i, i + m - 2, i + m - 1)) l = m;
            else r = m;
        }
        dpl[i] = l;
		dp[i] = max(dpl[i], dpr[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}