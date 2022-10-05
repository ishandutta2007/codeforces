#include<bits/stdc++.h>

typedef long long ll;
const int N = 100010;
const int M = N << 4;
const int moder = 998244353;
const int root = 3;
const int invroot = (moder + 1) / root;
const int MAX = 20;

int w[2][1 << MAX];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void init(){
    w[0][0] = w[1][0] = 1;
    w[0][1] = powermod(root, (moder - 1) >> MAX);
    for (int i = 2; i < (1 << MAX); ++i){
        w[0][i] = 1ll * w[0][i - 1] * w[0][1] % moder;
    }
    for (int i = 1; i < (1 << MAX); ++i){
        w[1][(1 << MAX) - i] = w[0][i];
    }
}

void NTT(std::vector <int> &a, int len, int type){
    for(int i = 1, j = 0; i < len - 1; ++i){
        for(int s = len; j ^= (s >>= 1), ~j & s; )
            ;
        if(i < j){
            std::swap(a[i], a[j]);
        }
    }
    for (int i = 2, d = 1; i <= len; i <<= 1, ++d){
        for (int j = 0; j < len; j += i){
            auto u = a.begin() + j;
            for (int k = 0; k < i / 2; ++k){
                int t = 1ll * w[type][k << (MAX - d)] * u[k + i / 2] % moder;
                u[k + i / 2] = u[k] - t + (u[k] - t < 0 ? moder : 0);
                ll tmp = (ll) u[k] + t;
                tmp -= tmp >= moder ? moder : 0;
                u[k] = tmp;
            }
        }
    }
    if (type == 0) return;
    int inv = powermod(len, moder - 2);
    for (int i = 0; i < len; ++i){
        a[i] = 1ll * a[i] * inv % moder;
    }
}

struct poly{
    std::vector <int> a;
    int len;
    
    poly() : len(-1) {}
    poly(int len) : len(len) { a.resize(len + 1); }
    poly(const poly &p, int len) : len(len) { 
        a.resize(len + 1); 
        for (int i = 0; i <= len; ++i) {
            a[i] = i > p.len ? 0 : p.a[i];
        }
    }

    void setlen(int len){
        a.resize(len + 1);
        this -> len = len;
    }

    void clear(){
        std::vector <int>().swap(a);
        len = -1;
    }
    
    int &operator [] (int n) { assert(n >= 0 && n <= len); return a[n]; }
    
    poly operator + (const poly &p) const {
        poly ret(*this, std::max(len, p.len));
        for (int i = 0; i <= p.len; ++i) {
            ll tmp = (ll) ret.a[i] + p.a[i];
            tmp -= tmp >= moder ? moder : 0;
            ret.a[i] = tmp;
        }
        for ( ; ~ret.len && !ret.a[ret.len]; --ret.len)
            ;
        return ret;
    }
    
    poly operator - (const poly &p) const {
        poly ret(*this, std::max(len, p.len));
        for (int i = 0; i <= p.len; ++i) {
            ret.a[i] -= p.a[i];
            ret.a[i] += ret.a[i] < 0 ? moder : 0;
        }
        for ( ; ~ret.len && !ret.a[ret.len]; --ret.len)
            ;
        return ret;
    }
    
    poly operator * (const int &p)const{
        poly ret(len);
        for (int i = 0; i <= len; ++ i){
            ret.a[i] = 1ll * a[i] * p % moder;
        }
        return ret;
    }

    poly operator * (const poly &p) const {
        if (!~len || !~p.len) return poly(-1);
        int n = len + p.len;
        const int SZ = 100;
        if (len < SZ || p.len < SZ){
            poly ret(n);
            for (int i = 0; i <= len; ++ i){
                for (int j = 0; j <= p.len; ++ j){
                    ret.a[i + j] = (ret.a[i + j] + 1ll * a[i] * p.a[j]) % moder;
                }
            }
            return ret;
        }
        int lenret = 1;
        for ( ; lenret <= n; lenret <<= 1)
            ;
        poly ret(*this, lenret);
        std::vector<int> aux(lenret);
        std::copy(p.a.begin(), p.a.begin() + p.len + 1, aux.begin());
        NTT(ret.a, lenret, 0);
        NTT(aux, lenret, 0);
        for (int i = 0; i < lenret; ++i) {
            ret.a[i] = 1ll * ret.a[i] * aux[i] % moder;
        }
        NTT(ret.a, lenret, 1);
        ret.len = n;
        return ret;
    }
};

