#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

int xb[100050], yb[100050], xe[100050], ye[100050];

struct cut {
    int A, B1, B2;
} C1[100050], C2[100050];
bool operator < (const cut& a, const cut& b)
{
    return a.A < b.A;
}

pair<int, int> P[200050];

int main()
{
    int n, m, k;

    scanf("%d%d%d", &n, &m, &k);

    int c1 = 0, c2 = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d%d%d", &xb[i], &yb[i], &xe[i], &ye[i]);
        if (xb[i] == xe[i]) {
            C1[c1].A = xb[i];
            C1[c1].B1 = min(yb[i], ye[i]);
            C1[c1].B2 = max(yb[i], ye[i]);
            ++c1;
        } else {
            C2[c2].A = yb[i];
            C2[c2].B1 = min(xb[i], xe[i]);
            C2[c2].B2 = max(xb[i], xe[i]);
            ++c2;
        }
    }

    sort(C1, C1+c1);
    sort(C2, C2+c2);

    int ns = m - 1, ms = n - 1;
    vector<int> rem1, xx, rem2, yy;
    vector<vector<pair<int, int> > > sp1, sp2;

    for (int i = 0; i < c1; ) {
        int j = i;
        while (j < c1 && C1[i].A == C1[j].A) ++j;

        int ps = 0;
        for (int k = i; k < j; ++k) {
            P[ps++] = make_pair(C1[k].B1, +1);
            P[ps++] = make_pair(C1[k].B2, -1);
        }
        sort(P, P+ps);

        int prev = 0, s = 0, r = 0;
        sp1.push_back(vector<pair<int, int> >());
        for (int k = 0; k < ps; ++k) {
            if (s == 0) {
                sp1.back().push_back(make_pair(prev, P[k].first));
                r += P[k].first - prev;
            }
            s += P[k].second;
            prev = P[k].first;
        }
        sp1.back().push_back(make_pair(prev, m));
        r += m - prev;

        rem1.push_back(r);
        xx.push_back(C1[i].A);
        --ms;
        i = j;
    }

    for (int i = 0; i < c2; ) {
        int j = i;
        while (j < c2 && C2[i].A == C2[j].A) ++j;

        int ps = 0;
        for (int k = i; k < j; ++k) {
            P[ps++] = make_pair(C2[k].B1, +1);
            P[ps++] = make_pair(C2[k].B2, -1);
        }
        sort(P, P+ps);

        int prev = 0, s = 0, r = 0;
        sp2.push_back(vector<pair<int, int> >());
        for (int k = 0; k < ps; ++k) {
            if (s == 0) {
                sp2.back().push_back(make_pair(prev, P[k].first));
                r += P[k].first - prev;
            }
            s += P[k].second;
            prev = P[k].first;
        }
        sp2.back().push_back(make_pair(prev, n));
        r += n - prev;

        rem2.push_back(r);
        yy.push_back(C2[i].A);
        --ns;
        i = j;
    }

    uint X = 0;
    if (ms % 2 == 1) X ^= m;
    if (ns % 2 == 1) X ^= n;
    for (int i = 0; i < (int)rem1.size(); ++i) {
        X ^= rem1[i];
    }
    for (int i = 0; i < (int)rem2.size(); ++i) {
        X ^= rem2[i];
    }

    if (X == 0) {
        puts("SECOND");
    } else {
        puts("FIRST");

        if (ms > 0 && (uint)m > (uint)(m ^ X)) {
            int mx = 1;
            for (int i = 0; i < (int)xx.size(); ++i) {
                if (xx[i] == mx) {
                    ++mx;
                }
            }
            int am = (uint)m - (uint)(m ^ X);
            printf("%d 0 %d %d\n", mx, mx, am);
            return 0;
        } else if (ns > 0 && (uint)n > (uint)(n ^ X)) {
            int ny = 1;
            for (int i = 0; i < (int)yy.size(); ++i) {
                if (yy[i] == ny) {
                    ++ny;
                }
            }
            int am = (uint)n - (uint)(n ^ X);
            printf("0 %d %d %d\n", ny, am, ny);
            return 0;
        } else {
            for (int i = 0; i < (int)rem1.size(); ++i) {
                if ((uint)rem1[i] > (uint)(rem1[i] ^ X)) {
                    int am = (uint)rem1[i] - (uint)(rem1[i] ^ X);
                    int cur = 0;
                    for (int j = 0; j < (int)sp1[i].size(); ++j) {
                        int ss = sp1[i][j].second - sp1[i][j].first;
                        if (cur + ss >= am) {
                            int pt = am - cur + sp1[i][j].first;
                            printf("%d 0 %d %d\n", xx[i], xx[i], pt);
                            return 0;
                        }
                        cur += ss;
                    }
                }
            }
            for (int i = 0; i < (int)rem2.size(); ++i) {
                if ((uint)rem2[i] > (uint)(rem2[i] ^ X)) {
                    int am = (uint)rem2[i] - (uint)(rem2[i] ^ X);
                    int cur = 0;
                    for (int j = 0; j < (int)sp2[i].size(); ++j) {
                        int ss = sp2[i][j].second - sp2[i][j].first;
                        if (cur + ss >= am) {
                            int pt = am - cur + sp2[i][j].first;
                            printf("0 %d %d %d\n", yy[i], pt, yy[i]);
                            return 0;
                        }
                        cur += ss;
                    }
                }
            }
        }
    }

    return 0;
}