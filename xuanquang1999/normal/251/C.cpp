//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define X real()
#define Y imag()
#define maxN 400005
#define oo 2000000007
#define EPS 1e-9

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

ll a, b;
int k, m;

int GCD(int a, int b) {return (b == 0) ? a : GCD(b, a%b);}
int LCM(int a, int b) {return a/GCD(a, b)*b;}

void Update(queue<int> &q, vector<int> &d, const int &u, const int &v) {
    if (!d[v]) {
        d[v] = d[u]+1;
        q.push(v);
    }
}

void DFS(int s, vector<int> &d) {
    d.assign(s+1, 0); d[s] = 1;
    queue<int> q; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u > 0) Update(q, d, u, u-1);
        fto(i, 1, k) Update(q, d, u, u-u%i);
    }
    fto(i, 0, s) --d[i];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> a >> b >> k;
    m = 1;
    fto(i, 2, k) m = LCM(m, i);

    ll ans = 0;

    vector<int> d;
    DFS(a%m, d);
    if (a/m == b/m) ans = d[b%m];
    else {
        ans = d[0];
        DFS(m, d);
        ans += d[0]*(a/m-b/m-1);
        ans += d[b%m];
    }

    cout << ans;


    return 0;
}