std::vector <int> e[N];
int son[N], top[N], sz[N];
poly ans[N], vec[N];
poly aux[M];

void dfs(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (fa == v) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    for (auto v : e[u]){
        if (fa == v) continue;
        if (sz[v] > sz[son[u]]){
            son[u] = v;
        }
    }
}

void dfs1(int u, int tp, int fa){
    top[u] = tp;
    for (auto v : e[u]){
        if (fa == v) continue;
        dfs1(v, son[u] == v ? tp : v, u);
    }
}

poly calc(int l, int r){
    if (l == r){
        return vec[l];
    }
    int sum = 0;
    for (int i = l; i <= r; ++ i){
        sum += vec[i].len;
    }
    int tot = 0, mid;
    for (int i = l; i <= r; ++ i){
        tot += vec[i].len;
        if (tot << 1 >= sum){
            mid = i;
            break;
        }
    }
    if (mid == r){
        -- mid;
    }
    return calc(l, mid) * calc(mid + 1, r);
}

std::pair <poly, poly> calc2(int l, int r){
    if (l == r){
        return {vec[l], vec[l]};
    }
    int sum = 0;
    for (int i = l; i <= r; ++ i){
        sum += vec[i].len;
    }
    int tot = 0, mid;
    for (int i = l; i <= r; ++ i){
        tot += vec[i].len;
        if (tot << 1 >= sum){
            mid = i;
            break;
        }
    }
    if (mid == r){
        -- mid;
    }
    std::pair <poly, poly> p1 = calc2(l, mid), p2 = calc2(mid + 1, r);
    return {p1.first * p2.first, p1.second + p1.first * p2.second};
}

void solve(int u, int fa){
    for (auto v : e[u]){
        if (v == fa) continue;
        solve(v, u);
    }
    int cnt = 0;
    for (auto v : e[u]){
        if (v == fa || v == son[u]) continue;
        ans[v][0] = 1;
        vec[cnt ++] = ans[v];
    }
    if (!cnt){
        ans[u] = poly(0);
        ans[u][0] = 1;
    }
    else{
        ans[u] = calc(0, cnt - 1);
    }
    ans[u].setlen(ans[u].len + 1);
    for (int i = ans[u].len; i; -- i){
        ans[u][i] = ans[u][i - 1];
    }
    ans[u][0] = 0;
    if (top[u] != u || sz[u] == 1) return;
    cnt = 0;
    for (int x = u; x; x = son[x]){
        vec[cnt ++] = ans[x];
    }
    ans[u] = calc2(0, cnt - 1).second;
}

void solve(){
    for (int i = 0; i < N; ++ i){
        std::vector <int>().swap(e[i]);
        ans[i].clear();
    }
    for (int i = 0; i < M; ++ i){
        aux[i].clear();
    }
    memset(sz, 0, sizeof(sz));
    memset(son, 0, sizeof(son));
    memset(top, 0, sizeof(top));
    int n;
    ll x;
    scanf("%d%lld", &n, &x);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    dfs1(1, 1, 0);
    solve(1, 0);
    int comb = 1, sum = 0;
    for (int i = 1; i <= n; ++ i){
        sum = (sum + 1ll * comb * ans[1][i]) % moder;
        comb = comb * ((x + i) % moder) % moder * powermod(i, moder - 2) % moder;
    }
    printf("%d\n", sum);
}

int main(){
    //freopen("data.txt", "r", stdin);
    for (int i = 2; i * i <= moder - 1; ++ i){
        if ((moder - 1) % i == 0){
            assert(powermod(root, i) != 1);
            assert(powermod(root, (moder - 1) / i) != 1);
        }
    }
    init();
    solve();
    return 0;
}