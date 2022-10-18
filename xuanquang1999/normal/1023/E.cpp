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

const int MAXN = 505;
int n, q, a[MAXN];
string s;

bool ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    string res; cin >> res;
    return (res == "YES");
}

int main () {
    scanf("%d", &n);

    string s1;
    int x = 1, y = 1;
    fto(i, 1, n-1) {
        if (x < n && ask(x+1, y, n, n)) {
            ++x;
            s1 += 'D';
        } else {
            ++y;
            s1 += 'R';
        }
    }

    string s2;
    int u = n, v = n;
    fto(i, 1, n-1) {
        if (v > 1 && ask(1, 1, u, v-1)) {
            --v;
            s2 += 'R';
        } else {
            --u;
            s2 += 'D';
        }
    }

    reverse(s2.begin(), s2.end());
    cout << "! " << s1 + s2 << endl;
    fflush(stdout);


    return 0;
}