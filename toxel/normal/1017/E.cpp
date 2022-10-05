#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, int> pii;

const int moder = 998244353;

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

struct KMP{
    #define MAXM (1000010)
    int m;
    pii p[MAXM];
    int fail[MAXM];

    void makeFail(pii *p, int mm){
        memset(this -> p, 0, sizeof(this -> p));

        m = mm;
        for(int i = 0; i < m; ++ i){
            this -> p[i] = p[i];
        }

        fail[0] = -1;
        for(int i = 1, j = -1; i <= m; ++ i){
            while(j >= 0 && p[j] != p[i - 1]) j = fail[j];
            fail[i] = ++ j;
        }
    }

    bool searchForm(pii *t, int n){
        for(int i = 0, j = 0; i < n; ++ i){
            while(j >= 0 && p[j] != t[i]) j = fail[j];
            if(++ j == m){
                return true;
            }
        }
        return false;
    }
    #undef MAXM
}kmp;

struct P{
    int x, y;

    P (int x = 0, int y = 0):x(x), y(y){}
    P operator +(const P &p)const{return P(x + p.x, y + p.y);}
    P operator -(const P &p)const{return P(x - p.x, y - p.y);}
    ll operator ^(const P &p)const{return 1ll * x * p.y - 1ll * y * p.x;}
    ll operator %(const P &p)const{return 1ll * x * p.x + 1ll * y * p.y;}
    ll abs2()const{return *this % *this;}
    
    bool operator < (const P &p)const{
        return x != p.x ? x < p.x : y < p.y;
    }

    void read(){
        scanf("%d%d", &x, &y);
    }
};

struct L{
    P p, v;

    L (){}
    L (P a, P b):p(a), v(b - a){}
};

ll onLeft(L l, P p){
    return l.v ^ (p - l.p);
}

const int N = 1000010;

std::vector <P> convexHull(std::vector <P> &ps){
    static P stack[N];
    std::sort(ps.begin(), ps.end());
    int n = ps.size(), top = 0;
    for (int i = 0; i < n; ++ i){
        while (top > 1 && onLeft(L (stack[top - 2], stack[top - 1]), ps[i]) <= 0){
            -- top;
        }
        stack[top ++] = ps[i];
    }
    int tmp = top;
    for (int i = n - 2; i >= 0; -- i){
        while (top > tmp && onLeft(L (stack[top - 2], stack[top - 1]), ps[i]) <= 0){
            -- top;
        }
        stack[top ++] = ps[i];
    }
    if (n > 1) -- top;
    std::vector <P> ret;
    for (int i = 0; i < top; ++ i){
        ret.push_back(stack[i]);
    }
    return ret;
}

pii s[N], t[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector <P> ps, qs;
    for (int i = 0; i < n; ++ i){
        P p;
        p.read();
        ps.push_back(p);
    }
    for (int i = 0; i < m; ++ i){
        P p;
        p.read();
        qs.push_back(p);
    }
    ps = convexHull(ps);
    qs = convexHull(qs);
    if (ps.size() != qs.size()){
        puts("NO");
        return 0;
    }
    n = ps.size();
    for (int i = 0; i < n; ++ i){
        ll x = (ps[i] - ps[(i + 1) % n]).abs2();
        ll y = (qs[i] - qs[(i + 1) % n]).abs2();
        int u = ((ps[(i + 1) % n] - ps[i]) % (ps[(i + 1) % n] - ps[(i + 2) % n])) % moder;
        u = 1ll * u * u % moder;
        u = 1ll * u * powermod(x, moder - 2) % moder * powermod((ps[(i + 1) % n] - ps[(i + 2) % n]).abs2(), moder - 2) % moder;
        int v = ((qs[(i + 1) % n] - qs[i]) % (qs[(i + 1) % n] - qs[(i + 2) % n])) % moder;
        v = 1ll * v * v % moder;
        v = 1ll * v * powermod(y, moder - 2) % moder * powermod((qs[(i + 1) % n] - qs[(i + 2) % n]).abs2(), moder - 2) % moder;
        s[i] = {x, u};
        t[i] = {y, v};
    }
    for (int i = n; i < n << 1; ++ i){
        s[i] = s[i - n];
    }
    kmp.makeFail(t, n);
    if (kmp.searchForm(s, n << 1)){
        puts("YES");
    }
    else{
        puts("NO");
    }
    return 0;
}