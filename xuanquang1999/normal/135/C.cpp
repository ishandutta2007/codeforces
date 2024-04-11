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
#define maxN 100005
#define oo 2000000007
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

int n, a, b, c;
string s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s;
    int n = s.length();
    fto(i, 0, n-1) {
        if (s[i] == '1') ++a;
        if (s[i] == '0') ++b;
        if (s[i] == '?') ++c;
    }

    vector<string> ans;
    if (a < b+c) ans.pb("00");
    if (s[n-1] != '0') {
        if (s[n-1] == '?') --c, ++a;
        int x = b + c - a + n%2;
        if (x >= 0 && x <= 2*c && x%2 == 0) ans.pb("01");
        if (s[n-1] == '?') ++c, --a;
    }
    if (s[n-1] != '1') {
        if (s[n-1] == '?') --c, ++b;
        int x = b + c - a + n%2;
        if (x >= 0 && x <= 2*c && x%2 == 0) ans.pb("10");
        if (s[n-1] == '?') ++c, --b;
    }
    if (a+c > b+1) ans.pb("11");

    forit(it, ans) cout << *it << endl;

    return 0;
}