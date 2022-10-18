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
#define oo 1000000007
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

const string VOWEL = "AEIOU";
int n, d[maxN];
string s;

struct BIT {
private: vector<int> t;
public:
    BIT(int n) {t.assign(n+1, oo);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] = min(t[i], x);
    }
    int query(int p) {
        int res = oo;
        for(int i = p; i > 0; i -= i&(-i)) res = min(res, t[i]);
        return res;
    }
};

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s; n = s.length();

    fto(i, 1, n) {
        int x = (VOWEL.find(toupper(s[i-1])) != string::npos) ? -1 : 2;
        d[i] = d[i-1]+x;
    }

    BIT t(3*n+1);

    int maxLen = 0, cntAns = 0;
    fto(i, 0, n) {
        int len = i-t.query(d[i]+n+1);
        if (len > maxLen) {
            maxLen = len;
            cntAns = 0;
        }
        if (len == maxLen) ++cntAns;

        t.update(d[i]+n+1, i);
    }

    if (maxLen == 0) puts("No solution");
    else printf("%d %d", maxLen, cntAns);

    return 0;
}