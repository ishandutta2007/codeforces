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
#define maxN 1000005
#define MOD 1000000007
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

char tmp[maxN];
void read(string &s) {
    scanf("%s", tmp);
    s.assign(tmp);
}

ll power(ll x, int n) {
    if (n == 0) return 1;
    if (n&1) return (x*power(x, n-1))%MOD;
    ll p = power(x, n/2);
    return (p*p)%MOD;
}

int n, cnt[256], tot;
ll inv[maxN], cur, ans;
string a, b;

void add(char c) {
    ++cnt[c]; ++tot;
    cur = ((cur*tot)%MOD * inv[cnt[c]])%MOD;
}

void del(char c) {
    cur = ((cur*inv[tot])%MOD * cnt[c])%MOD;
    --cnt[c]; --tot;
}

void Try(char c) {
    if (cnt[c] > 0) {
        del(c);
        ans = (ans+cur)%MOD;
        add(c);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    read(a);
    read(b);
    n = a.length();

    fto(i, 0, n) inv[i] = power(i, MOD-2);

    int l = 0;
    while (a[l] == b[l]) ++l;

    cur = 1;
    fdto(i, n-1, l+1) {
        add(a[i]);
        fto(c, a[i]+1, 'z') Try(c);
    }
    add(a[l]);

//    debug(ans);
    fto(i, l, n-1) {
        char lim = (i == l) ? a[i]+1 : 'a';
        fto(c, lim, b[i]-1) Try(c);
//        debug(ans);
        if (cnt[b[i]] == 0) break;
        del(b[i]);
    }

    printf("%lld", ans);

    return 0;
}