#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

using pii = std::pair <int, int>;
std::mt19937 rnd(19971109);

struct Treap{
#define ls(u) (ch[(u)][0])
#define rs(u) (ch[(u)][1])

    int root, node_sz;
    int ch[N][2];
    ll key[N], sz[N], cnt[N], sum[N];
    unsigned prior[N];

    void clear(int x){
        ls(x) = rs(x) = 0;
        key[x] = sz[x] = cnt[x] = sum[x] = 0;
    }

    void init(){
        node_sz = 0;
    }

    int newnode(ll x){
        clear(++ node_sz);
        key[node_sz] = x;
        prior[node_sz] = rnd();
        return node_sz;
    }

    void pull(int u){
        sz[u] = sz[ls(u)] + sz[rs(u)] + cnt[u];
        sum[u] = sum[ls(u)] + sum[rs(u)] + cnt[u] * key[u];
    }

    pii split(int p, ll u){
        if (!p) return {0, 0};
        if (key[p] <= u){
            pii ret = split(rs(p), u);
            rs(p) = ret.first;
            pull(p);
            return {p, ret.second};
        }
        pii ret = split(ls(p), u);
        ls(p) = ret.second;
        pull(p);
        return {ret.first, p};
    }

    int merge(int u, int v){
        if (!u || !v) return u ^ v;
        if (prior[u] > prior[v]){
            rs(u) = merge(rs(u), v);
            pull(u);
            return u;
        }
        ls(v) = merge(u, ls(v));
        pull(v);
        return v;
    }

    ll begin(){
        int p = root;
        while (ls(p)) p = ls(p);
        return key[p];
    }

    ll end(){
        int p = root;
        while (rs(p)) p = rs(p);
        return key[p];
    }

    int right(int p){
        while (rs(p)) p = rs(p);
        return p;
    }

    void insert(ll x){
        pii pair = split(root, x);
        int p = right(pair.first);
        pii pair1;
        if (p && key[p] == x){
            pair1 = split(pair.first, x - 1);
        }
        else{
            pair1 = {pair.first, newnode(x)};
        }
        ++ cnt[pair1.second], ++ sz[pair1.second];
        sum[pair1.second] += x;
        root = merge(pair1.first, pair1.second);
        root = merge(root, pair.second);
    }

    void erase(ll x){
        pii pair = split(root, x);
        pii pair1 = split(pair.first, x - 1);
        if (!pair1.second || cnt[pair1.second] == 1){
            root = merge(pair1.first, pair.second);
            return;
        }
        -- cnt[pair1.second], -- sz[pair1.second];
        sum[pair1.second] -= x;
        root = merge(pair1.first, pair1.second);
        root = merge(root, pair.second);
    }

    ll prev(int u, ll x){
        if (!u) return LLONG_MIN;
        if (x <= key[u]) return prev(ls(u), x);
        ll ret = prev(rs(u), x);
        return ret == LLONG_MIN ? key[u] : ret;
    }

    ll prev_non_strict(int u, ll x){
        if (!u) return LLONG_MIN;
        if (x < key[u]) return prev_non_strict(ls(u), x);
        if (x == key[u]) return x;
        ll ret = prev_non_strict(rs(u), x);
        return ret == LLONG_MIN ? key[u] : ret;
    }

    ll next(int u, ll x){
        if (!u) return LLONG_MAX;
        if (x >= key[u]) return next(rs(u), x);
        ll ret = next(ls(u), x);
        return ret == LLONG_MAX ? key[u] : ret;
    }

    ll get_sum(int u, ll x){
        if (!u) return 0;
        if (x > key[u]){
            return get_sum(rs(u), x);
        }
        return get_sum(ls(u), x) + cnt[u] * key[u] + sum[rs(u)];
    }

    ll get_cnt(int u, ll x){
        if (!u) return 0;
        if (x > key[u]){
            return get_cnt(rs(u), x);
        }
        return get_cnt(ls(u), x) + cnt[u] + sz[rs(u)];
    }
};

Treap treap1, treap2;
ll a[N], b[N];

