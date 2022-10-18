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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, c[maxN];
bool visited[maxN];
vector<int> ke[maxN], ans;


int DFS(int u) {
    ans.pb(u);
    visited[u] = true;
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) {
            c[v] *= -1;
            DFS(v);
            ans.pb(u);
            c[u] *= -1;
            if (c[v] == -1) {
                ans.pb(v);
                ans.pb(u);
                c[u] *= -1;
                c[v] *= -1;
            }
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    int sum = 0;
    fto(i, 1, n) {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    if (sum == n) {
        puts("1");
        return 0;
    }

    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
        ke[v].pb(u);
    }

    DFS(1);

    if (c[1] == -1) {
        ans.pb(*ke[1].begin());
        ans.pb(1);
        ans.pb(*ke[1].begin());
    }
    forit(it, ans) printf("%d ", *it);


    return 0;
}