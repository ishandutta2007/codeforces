#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969
#define free FREE

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

const int MAX = 3000000;

int n;
int m, o;
int tree[MAX];
int sl[MAX], sr[MAX], L[MAX], R[MAX];
map<int, int> pr, all;
set<pair<int, ii> > free;

int del (int l, int r) {
    pr.erase (l);
    pr.erase (r);
    free.erase (mp (r - l + 1, mp (l, r)));
    re 0;
}

int add (int l, int r) {
    if (l <= r) {
        pr[l] = r;
        pr[r] = l;
        free.insert (mp (r - l + 1, mp (l, r)));
    }
    re 0;
}

ii get (int x) {
    if (pr.count (x)) {
        int y = pr[x];
        if (x > y) swap (x, y);
        re mp (x, y);
    }
    re mp (-1, -1);
}

int upd (int x, int y, int z) {
    if (L[x] > y || R[x] < y) re 0;
    if (L[x] == R[x]) {
        tree[x] += z;
        re 0;
    }
    int s = (L[x] + R[x]) / 2;
    if (y <= s) {
        if (sl[x] == -1) {
            sl[x] = o;
            L[o] = L[x];
            R[o] = s;
            sl[o] = sr[o] = -1;
            tree[o] = 0;
            o++;
        }
        upd (sl[x], y, z);
    } else {
        if (sr[x] == -1) {
            sr[x] = o;
            L[o] = s + 1;
            R[o] = R[x];
            sl[o] = sr[o] = -1;
            tree[o] = 0;
            o++;
        }
        upd (sr[x], y, z);
    }
    tree[x] += z;
    re 0;
}

int get (int x, int l, int r) {
    if (L[x] > r || R[x] < l) re 0;
    if (L[x] >= l && R[x] <= r) re tree[x];
    int res = 0;
    if (sl[x] != -1) res += get (sl[x], l, r);
    if (sr[x] != -1) res += get (sr[x], l, r);
    re res;
}

int main() {
    scanf ("%d%d", &m, &n);
    o = 1;
    L[0] = 1;
    R[0] = m;
    sl[0] = sr[0] = -1;
    tree[0] = 0;
    free.insert (mp (m, mp (1, m)));
    pr[1] = m;
    pr[m] = 1;
    for (int i = 0; i < n; i++) {
        int x, y, l, r;
        scanf ("%d", &x);
        if (x == 0) {
            scanf ("%d%d", &l, &r);
            printf ("%d\n", get (0, l, r));
        } else {
            if (all.count (x)) {
                y = all[x];
                upd (0, y, -1);
                all.erase (x);
                ii al = get (y - 1);
                ii ar = get (y + 1);
                l = r = y;
                if (al.fi != -1) { del (al.fi, al.se); l = al.fi; }
                if (ar.fi != -1) { del (ar.fi, ar.se); r = ar.se; }
                add (l, r);
            } else {
                pair<int, ii> cur = *free.rbegin ();
                l = cur.se.fi;
                r = cur.se.se;
                del (l, r);
                int y = (l + r + 1) / 2;
                upd (0, y, 1);
                add (l, y - 1);
                add (y + 1, r);
                all[x] = y;
            }   
        }
    }
    return 0;
}