int main(){
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
        treap1.insert(a[i]);
        sum1 += a[i];
    }
    for (int i = 0; i < m; ++ i){
        scanf("%lld", &b[i]);
        treap2.insert(b[i]);
        sum2 += b[i];
    }
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int pos;
            ll x;
            scanf("%d%lld", &pos, &x);
            -- pos;
            sum1 -= a[pos];
            treap1.erase(a[pos]);
            a[pos] = x;
            treap1.insert(a[pos]);
            sum1 += a[pos];
            continue;
        }
        if (type == 2){
            int pos;
            ll x;
            scanf("%d%lld", &pos, &x);
            -- pos;
            sum2 -= b[pos];
            treap2.erase(b[pos]);
            b[pos] = x;
            treap2.insert(b[pos]);
            sum2 += b[pos];
            continue;
        }
        ll k;
        scanf("%lld", &k);
        ll min1 = treap1.begin(), min2 = treap2.begin();
        ll global_min = std::min(min1, min2);
        ll ans = LLONG_MIN;
        {
            ll x = global_min + k;
            ll u = treap1.prev_non_strict(treap1.root, x);
            if (u != LLONG_MIN){
                ll first = u - k;
                ll value = (sum1 - n * first) - (sum2 - m * first);
                ans = std::max(ans, value);
                first = min1 - k;
                value = (sum1 - n * first) - (sum2 - m * first);
                ans = std::max(ans, value);
            }
            u = treap2.prev_non_strict(treap2.root, x);
            if (u != LLONG_MIN){
                ll first = u - k;
                ll value = (sum1 - n * first) - (sum2 - m * first);
                ans = std::max(ans, value);
                first = min2 - k;
                value = (sum1 - n * first) - (sum2 - m * first);
                ans = std::max(ans, value);
            }
        }
        {
            ll x = global_min + k;
            ll u = treap2.next(treap2.root, x);
            if (u != LLONG_MAX){
                ll first = treap2.end() - k;
                if (first > global_min){
                    ll value = sum1 - n * global_min;
                    ll sum = treap2.get_sum(treap2.root, first);
                    ll cnt = treap2.get_cnt(treap2.root, first);
                    value -= sum - cnt * first;
                    ans = std::max(ans, value);
                }
            }
        }
        {
            ll a1 = treap2.end() + k;
            ll first = treap1.next(treap1.root, a1);
            if (first != LLONG_MAX && first - k > global_min){
                ll value = sum1 - n * global_min;

                // fix first value
                value -= first - global_min;
                value += k;

                first -= k;
                ll sum = treap2.get_sum(treap2.root, first);
                ll cnt = treap2.get_cnt(treap2.root, first);
                value -= sum - cnt * first;
                ans = std::max(ans, value);
            }
            first = treap1.prev_non_strict(treap1.root, a1);
            if (first != LLONG_MIN && first - k > global_min){
                ll value = sum1 - n * global_min;

                // fix first value
                value -= first - global_min;
                value += k;

                first -= k;
                ll sum = treap2.get_sum(treap2.root, first);
                ll cnt = treap2.get_cnt(treap2.root, first);
                value -= sum - cnt * first;
                ans = std::max(ans, value);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

// #include <bits/stdc++.h>
//
// const int N = 20;
// int a[N], b[N];
//
// int main(){
//     std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
//     int n, m;
//     scanf("%d%d", &n, &m);
//     printf("a = ");
//     for (int i = 0; i < n; ++ i){
//         a[i] = rnd() % 10;
//         // scanf("%d", &a[i]);
//         printf("%d ", a[i]);
//     }
//     puts("");
//     printf("b = ");
//     for (int i = 0; i < m; ++ i){
//         b[i] = rnd() % 10;
//         // scanf("%d", &b[i]);
//         printf("%d ", b[i]);
//     }
//     std::sort(a, a + n);
//     std::sort(b, b + m, std::greater <int>());
//     puts("");
//     std::vector <int> perm(n + m);
//     for (int i = 0; i < n + m; ++ i){
//         perm[i] = i;
//     }
//     const int MAX = 20;
//     std::vector <int> max(MAX, INT_MIN);
//     std::vector <std::vector <int>> pos(MAX);
//     do{
//         auto get = [&](int pos){
//             return pos < n ? b[pos] : a[pos - m];
//         };
//         for (int i = 0; i < MAX; ++ i){
//             int pre = get(perm[0]), cur = i;
//             int ans = 0;
//             for (int j = 0; j < n + m; ++ j){
//                 int x = get(perm[j]);
//                 cur = std::max(cur + x - pre, 0);
//                 ans += perm[j] < m ? -cur : cur;
//                 pre = x;
//             }
//             if (max[i] < ans){
//                 max[i] = ans;
//                 pos[i] = perm;
//             }
//             max[i] = std::max(max[i], ans);
//         }
//     }
//     while (std::next_permutation(perm.begin(), perm.end()));
//     for (int i = 0; i < MAX; ++ i){
//         printf("%d = %d: ", i, max[i]);
//         for (auto u : pos[i]){
//             printf("%d%c ", u < n ? b[u] : a[u - m], u < m ? 'b' : 'a');
//         }
//         puts("");
//     }
//     return 0;
// }