#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 5e5;
const int INF = 1e9;
const int A = N;
const int K = 20;

struct Query {
    int x, l, r, tp, nom;
    Query() {}
    Query(int x, int l, int r, int tp, int nom) : x(x), l(l), r(r), tp(tp), nom(nom) {}

    bool operator <(const Query& q) const {
        if (x != q.x) return x < q.x;
        return tp < q.tp;
    }

    void print() {
        cerr << x << " " << l << " " << r << " " << tp << " " << nom << endl;
    }
};

int n, q, nom[N];
char buff[N];
int s[N];
int p[N], cnt[N], cl[N], pn[N], cn[N], ls, len[N], ans[N];
int c[K][N], lg2[N], lcp[N], LAST, rmin[K][N], nst[N], sa[N], rev[N];
vector<Query> v;

void save(int cur, int ls) {
    for (int i = 0; i < ls; i++) c[cur][i] = cl[i];
}

void suffarray() {
    lg2[1] = 0;
    for (int i = 2; i < N; i++) lg2[i] = lg2[i / 2] + 1;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < ls; i++) cnt[s[i]]++;
    for (int i = 1; i < A; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < ls; i++) p[--cnt[s[i]]] = i;
    cl[p[0]] = 0;
    for (int i = 1; i < ls; i++) {
        cl[p[i]] = cl[p[i - 1]];
        if (s[p[i]] != s[p[i - 1]]) cl[p[i]]++;
    }
    save(0, ls);

    for (int ch = 0; (1 << ch) < ls; ch++) {
        // for (int i = 0; i < ls; i++) cerr << p[i] << " ";
        //  cerr << endl;
        for (int i = 0; i < ls; i++) {
            pn[i] = p[i] - (1 << ch);
            while (pn[i] < 0) pn[i] += ls;
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < ls; i++) ++cnt[cl[pn[i]]];
        for (int i = 1; i < A; i++) cnt[i] += cnt[i - 1];
        for (int i = ls - 1; i >= 0; i--) p[--cnt[cl[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        for (int i = 1; i < ls; i++) {
            int n0 = (p[i] + (1 << ch)) % ls;
            int n1 = (p[i - 1] + (1 << ch)) % ls;
            cn[p[i]] = cn[p[i - 1]];
            if ((cl[p[i]] != cl[p[i - 1]]) || (cl[n0] != cl[n1])) cn[p[i]]++;
        }
        for (int i = 0; i < A; i++) cl[i] = cn[i];
        save(ch + 1, ls);
        LAST = ch + 1;
    }
    for (int i = 0; i + 1 < ls; i++) {
        lcp[i] = 0;
        int x = p[i];
        int y = p[i + 1];
        for (int j = LAST; j >= 0; j--) {
            if (c[j][x] == c[j][y]) {
                lcp[i] += (1 << j);
                x += (1 << j);
                y += (1 << j);
            }
        }
    }
}

int getmin(int l, int r) {
    if (r < l) return INF;
    int k = lg2[r - l + 1];
    return min(rmin[k][l], rmin[k][r - (1 << k) + 1]);
}

void add(int x) {
    ++x;
    for (int i = x; i < N; i = (i | (i - 1)) + 1) sa[i]++;
}

int fsum(int x) {
    ++x;
    int res = 0;
    for (int i = x; i > 0; i = (i & (i - 1))) res += sa[i];
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d\n", &n, &q);
    ls = 0;
    for (int i = 0; i < n; i++) {
        gets(buff);
        buff[strlen(buff)] = 0;
        string curs(buff);
        // cerr << curs << endl;
        len[i] = curs.size();
        nst[i] = ls;
        for (int j = 0; j < curs.size(); j++) {
            nom[ls] = i;
            s[ls++] = curs[j] - 'a' + n;
        }
        nom[ls] = i;
        s[ls++] = n - i - 1;
    }
    // for (int i = 0; i < ls; i++) cerr << s[i] << " ";
    //  cerr << endl;
    suffarray();
    // for (int i = 0; i < ls; i++) cerr << p[i] << " ";
    //  cerr << endl;
    // for (int i = 0; i + 1 < ls; i++) cerr << lcp[i] << " ";
    //  cerr << endl;
    for (int i = 0; i < ls; i++) rev[p[i]] = i;
    for (int i = 0; i < ls; i++) rmin[0][i] = lcp[i];
    for (int j = 1; j < K; j++) {
        for (int i = 0; i < ls; i++) {
            rmin[j][i] = rmin[j - 1][i];
            int ni = i + (1 << (j - 1));
            if (ni < ls) rmin[j][i] = min(rmin[j][i], rmin[j - 1][ni]);
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        --l; --r; --k;
        int ss = rev[nst[k]];
        int ll = ss, rr = ls;
        while (ll < rr - 1) {
            int mid = (ll + rr) / 2;
            if (getmin(ss, mid - 1) >= len[k]) {
                ll = mid;
            } else {
                rr = mid;
            }
        }
        int ri = ll;
        ll = -1, rr = ss;
        while (ll < rr - 1) {
            int mid = (ll + rr) / 2;
            if (getmin(mid, ss - 1) >= len[k]) {
                rr = mid;
            } else {
                ll = mid;
            }
        }
        int le = rr;
        // cerr << le << " " << ss << " " << ri << endl;
        v.push_back(Query(le - 1, l, r, 1, i));
        v.push_back(Query(ri, l, r, 2, i));
    }
    for (int i = 0; i < ls; i++) {
        v.push_back(Query(i, nom[p[i]], nom[p[i]], 0, 0));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        // v[i].print();
        if (v[i].tp == 0) {
            add(v[i].l);
        } else if (v[i].tp == 1) {
            ans[v[i].nom] -= fsum(v[i].r) - fsum(v[i].l - 1);
        } else {
            ans[v[i].nom] += fsum(v[i].r) - fsum(v[i].l - 1);
        }
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
}