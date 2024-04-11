//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define MOD 1000000007
#define oo 1000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ii o_pair(int u, int v) {return (u < v) ? mp(u, v): mp(v, u);}

int n, m, r[maxN], s[maxN];
vector<int> t[maxN], ke[maxN], save;
map<ii, int> e;
bool visited[maxN];

void DFS(int u, int c) {
    visited[u] = true;
    save.pb(u);
    s[u] = c;
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) DFS(v, !(e[o_pair(u, v)]^s[u]));
    }
}

bool Check() {
    forit(it1, save) {
        int a = *it1;
        forit(it2, ke[a]) {
            int b = *it2;
            //printf("%d %d %d\n", a, b, e[o_pair(a, b)]);
            if (!(e[o_pair(a, b)]^s[a]^s[b])) return false;
        }
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &r[i]);
    fto(i, 1, m) {
        int k; scanf("%d", &k);
        fto(j, 1, k) {
            int u; scanf("%d", &u);
            t[u].pb(i);
        }
    }

    fto(i, 1, n) {
        ke[t[i][0]].pb(t[i][1]);
        ke[t[i][1]].pb(t[i][0]);
        ii p = o_pair(t[i][0], t[i][1]);
        if (e.find(p) == e.end()) e[p] = r[i];
        else if (e[p] != r[i]) {
            puts("NO");
            return 0;
        }
    }

//    forit(it, e) printf("%d %d %d\n", it->ff.ff, it->ff.ss, it->ss);

    fto(u, 1, m) {
        if (!visited[u]) {
            save.clear();
            DFS(u, 0);
//            debug(u);
//            fto(v, 1, m) printf("%d ", s[v]);
//            puts("");
            if (!Check()) {
                forit(it, save) visited[*it] = false;
                save.clear();
                DFS(u, 1);
//                debug(u);
//                fto(v, 1, m) printf("%d ", s[v]);
//                puts("");
                if (!Check()) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    puts("YES");


    return 0;
}