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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

struct Edge {
    int w, tp, nom;
    Edge() {}
    bool operator < (const Edge &e) const {
        if (w != e.w) return w < e.w;
        return tp > e.tp;
    }
};

int n, m;

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    vector<Edge> a(m);
    for (int i = 0; i <m; i++) {
        scanf("%d%d", &a[i].w, &a[i].tp);
        a[i].nom = i;
    }   
    sort(a.begin(), a.end());
    int lst = 0;
    vector< pair<int, int> > ans(m);
    vector< pair<int, int> > act;
    int fst = 0;
    for (int i = 0; i < m; i++) {
        if (a[i].tp == 1) {
            ++lst;
            ans[a[i].nom] = mp(0, lst);
            for (int j = 1; (j < lst) && ((int)act.size() <= m); j++) {
                act.pb(mp(j, lst));
            }
        } else {
            if (fst == (int)act.size()) {
                puts("-1");
                return 0;
            }
            ans[a[i].nom] = act[fst++];
        }
    }
    for (int i = 0; i < m; i++) printf("%d %d\n", 1+ans[i].fr, 1+ans[i].sc);
    return 0;
}