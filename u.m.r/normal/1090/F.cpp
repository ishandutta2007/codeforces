#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n;
int o[5];
int ans[MAXN];
int a[MAXN];

int rank2o[5];
int o2rank[5];
int kanon[4] = {4, 3, 1, 0};

ll query(int p, int q, int r) {
#ifdef UMR
    ll max_v = max(max(a[o[p]], a[o[q]]), a[o[r]]);
    ll min_v = min(min(a[o[p]], a[o[q]]), a[o[r]]);
    // std::cout << "query " << o[p] << ' ' << o[q] << ' ' << o[r] << "     " << max_v << ' ' << min_v << endl;
    return max_v + min_v;
#else
    printf("? %d %d %d\n", o[p], o[q], o[r]);
    fflush(stdout);
    ll x = 0;
    scanf("%lld", &x);
    return x;
#endif
}

struct tp {
    int x[3];
}; 

vector<int> intersect(const tp& a, const tp& b) {
    vector<int> u;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) if (a.x[i] == b.x[j]) {
            u.push_back(a.x[i]);
        }
    }
    return u;
}

struct itp {
    ll res;
    tp v;
};

ll val[10];

void gao() {
    vector<itp> f;
#define add(p, q, r) { \
    itp rtp; \
    rtp.v.x[0] = p, rtp.v.x[1] = q, rtp.v.x[2] = r; \
    rtp.res = query(p, q, r); \
    f.push_back(rtp); }
    add(0, 1, 2); add(0, 1, 3); add(0, 1, 4);
    add(0, 2, 3); add(0, 2, 4); add(0, 3, 4);
    add(1, 2, 3); add(1, 2, 4); add(1, 3, 4);
    add(2, 3, 4);
#undef add
    sort(f.begin(), f.end(), [](const itp&a, const itp&b) {
        return a.res < b.res;
    });
    // 0   12   3456   78   9
    ll s13 = f[0].res;
    ll s14 = f[1].res;
    ll s35 = f[9].res;
    ll s25 = f[8].res;
    ll s15 = f[4].res;
    ll s24 = f[3].res + f[4].res + f[5].res + f[6].res - 3 * s15;
    ll s135 = (s13 + s15 + s35) / 2;
    val[1] = s135 - s35;
    val[3] = s135 - s15;
    val[5] = s135 - s13;
    val[2] = s25 - val[5];
    val[4] = s14 - val[1];
    for (int i = 0; i < 5; i++) {
        o2rank[i] = i;
    }
    do {
        int flag = 1;
        for (int i = 0; i < 10; i++) {
            int p = o2rank[f[i].v.x[0]] + 1;
            int q = o2rank[f[i].v.x[1]] + 1;
            int r = o2rank[f[i].v.x[2]] + 1;
            if (max(max(val[p], val[q]), val[r]) + min(min(val[p], val[q]), val[r]) != f[i].res) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < 5; i++) {
                ans[o[i]] = val[o2rank[i] + 1];
            }
            return ;
        }
    } while (next_permutation(o2rank, o2rank + 5));

    // ll min_v = f[0].res, max_v = f.back().res;
    // for (int i = 0; i < f.size() && f[i].res == min_v; i++) {
    //     for (int j = 9; j >= 0 && f[j].res == max_v; j++) {
    //         auto v = intersect(f[i].v, f[j].v);
    //         if (v.size() == 1) {
    //             rank2o[2] = v[0];
    //             goto Keke;
    //         }
    //     }
    // }
    // Keke:
    // vector<itp> g;
    // for (int i = 0; i < 10; i++) {
    //     int flag = 1;
    //     for (int j = 0; j < 3; j++)
    //         if (f[i].v.x[j] == rank2o[2]) flag = 0;
    //     if (flag) {
    //         g.push_back(f[i]);
    //     }
    // }
    // assert(g.size() == 4);
    // ll sm = 0;
    // for (int i = 0; i < 4; i++) {
    //     int v = 10 - rank2o[2];
    //     for (int j = 0; j < 3; j++) {
    //         v -= g[i].v.x[j];
    //     }
    //     rank2o[kanon[i]] = v;
    //     sm += g[i].res;
    // }
    // sm /= 3;
    // for (int i = 0; i < 4; i++) {
    //     ans[o[rank2o[kanon[i]]]] = sm - g[i].res;
    // }
    // ans[o[rank2o[2]]] = min_v - ans[o[rank2o[0]]] - ans[o[rank2o[1]]];
}

void solve(int casi){
    scanf("%d", &n);
#ifdef UMR
    srand(time(NULL));
    for (int i = 1; i <= n; i++) {
        a[i] = rand() % 10;
    }
    // n = 5; a[1] = 1, a[2] = 0, a[3] = 2, a[4] = 1, a[5] = 3;
    for (int i = 1; i <= n; i++) std::cout << a[i] << ' '; std::cout << endl;
#endif
    for (int i = 1; i <= n / 5; i++) {
        for (int j = 0; j < 5; j++) {
            o[j] = i * 5 - j;
        }
        gao();
    }
    if (n % 5 != 0) {
        for (int j = 0; j < 5; j++) {
            o[j] = n - j;
        }
        gao();
    }
    printf("!");
    for (int i = 1; i <= n; i++) {
        printf(" %d", ans[i]);
    }
    puts("");
    fflush(stdout);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}