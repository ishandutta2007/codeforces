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
#define maxN 100005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n;
set<int> s, t;
map<int, int> d;

set<int> DFS(int u) {
//    if (t.find(u) != t.end()) d[u] = 1;
    set<int> l, r;
    if (s.find(2*u) != s.end()) {
        l = DFS(2*u);
//        d[u] += d[2*u];
    }
    if (s.find(2*u+1) != s.end()) {
        r = DFS(2*u+1);
//        d[u] += d[2*u+1];
    }
//    debug(u);
    if (l.size() < r.size()) swap(l, r);

    forit(it, r) l.insert(*it);
//    forit(it, l) printf("%d ", *it);
//    puts("");
//    forit(it, r) printf("%d ", *it);
//    puts("");
//    forit(it, t) printf("%d ", *it);
//    puts("");
    if (t.find(u) == t.end()) {
        l.erase(--l.end());
    }
    l.insert(u);
    return l;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        t.insert(x);
        while (x > 1) {
            s.insert(x);
            x /= 2;
        }
    }
    s.insert(1);

    set<int> ans = DFS(1);
    forit(it, ans) printf("%d ", *it);


    return 0;
}