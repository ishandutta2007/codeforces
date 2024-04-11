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

int reduce(int &a, int &b) {
    fto(i, 2, min(a, b))
        while (a%i == 0 && b%i == 0) {
            a /= i;
            b /= i;
        }
}

int n, p[maxN], q[maxN];

int toStr(string s) {
    stringstream ss(s);
    int x; ss >> x;
    return x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    cin >> n;
    map<ii, int> m;
    fto(i, 1, n) {
        string s;
        cin >> s;

        int pos1 = s.find("+"), pos2 = s.find("/");
        int a = toStr(s.substr(1, pos1-1));
        int b = toStr(s.substr(pos1+1, pos2-pos1-2));
        int c = toStr(s.substr(pos2+1, sz(s)-pos2-1));
        //cout << a << " " << b << " " << c << endl;

        p[i] = a+b; q[i] = c;
        reduce(p[i], q[i]);
        ++m[mp(p[i], q[i])];
    }

    fto(i, 1, n) cout << m[mp(p[i], q[i])] << " ";



    return 0;
}