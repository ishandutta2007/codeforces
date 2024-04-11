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
#define maxN 200005
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

string T[256], F[256], E[256];
bool stop;

void update(string &a, string b) {
    if (a == "" || sz(a) > sz(b) || (sz(a) == sz(b) && a > b)) {
        stop = false;
        a = b;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    F[0b11110000] = "x";
    F[0b11001100] = "y";
    F[0b10101010] = "z";

    while (true) {
        stop = true;

        fto(i, 0, 255) if (T[i] != "")
            fto(j, 0, 255) if (F[j] != "") update(T[i&j], T[i]+"&"+F[j]);
        fto(i, 0, 255) if (E[i] != "")
            fto(j, 0, 255) if (T[j] != "") update(E[i|j], E[i]+"|"+T[j]);
        fto(i, 0, 255) if (E[i] != "") update(F[i], "("+E[i]+")");
        fto(i, 0, 255) if (T[i] != "") update(E[i], T[i]);
        fto(i, 0, 255) if (F[i] != "") update(T[i], F[i]);
        fto(i, 0, 255) if (F[i] != "") update(F[i^255], "!"+F[i]);

        if (stop) break;
    }

    int nTest; scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        char s[9]; scanf("%s", s);
        int mask = 0;
        fto(i, 0, 7)
            if (s[i]-'0') mask |= 1<<i;

        cout << E[mask] << endl;
    }

    return 0;
}