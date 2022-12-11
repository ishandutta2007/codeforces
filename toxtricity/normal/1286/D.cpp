#include <bits/stdc++.h>

const int moder = 998244353;
using ll = long long;

struct Event{
    int id, x, y;
};

struct frac{
    ll x, y;

    explicit frac(ll x = 0, ll y = 0):x(x), y(y){}

    bool operator < (const frac &f)const{return x * f.y < y * f.x;}
    bool operator == (const frac &f)const{return x * f.y == y * f.x;}
};

struct matrix{
    static const int N = 2;

    int a[N][N];

    matrix():a(){}

    int *operator[](const int &n){ return a[n]; }

    matrix operator *(const matrix &m)const{
        matrix ret;
        for (int k = 0; k < 2; ++ k){
            for (int i = 0; i < 2; ++ i){
                for (int j = 0; j < 2; ++ j){
                    ret[i][j] = (ret[i][j] + 1ll * a[i][k] * m.a[k][j]) % moder;
                }
            }
        }
        return ret;
    }
};

const int N = 300010;
const int MAX = 1 << 17;

matrix seg[MAX << 1];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void add(int pos, matrix mat){
    seg[pos += MAX] = mat;
    for (pos >>= 1; pos; pos >>= 1){
        seg[pos] = seg[pos << 1 | 1] * seg[pos << 1];
    }
}

matrix query(int l, int r){
    matrix retl, retr;
    for (int i = 0; i < 2; ++ i){
        retl[i][i] = retr[i][i] = 1;
    }
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) retl = seg[l ++] * retl;
        if (r & 1) retr = retr * seg[-- r];
    }
    return retr * retl;
}

ll x[N], v[N];
int prob[N];
std::vector <Event> event[N];
frac c[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld%d", &x[i], &v[i], &prob[i]);
        prob[i] = 1ll * prob[i] * powermod(100, moder - 2) % moder;
    }
    if (n == 1){
        puts("0");
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; ++ i){
        c[cnt ++] = frac(x[i + 1] - x[i], v[i] + v[i + 1]);
        if (v[i] != v[i + 1]){
            c[cnt ++] = frac(x[i + 1] - x[i], std::abs(v[i] - v[i + 1]));
        }
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    for (int i = 0; i < n - 1; ++ i){
        int pos = std::lower_bound(c, c + cnt, frac(x[i + 1] - x[i], v[i] + v[i + 1])) - c;
        event[pos].push_back({i, 1, 0});
        seg[i + MAX][1][0] = prob[i + 1];
        if (v[i] < v[i + 1]){
            int pos = std::lower_bound(c, c + cnt, frac(x[i + 1] - x[i], std::abs(v[i] - v[i + 1]))) - c;
            event[pos].push_back({i, 0, 0});
            seg[i + MAX][1][1] = prob[i + 1];
        }
        else if (v[i] > v[i + 1]){
            int pos = std::lower_bound(c, c + cnt, frac(x[i + 1] - x[i], std::abs(v[i] - v[i + 1]))) - c;
            event[pos].push_back({i, 1, 1});
            seg[i + MAX][0][0] = 1 - prob[i + 1];
            seg[i + MAX][0][0] += seg[i + MAX][0][0] < 0 ? moder : 0;
        }
        else{
            seg[i + MAX][0][0] = 1 - prob[i + 1];
            seg[i + MAX][0][0] += seg[i + MAX][0][0] < 0 ? moder : 0;
            seg[i + MAX][1][1] = prob[i + 1];
        }
    }
    for (int i = MAX - 1; i > 0; -- i){
        seg[i] = seg[i << 1 | 1] * seg[i << 1];
    }
    matrix mat = query(0, n - 2);
    int xx = 1 - prob[0], yy = prob[0];
    int cur = (1ll * mat[0][0] * xx + 1ll * mat[0][1] * yy + 1ll * mat[1][0] * xx + 1ll * mat[1][1] * yy) % moder;
    int ans = 0, pre = cur;
    for (int i = cnt - 1; i >= 0; -- i){
        for (auto u : event[i]){
            matrix mat = seg[u.id + MAX];
            int xx = 1 - prob[u.id + 1];
            xx += xx < 0 ? moder : 0;
            mat[u.y][u.x] = u.y == 0 ? xx : prob[u.id + 1];
            add(u.id, mat);
        }
        matrix mat = query(0, n - 2);
        int xx = 1 - prob[0], yy = prob[0];
        int cur = (1ll * mat[0][0] * xx + 1ll * mat[0][1] * yy + 1ll * mat[1][0] * xx + 1ll * mat[1][1] * yy) % moder;
        int value = c[i].x * powermod(c[i].y, moder - 2) % moder;
        ans = (ans + 1ll * value * (cur - pre)) % moder;
        pre = cur;
    }
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}