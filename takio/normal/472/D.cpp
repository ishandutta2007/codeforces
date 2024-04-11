#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define LL long long
#define pii pair <LL, LL>
using namespace std;

const LL INF = 2e9 + 10;
//struct edge {
//    LL u, v, w;
//} e[4000010];
LL mp[2010][2010];

LL head[4010], tot = 0, d[4010], n;

struct eg {
    LL v, nx, w;
    eg () {}
    eg (LL v, LL nx, LL w) : v(v), nx (nx), w(w) {}
} e2[8010];

void add (LL u, LL v, LL w) {
//    cout << "u" << u << endl;
    e2[tot] = eg (v, head[u], w);
    head[u] = tot++;
}

//bool cmp (edge a, edge b) {
//    return a.w < b.w;
//}

LL dij (LL u) {
    priority_queue <pii> q;
    q.push (pii (0, u));
    for (LL i = 1; i <= n; i++) d[i] = INF;
//    cout << d[0] << endl;
    d[u] = 0;
    LL v;
    while (!q.empty()) {
        pii k = q.top();
        LL x = k.second;
        if (d[x] != mp[u][x]) {
//               cout << x << ' ' << mp[u][x] << ' ' << d[x] <<endl;
                return 0;
        }
//        cout << x <<' ' << d[x] << endl;
        q.pop();
        for (LL i = head[x]; i != -1; i = e2[i].nx) {
            v = e2[i].v;
            if (mp[x][v] && d[v] > d[x] + e2[i].w){
                d[v] = d[x] + e2[i].w;
                q.push (pii (d[x] + e2[i].w, v));
            }
        }
    }
//    cout << u << endl;
//    for (LL i = 1; i <= n; i++) cout <<d[i] <<' '; cout << endl;
    return 1;
}

LL fa[4010], vis[4010];

LL find (LL x) {
    if (fa[x] == x) return x;
    return fa[x] = find (fa[x]);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            scanf ("%I64d", &mp[i][j]);
            if ((i == j && mp[i][j]) || (i != j && !mp[i][j])) {
                printf ("NO\n");
                return 0;
            }
        }
    }
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            if (mp[i][j] != mp[j][i]) {
                printf ("NO\n");
                return 0;
            }
        }
    }
//    LL en = 0, cnt = 0;
    for (LL i = 1; i <= n; i++) d[i] = INF;
    d[1] = 0;
    LL p = 1;
    memset (head, -1, sizeof head);
    for (LL i = 1; i < n; i++) {
        vis[p] = 1;
        for (LL j = 1; j <= n; j++) if (!vis[j] && mp[p][j] && d[j] > mp[p][j]){
            d[j] = mp[p][j];
            fa[j] = p;
//            cout << "jp" << j << ' ' << p << ' ' << d[j] << ' ' << fa[j] << endl;
        }
        LL mn = INF + 10, v;
        for (LL j = 1; j <= n; j++) if (!vis[j] && mn > d[j]){
            mn = d[j];
            p = j;
            v = fa[j];
        }
//        cout << p << ' ' << v << endl;
        add (p, v, mp[p][v]);
        add (v, p, mp[v][p]);
    }
//    for (LL i = 1; i <= n; i++) {
//        for (LL j = 1; j <= n; j++) if (i != j){
//            e[++en].u = i, e[en].v = j, e[en].w = mp[i][j];
//        }
//    }
//    sort (e + 1, e + 1 + en, cmp);
//    for (LL i = 1; i <= n; i++) fa[i] = i;
//    for (LL i = 1; i <= en; i++) {
//        LL u = e[i].u, v = e[i].v, fu = find (u), fv = find(v);
////        cout << u << ' ' << v << endl;
//        if (fu == fv) continue;
//        fa[fu] = fv;
////        cout << u << ' ' << v << endl;
////        cout << "!" << fu <<' ' << fv << endl;
//        cnt++;
//        if (cnt == n - 1) break;
//    }

//    for (LL i = 1; i <= n; i++) {
////        cout << head[i] << endl;
//        for (LL j = head[i]; j != -1; j = e2[j].nx) {
//            cout << i <<' ' << e2[j].v << endl;
//        } cout << endl;
//    }

    for (LL i = 1; i <= n; i++) {
        if (!dij (i)) {
//                cout << i << endl;
            printf ("NO\n");
            return 0;
        }
    }

    printf ("YES\n");
}