#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 1e5 + 10;
int cnt[N];
pair<int, int> t[4 * N];

void build(int v, int l, int r) {
    if (l == r) {
        t[v] = {l * cnt[l], cnt[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = {t[2 * v].first + t[2 * v + 1].first, t[2 * v].second + t[2 * v + 1].second};
}

void update(int v, int l, int r, int need, int delta) {
    if (l == r) {
        t[v].first += need * delta;
        t[v].second += delta;
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        update(2 * v, l, mid, need, delta);
    } else {
        update(2 * v + 1, mid + 1, r, need, delta);
    }
    t[v] = {t[2 * v].first + t[2 * v + 1].first, t[2 * v].second + t[2 * v + 1].second};
}

int get(int need, int n) {
    if (need == 0) {
        return 0;
    }
    int l = 1, r = n, v = 1, sum = 0, diff = 0;
    while (l != r) {
        int mid = (l + r) / 2;
        if (sum + t[2 * v].first >= need) {
            r = mid;
            v = 2 * v;
        } else {
            sum += t[2 * v].first;
            diff += t[2 * v].second;
            l = mid + 1;
            v = 2 * v + 1;
        }
    }
    return diff + (need - sum) / (t[v].first / t[v].second);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        k = min(k, n);
        map<int, int> cnt_elem;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt_elem[x]++;
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
        }
        for (auto [_, val] : cnt_elem) {
            cnt[val]++;
        }
        build(1, 1, n);
        int have = 0, cnt_diff = cnt_elem.size(), answer = cnt_diff - get(k, n);
        //cout << answer << endl;
        for (int mex = 1; mex <= n; mex++) {
            if (cnt_elem.count(mex - 1)) {
                have++;
                update(1, 1, n, cnt_elem[mex - 1], -1);
                cnt_diff--;
            }
            if (mex - have > k) {
                continue;
            }
            int killed = get(min(k, t[1].first), n);
            answer = min(answer, cnt_diff - killed);
            //cout << mex << ' ' << cnt_diff << ' ' << killed << ' ' << answer << endl;
        }
        cout << answer << endl;
    }
    return 0;
}