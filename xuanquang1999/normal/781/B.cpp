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
#define maxN 3005
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

int n, f[maxN][maxN], c[maxN][maxN], trace[maxN], delta[maxN];
vector<int> ke[maxN];

void addEdge(int u, int v, int w) {
    ++u; ++v;
    c[u][v] = w;
    ke[u].pb(v); ke[v].pb(u);
}

bool findPath(int s, int t) {
    queue<int> q; q.push(s);
    memset(trace, 0, sizeof trace);
    trace[s] = s;
    delta[s] = oo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
//        debug(u);
        forit(it, ke[u]) {
            int v = *it;
            if (!trace[v]) {
                if (c[u][v] > f[u][v]) {
                    delta[v] = min(delta[u], c[u][v]-f[u][v]);
                    trace[v] = u;
                    q.push(v);
                } else if (f[v][u] > 0) {
                    delta[v] = min(delta[u], f[v][u]);
                    trace[v] = -u;
                    q.push(v);
                }
            }
        }
    }
    return (trace[t] != 0);
}

int incFlow(int s, int t) {
    int v = t;
    while (v != s) {
        int u = trace[v];
        if (u > 0) f[u][v] += delta[t];
        else {
            u = -u;
            f[v][u] -= delta[t];
        }
        v = u;
    }
    //debug(delta[t]);
    return delta[t];
}

int maxFlow(int s, int t) {
    ++s; ++t;
    int ret = 0;
    while (findPath(s, t)) ret += incFlow(s, t);
    return ret;
}

string cn[maxN], hn[maxN], s[maxN], t[maxN], rm[maxN];
map<string, int> ma, cnts;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    //debug(n);
    fto(i, 1, n) {
        cin >> cn[i] >> hn[i];
        s[i] = cn[i].substr(0, 3);
        t[i] = cn[i].substr(0, 2)+hn[i].substr(0, 1);
        if (ma.find(s[i]) == ma.end()) ma[s[i]] = ma.size(), rm[ma.size()] = s[i];
        if (ma.find(t[i]) == ma.end()) ma[t[i]] = ma.size(), rm[ma.size()] = t[i];
        ++cnts[s[i]];
//        debug(s[i]);
//        debug(t[i]);

    }

    fto(i, 1, n) {
        addEdge(0, i, 1);
        if (cnts[s[i]] == 1) addEdge(i, n+ma[s[i]], 1);
        addEdge(i, n+ma[t[i]], 1);
    }
    fto(i, 1, ma.size()) addEdge(n+i, n+ma.size()+1, 1);
//    fto(i, 0, n+ma.size()+1) {
//        forit(it, ke[i]) printf("%d %d %d\n", i, *it, c[i][*it]);
//    }

    int x = maxFlow(0, n+ma.size()+1);
    //return 0;
    if (x < n) puts("NO");
    else {
        puts("YES");
        fto(u, 1, n) {
            if (f[u+1][n+ma[s[u]]+1] > 0) cout << s[u] << endl;
            else cout << t[u] << endl;
        }
    }





    return 0;
}