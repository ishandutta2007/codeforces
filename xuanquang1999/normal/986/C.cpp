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
#define maxN 22
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

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

int n, m;
bool avail[1<<maxN], visited[1<<maxN][2];

int inv(int x) {return (1<<n)-1-x;}

bool isOn(int x, int i) {return (x>>i)&1;}

void DFS(int x, int type) {
    if (visited[x][type]) return;
    visited[x][type] = true;
    if (type == 0) DFS(x, 1);
    else {
        fto(i, 0, n-1) {
            if (!isOn(x, i)) DFS(x|(1<<i), 1);
        }
        if (avail[inv(x)]) DFS(inv(x), 0);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, m-1) {
        int x; scanf("%d", &x);
        avail[x] = true;
    }

    int ans = 0;
    fto(x, 0, (1<<n)-1) {
        if (avail[x] && !visited[x][0]) {
            ++ans;
            DFS(x, 0);
        }
    }

    printf("%d", ans);

    return 0;
}