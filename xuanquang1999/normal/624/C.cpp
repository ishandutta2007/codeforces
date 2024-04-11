//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 505
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, a[maxN][maxN], color[maxN], cnt, big;
//char ans[maxN];
vector<int> ke[maxN];

void DFS(int u, int c) {
    color[u] = c;
    ++cnt;
    forit(it, ke[u]) {
        int v = *it;
        if (color[v] == 0) DFS(v, 3-c);
        else if (color[v] == c) {
            puts("No");
            exit(0);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }

    fto(u, 1, n) {
        fto(v, 1, n) {
            if (u != v && !a[u][v]) ke[u].pb(v);
        }
        //printf("%d\n", ke[u].size());
    }

    fto(u, 1, n) {
        if (color[u] == 0) {
            cnt = 0;
            DFS(u, 1);
            if (cnt > 1) {
                ++big;
                if (big > 1) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }
    fto(u, 1, n) {
        if (ke[u].size() == 0) color[u] = 0;
    }
    char c[3] = {'b', 'a', 'c'};
    fto(u, 1, n) {
        fto(v, u+1, n) {
            if ((abs(c[color[u]]-c[color[v]]) < 2) ^ (a[u][v]) == 1) {
                puts("No");
                return 0;
            }
        }
    }
    puts("Yes");
    fto(i, 1, n) printf("%c", c[color[i]]);


    return 0;
}