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
#define maxN 1005
#define maxK 20
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

void maximize(int &a, int b) {a = max(a, b);}

int n, m, W, b[maxN], w[maxN], f[maxN][maxN];
vector<int> ke[maxN], ver;
bool visited[maxN];

void DFS(int u) {
    ver.pb(u);
    visited[u] = true;
    forit(it, ke[u]) {
        int v = *it;
        if (!visited[v]) DFS(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &W);
    fto(i, 1, n) scanf("%d", &w[i]);
    fto(i, 1, n) scanf("%d", &b[i]);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    int i = 0;
    fto(u, 1, n) {
        if (!visited[u]) {
            ++i;
            ver.clear();
            DFS(u);
//            forit(it, ver) printf("%d ", *it);
//            puts("");
            int sumB = 0, sumW = 0;
            fto(j, 0, W) f[i][j] = f[i-1][j];
            forit(it, ver) {sumB += b[*it]; sumW += w[*it];}
            fto(j, sumW, W) maximize(f[i][j], f[i-1][j-sumW]+sumB);
            forit(it, ver) {
                fto(j, w[*it], W) maximize(f[i][j], f[i-1][j-w[*it]] + b[*it]);
            }
        }
    }
//    fto(I, 0, i) {
//        fto(j, 0, W) printf("%d ", f[I][j]);
//        puts("");
//    }


    cout << *max_element(f[i], f[i]+W+1);

    return 0;
}