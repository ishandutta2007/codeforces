#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int C = 4, INF = 1000000000;

struct State {
    int length;
    State *parent, *go[C];

    int toEnd[C];
    bool vis;

    State(int length) : length(length), parent(NULL) {
        memset(go, NULL, sizeof(go));
        vis = false;
    }
    
    State* extend(State* start, int token) {
        State *p = this;
        State *np = new State(length + 1);
        while (p && !p->go[token]) {
            p->go[token] = np; 
            p = p->parent;
        }
        if (!p) {
            np->parent = start;
        } else {
            State *q = p->go[token];
            if (p->length + 1 == q->length) {
                np->parent = q;
            } else {
                State *nq = new State(p->length + 1);
                memcpy(nq->go, q->go, sizeof(q->go));
                nq->parent = q->parent;
                np->parent = q->parent = nq;
                while (p && p->go[token] == q) {
                    p->go[token] = nq;
                    p = p->parent;
                }
            }
        }
        return np;
    }

    void dp() {
        if (vis == true) {
            return;
        }
        vis = true;
        for (int i = 0; i < C; ++i) {
            if (!go[i]) {
                toEnd[i] = 1;
            } else {
                toEnd[i] = INF;
            }
        }
        for (int i = 0; i < C; ++i) {
            if (go[i]) {
                go[i]->dp();
                for (int j = 0; j < C; ++j) {
                    toEnd[j] = min(toEnd[j], go[i]->toEnd[j] + 1);
                }
            }
        }
    }
};

struct Matrix {
    long long a[C][C];

    Matrix(int tag = 0) {
        memset(a, 0, sizeof(a));
        if (tag) {
            for (int i = 0; i < C; ++i) {
                a[i][i] = 1;
            }
        }
    }

    long long* operator [] (const int &i) {
        return a[i];
    }
    
    const long long* operator [] (const int &i) const {
        return a[i];
    }
};

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix ret;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            ret[i][j] = 1ll << 60;
        }
    }
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < C; ++k) {
                ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return ret;
}

Matrix powMod(const Matrix &a, long long n) {
    Matrix ret(1), mul = a;
    while (n) {
        if (n & 1) {
            ret = ret * mul;
        }
        mul = mul * mul;
        n >>= 1;
    }
    return ret;
}

Matrix g;

long long cal(long long n) {
    Matrix a = powMod(g, n);
    long long ret = 1ll << 60;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
//cout << (char)('A' + i) << ' ' << (char)('A' + j) << ' ' << a[i][j] << endl;
            ret = min(ret, a[i][j]);
        }
    }
    return ret;
}

long long n;

const int L = 100005;
int l;
char s[L];

State *root;

int main() {
    cin >> n;
    scanf("%s", s);
    l = strlen(s);
    root = new State(0);
    State *last = root;
    for (int i = 0; i < l; ++i) {
        last = last->extend(root, s[i] - 'A'); 
    }
    root->dp();
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            g[i][j] = root->go[i]->toEnd[j];
//cout << (char)('A' + i) << ' ' << (char)('A' + j) << ' ' << g[i][j] << endl;
        }
    }
    long long l = 1, r = n + 1;
    while (l < r) {
        long long m = l + r + 1 >> 1;
//cout << l << ' ' << r << ' ' << m << ' ' << cal(m) << endl;
        if (cal(m) <= n) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l + (cal(l) < n) << endl;
    return 0;
}