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
#define maxN 100005
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

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string t1 = "What are you doing while sending \"";
string t2 = "\"? Are you busy? Will you send \"";
string t3 = "\"?";

ll f[100005];

char Solve(int n, ll k) {
    if (k >= f[n]) return '.';
    if (n == 0) return s[k];
    if (k >= sz(t1)+f[n-1]+sz(t2)+f[n-1]) return t3[k-(sz(t1)+f[n-1]+sz(t2)+f[n-1])];
    if (k >= sz(t1)+f[n-1]+sz(t2)) return Solve(n-1, k-(sz(t1)+f[n-1]+sz(t2)));
    if (k >= sz(t1)+f[n-1]) return t2[k-(sz(t1)+f[n-1])];
    if (k >= sz(t1)) return Solve(n-1, k-sz(t1));
    return t1[k];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    f[0] = sz(s);
    fto(i, 1, 100000) f[i] = min(oo, 2*f[i-1]+sz(t1)+sz(t2)+sz(t3));

    int q; scanf("%d", &q);
    fto(i, 1, q) {
        int n; ll k;
        scanf("%d%lld", &n, &k);
        printf("%c", Solve(n, k-1));
    }

    return 0;
}