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
 
#define INF 2100000000
#define COR 1000000000
#define N 300500
#define M 600500
 
using namespace std;
 
struct Point {
        int cm, l, r, rev;
        Point(int cm, int l, int r) : cm(cm), l(l), r(r) {};
};
 
struct Tree {
        int l, r, mr, data;
        Tree() : l(0), r(0), mr(-INF), data(-INF) {};
        Tree(int l, int r, int data) : l(l), r(r), data(data), mr(-INF) {};
};
 
int next[N], prev[N];
int a[N], b[N], ansl, ansr, n, k, d, tmax[N];
map <int, int> cnt;
vector<Point> v;
Tree tr[M];
 
void upd(int l, int r) {
        if (r < l)
                return;
        if ((r - l + 1 > ansr - ansl + 1) || ((ansr - ansl + 1 == r - l + 1) && (l < ansl))) {
                ansl = l;
                ansr = r;
        }
}
 
bool cmp(Point x, Point y) {
        return x.cm - x.r < y.cm - y.r;
}
 
bool cmp2(Point x, Point y) {
        return x.r < y.r;
}
 
void build(int x, int l, int r) {
        tr[x] = Tree(v[l].cm - v[l].r, v[r].cm - v[r].r, v[l].r);
        if (l < r) {
                build(x + x, l, (l + r) >> 1);
                build(x + x + 1, ((l + r) >> 1) + 1, r);
        } else
                v[l].rev = x;
}
 
void modify(int x, int e) {
        if (e == -1)
                tr[x].mr = -INF;
        else
                tr[x].mr = tr[x].data;
        while (x > 1) {
                x >>= 1;
                tr[x].mr = max(tr[x + x].mr, tr[x + x + 1].mr);
        }
}
 
int findmax(int x, int t) {
        if (t < tr[x].l)
                return -INF;
        if (tr[x].r <= t)
                return tr[x].mr;
        return max(findmax(x + x, t), findmax(x + x + 1, t));
}
 
