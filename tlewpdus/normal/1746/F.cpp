#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

const int T = 30;

int N, Q;
int A[300100];
ll mp[600100];

struct BIT {
    ll tree[300100];
    void init() { memset(tree, 0, sizeof(tree)); }
    void upd(int idx, ll val) {
        idx++;
        while (idx <= N) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
    ll getv(int idx) {
        idx++;
        ll res = 0;
        while (idx) {
            res += tree[idx];
            idx &= idx - 1;
        }
        return res;
    }
} bit;

struct Query {
    int l, r, x;
} query[300100];

int B[300100];
bool mang[300100];

int main() {
    scanf("%d%d", &N, &Q);
    vector<int> comp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        // A[i] = i + 1;
        comp.push_back(A[i]);
    }
    for (int i = 0; i < Q; i++) {
        int t;
        scanf("%d", &t);
        // t = rand() % 2 + 1;
        if (t == 1) {
            int x, k;
            scanf("%d%d", &x, &k);
            x--;
            // x = rand() % N;
            // k = N + i + 1;
            query[i] = {x, -1, k};
            comp.push_back(k);
        } else {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            --x;
            --y;
            // x = rand() % N;
            // y = rand() % N;
            // if (x > y) swap(x, y);
            // k = rand() % 2 + 2;
            query[i] = {x, y, k};
        }
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < N; i++) {
        A[i] = lower_bound(comp.begin(), comp.end(), A[i]) - comp.begin();
        B[i] = A[i];
    }
    for (int i = 0; i < Q; i++) {
        if (query[i].r == -1) {
            query[i].x = lower_bound(comp.begin(), comp.end(), query[i].x) -
                         comp.begin();
        }
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ll> distribution(1, 1e10);
    for (int t = 0; t < T; t++) {
        bit.init();
        for (int i = 0; i < N; i++) A[i] = B[i];
        for (int i = 0; i < comp.size(); i++) {
            mp[i] = distribution(rng);
        }
        for (int i = 0; i < N; i++) {
            bit.upd(i, mp[A[i]]);
        }
        for (int i = 0; i < Q; i++) {
            if (query[i].r == -1) {
                int l = query[i].l;
                int x = query[i].x;
                bit.upd(l, mp[x] - mp[A[l]]);
                A[l] = x;
            } else if (!mang[i]) {
                int l = query[i].l;
                int r = query[i].r;
                int k = query[i].x;
                if ((r - l + 1) % k != 0) {
                    mang[i] = true;
                } else {
                    if ((bit.getv(r) - bit.getv(l - 1)) % k != 0) {
                        // printf("%d!\n", i);
                        // printf("%d, %d, %d: %lld\n", l, r, k,
                        //        bit.getv(r) - bit.getv(l - 1));
                        mang[i] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        if (query[i].r != -1) {
            puts(mang[i] ? "NO" : "YES");
        }
    }

    return 0;
}