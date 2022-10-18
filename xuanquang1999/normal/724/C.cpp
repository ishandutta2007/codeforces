//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int m, n, k, x[maxN], y[maxN], l[maxN], r[maxN], u[maxN], d[maxN];
ll ans[maxN];
vector<int> sc[maxN], sr[maxN];

int mapX(int x, int y) {
    return x+y-1;
}

int mapY(int x, int y) {
    return y+n-x;
}

void update(int x, int y) {
    int _x = x+y-1, _y = y+n-x;
    l[_x] = min(l[_x], _y);
    r[_x] = max(r[_x], _y);
    u[_y] = min(u[_y], _x);
    d[_y] = max(d[_y], _x);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    ++n, ++m;
    fto(i, 1, k) {
        int u, v;
        scanf("%d%d", &u, &v); ++u, ++v;
        x[i] = u+v-1, y[i] = v+n-u;
        sr[x[i]].pb(i), sc[y[i]].pb(i);
        ans[i] = -1;
    }

//    fto(i, 1, k) printf("%d %d\n", x[i], y[i]);

    fto(i, 1, n+m-1) l[i] = u[i] = maxN;
    fto(i, 1, n) update(i, 1), update(i, m);
    fto(j, 1, m) update(1, j), update(n, j);

//    fto(i, 1, n+m-1) printf("%d %d %d %d\n", l[i], u[i], r[i], d[i]);

    int a = 1, b = n, dir = 0;
    ll t = 0;
    //d = 0: down
    //d = 1: right
    //d = 2: up
    //d = 3: left
    while (true) {
//        printf("%d %d\n", a, b);
        if (dir == 0) {
            forit(it, sc[b]) {
                if (ans[*it] == -1) ans[*it] = (t+x[*it]-a)/2;
            }
            if (d[b] == a) break;
            t += d[b]-a; a = d[b];
            if (r[a] > b) dir = 1;
            else dir = 3;
        }
        else if (dir == 1) {
            forit(it, sr[a]) {
                if (ans[*it] == -1) ans[*it] = (t+y[*it]-b)/2;
            }
            if (r[a] == b) break;
            t += r[a]-b; b = r[a];
            if (d[b] > a) dir = 0;
            else dir = 2;
        }
        else if (dir == 2) {
            forit(it, sc[b]) {
                if (ans[*it] == -1) ans[*it] = (t+a-x[*it])/2;
            }
            if (u[b] == a) break;
            t += a-u[b]; a = u[b];
            if (r[a] > b) dir = 1;
            else dir = 3;
        }
        else if (dir == 3) {
            forit(it, sr[a]) {
                if (ans[*it] == -1) ans[*it] = (t+b-y[*it])/2;
            }
            if (l[a] == b) break;
            t += b-l[a]; b = l[a];
            if (d[b] > a) dir = 0;
            else dir = 2;
        }
//        dir = (dir+1)%4;
    }

    fto(i, 1, k) printf("%I64d\n", ans[i]);


    return 0;
}