void solve(int l, int r) {
        if (l > r)
                return;
        int mid, cmin, cmax, lj, rj, lv, rv;
        mid = (l + r) / 2;
        solve(l, mid - 1);
        solve(mid + 1, r);
        //First case: min and max in left part
        cmax = b[mid];
        cmin = b[mid];
        for (int i = mid, j = mid; i >= l; i--) {
                j = min(j, next[i]);
                if (j < mid)
                        break;
                cmin = min(cmin, b[i]);
                cmax = max(cmax, b[i]);
                while ((j < next[i]) && (j < r) && (b[j + 1] < cmax) && (b[j + 1] > cmin))
                        j++;
                if (cmax - cmin - (j - i) <= k)
                        upd(i, j);
        }
        //Second case: min and max in right part
        cmax = b[mid];
        cmin = b[mid];
        for (int i = mid, j = mid; j <= r; j++) {
                i = max(i, prev[j]);
                if (i > mid)
                        break;
                cmin = min(cmin, b[j]);
                cmax = max(cmax, b[j]);
                while ((i > prev[j]) && (i > l) && (b[i - 1] < cmax) && (b[i - 1] > cmin))
                        i--;
                if (cmax - cmin - (j - i) <= k)
                        upd(i, j);
        }
        //Third case: min in left part, max in right part
        v.clear();
        for (int i = mid; i <= r; i++) {
                if (i == mid)
                        tmax[i] = b[i];
                else
                        tmax[i] = max(tmax[i - 1], b[i]);
                if ((v.empty()) || (b[i] > v.back().cm))
                        v.push_back(Point(b[i], i, i));
                else
                        v.back().r = i;
        }
        sort(v.begin(), v.end(), cmp);
        build(1, 0, int(v.size()) - 1);
        sort(v.begin(), v.end(), cmp2);
        cmin = b[mid];
        cmax = b[mid];
        lj = mid + 1;
        rj = mid - 1;
        lv = 0;
        rv = 0;
        for (int i = mid; i >= l; i--) {
                if (next[i] < mid)
                        break;
                cmin = min(cmin, b[i]);
                cmax = max(cmax, b[i]);
                while ((rj >= lj) && (rj > next[i])) {
                        while ((rv > lv) && (v[rv - 1].r >= rj)) {
                                rv--;
                                modify(v[rv].rev, -1);
                        }
                        rj--;
                }
                while ((rj < next[i]) && (rj < r) && (b[rj + 1] >= cmin)) {
                        rj++;
                        while ((rv < v.size()) && (v[rv].r <= rj)) {
                                if (v[rv].l >= lj)
                                        modify(v[rv].rev, +1);
                                rv++;
                        }
                }
                while ((lj <= rj) && (tmax[lj] < cmax)) {
                        while ((lv < rv) && (v[lv].l <= lj)) {
                                modify(v[lv].rev, -1);
                                lv++;
                        }
                        lj++;
                       
                }
                if (rj < lj)
                        continue;
                upd(i, findmax(1, k + cmin - i));
                if ((rv < v.size()) && (v[rv].l >= lj) && (v[rv].cm - rj <= k + cmin - i))
                        upd(i, rj);
        }
        //Fourth case: max in left part, min in right part
        for (int i = l; i <= r; i++)
                b[i] = -b[i];
        v.clear();
        for (int i = mid; i <= r; i++) {
                if (i == mid)
                        tmax[i] = b[i];
                else
                        tmax[i] = max(tmax[i - 1], b[i]);
                if ((v.empty()) || (b[i] > v.back().cm))
                        v.push_back(Point(b[i], i, i));
                else
                        v.back().r = i;
        }
        sort(v.begin(), v.end(), cmp);
        build(1, 0, int(v.size()) - 1);
        sort(v.begin(), v.end(), cmp2);
        cmin = b[mid];
        cmax = b[mid];
        lj = mid + 1;
        rj = mid - 1;
        lv = 0;
        rv = 0;
        for (int i = mid; i >= l; i--) {
                if (next[i] < mid)
                        break;
                cmin = min(cmin, b[i]);
                cmax = max(cmax, b[i]);
                while ((rj >= lj) && (rj > next[i])) {
                        while ((rv > lv) && (v[rv - 1].r >= rj)) {
                                rv--;
                                modify(v[rv].rev, -1);
                        }
                        rj--;
                }
                while ((rj < next[i]) && (rj < r) && (b[rj + 1] >= cmin)) {
                        rj++;
                        while ((rv < v.size()) && (v[rv].r <= rj)) {
                                if (v[rv].l >= lj)
                                        modify(v[rv].rev, +1);
                                rv++;
                        }
                }
                while ((lj <= rj) && (tmax[lj] < cmax)) {
                        while ((lv < rv) && (v[lv].l <= lj)) {
                                modify(v[lv].rev, -1);
                                lv++;
                        }
                        lj++;
                       
                }
                if (rj < lj)
                        continue;
                upd(i, findmax(1, k + cmin - i));
                if ((rv < v.size()) && (v[rv].l >= lj) && (v[rv].cm - rj <= k + cmin - i))
                        upd(i, rj);
        }
        for (int i = l; i <= r; i++)
                b[i] = -b[i];
}
 
int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        scanf("%d%d%d", &n, &k, &d);
        if (d == 0) {
                ansl = 0;
                ansr = -1;
                for (int i = 0; i < n; i++)
                        scanf("%d", &a[i]);
                for (int i = 0; i < n; i++) {
                        int j = i;
                        while ((j + 1 <  n) && (a[j + 1] == a[i]))
                                j++;
                        upd(i, j);
                }
                printf("%d %d\n", ansl + 1, ansr + 1);
                return 0;
        }
        for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
                a[i] += COR;
                b[i] = a[i] / d;
        }
        cnt.clear();
        for (int i = 0, j = -1; i < n; i++) {
                while ((j + 1 < n) && (cnt[a[j + 1]] == 0)) {
                        j++;
                        cnt[a[j]]++;
                }
                next[i] = j;
                cnt[a[i]]--;
        }
        cnt.clear();
        for (int i = n - 1, j = n; i >= 0; i--) {
                while ((j - 1 >= 0) && (cnt[a[j - 1]] == 0)) {
                        j--;
                        cnt[a[j]]++;
                }
                prev[i] = j;
                cnt[a[i]]--;
        }
       
        ansl = 0;
        ansr = -1;
        for (int i = 0; i < n; i++) {
                int j = i;
                while ((j + 1 < n) && (a[j + 1] % d == a[i] % d))
                        j++;
                solve(i, j);
                i = j;
        }
        printf("%d %d\n", ansl + 1, ansr + 1);
}