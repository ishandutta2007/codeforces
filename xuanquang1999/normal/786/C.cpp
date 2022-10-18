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
#define oo 1000000000000000007LL
#define maxN 100005
#define EPS 1e-9
#define sz(a) (int)a.size()
#define next pleaseLetMeUseThisVariable
#define prev pleaseLetMeUseThisVariableToo

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

int n, a[maxN], prev[maxN], next[maxN], last[maxN], t[(1<<17)+1], ans[maxN];
vector<int> Q[maxN];

void add(int p, int x) {
    for(int i = p; i <= (1<<17); i += i&(-i)) t[i] += x;
}

int query(int x) {
    int res = 0, sum = 0;
    for(int i = (1<<17); i > 0; i >>= 1) {
        if (sum+t[res+i] <= x) {
            sum += t[res+i];
            res += i;
        }
        //printf("%d %d\n", res, sum);
    }
    return min(n, res);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) last[i] = n+1;
    fdto(i, n, 1) {
        next[i] = last[a[i]];
        prev[next[i]] = i;
        last[a[i]] = i;
    }

    //fto(i, 1, n) printf("%d %d %d\n", a[i], next[i], prev[i]);

    fto(i, 1, n) {
        if (prev[i] == 0) add(i, 1);
        Q[1].pb(i);
        //ans[i] = 1;
    }
    //fto(i, 1, 10) printf("%d ", t[i]);
    //puts("");
    //debug(query(3));
    //return 0;
    fto(i, 1, n) {
        //debug(i);
        forit(it, Q[i]) {
            int x = query(*it);
            //printf("%d %d\n", *it, x);
            Q[x+1].pb(*it);
            ++ans[*it];
        }
        add(i, -1);
        add(next[i], 1);
    }

    fto(i, 1, n) printf("%d ", ans[i]);

    return 0;
}