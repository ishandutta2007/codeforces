#include<bits/stdc++.h>

const int N = 100010;
const int BIT = 42;
const double INF = 1e100;
const double eps = 1e-12; typedef long long ll;
typedef std::pair <double, double> pdd;

inline int sig(double x){return (x > eps) - (x < -eps);}

struct L{
    double k, b, p;
    
    L(double k = 0, double b = 0, double p = 0):k(k), b(b), p(p){}

    bool operator < (const L &l)const{
        return k < l.k;
    }

    double gety(double x){
        return k * x + b;
    }
};

struct matrix{
    static const int N = 3;
    int n, m;
    double a[N][N];


    matrix():n(0),m(0){memset(a, 0, sizeof(a));}
    matrix(int n, int m):n(n),m(m){memset(a, 0, sizeof(a));}
    
    double *operator [](const int &sit){return a[sit];}

    matrix operator *(const matrix &mat)const{
        matrix ret(n, mat.m);
        for (int k = 0; k < m; ++ k){
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < mat.m; ++ j){
                    ret[i][j] += a[i][k] * mat.a[k][j];
                }
            }
        }
        return ret;
    }

    matrix power(ll exp)const{
        matrix ret(n, n), tmp = *this;
        for (int i = 0; i < n; ++ i){
            ret[i][i] = 1;
        }
        for ( ; exp > 0; exp >>= 1){
            if (exp & 1){
                ret = ret * tmp;
            }
            tmp = tmp * tmp;
        }
        return ret;
    }
};

int a[N], b[N];
double p[N];
matrix trans[BIT];

int main(){
    int n;
    ll t;
    scanf("%d%lld", &n, &t);
    double max = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%lf", &a[i], &b[i], &p[i]);
        max = std::max(max, b[i] * p[i]);
    }
    std::vector <pdd> vec;
    std::vector <L> stack;
    for (int i = 0; i < n; ++ i){
        vec.push_back({p[i], p[i] * a[i]});
    }
    std::sort(vec.begin(), vec.end());
    for (auto u : vec){
        while (!stack.empty()){
            L last = stack.back();
            if (!sig(last.k - u.first)){
                stack.pop_back();
                continue;
            }
            double x = (u.second - last.b) / (last.k - u.first);
            if (sig(x - last.p) <= 0){
                stack.pop_back();
                continue;
            }
            stack.push_back(L(u.first, u.second, x));
            break;
        }
        if (stack.empty()){
            stack.push_back(L(u.first, u.second, -INF));
        }
    }
    matrix now(3, 1);
    now[0][0] = 1;
    for (int i = 0, sz = stack.size(); i < sz; ++ i){
        if (i < sz - 1 && sig(now[1][0] * max - now[2][0] - stack[i + 1].p) >= 0) continue;
        L l = stack[i];
        trans[0] = matrix(3, 3);
        trans[0][0][0] = trans[0][1][0] = trans[0][1][1] = 1;
        trans[0][2][0] = l.b;
        trans[0][2][1] = l.k * max;
        trans[0][2][2] = 1 - l.k;
        for (int j = 1; j < BIT; ++ j){
            trans[j] = trans[j - 1] * trans[j - 1];
        }
        matrix tmp(3, 3);
        for (int j = 0; j < 3; ++ j){
            tmp[j][j] = 1;
        }
        for (int j = BIT - 1; j >= 0; -- j){
            matrix mat = tmp * trans[j];
            matrix nowmat = mat * now;
            if ((ll) std::round(nowmat[1][0]) <= t && (i == sz - 1 || sig(nowmat[1][0] * max - nowmat[2][0] - stack[i + 1].p) < 0)){
                tmp = mat;
            }
        }
        now = tmp * now;
        if ((ll) std::round(now[1][0]) == t){
            break;
        }
        now = trans[0] * now;
    }
    printf("%.12f\n", now[2][0]);
    return 0;
}