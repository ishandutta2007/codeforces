//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define X real()
#define Y imag()
#define maxN 200005
#define oo 2000000007

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

bool cmp(const point &a, const point &b) {
    return a.X < b.X;
}

int n, a[maxN], par[maxN], color[maxN];
vector<int> ke[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    queue<int> q;
    q.push(1); color[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int cur = 1;
        forit(it, ke[u]) {
            int v = *it;
            if (v != par[u]) {
                par[v] = u;
                while (cur == color[u] || (par[u] != -1 && cur == color[par[u]])) ++cur;
                color[v] = cur; ++cur;
                q.push(v);
            }
        }
    }

    printf("%d\n", *max_element(color+1, color+n+1));
    fto(u, 1, n) printf("%d ", color[u]);


    return 0;
}