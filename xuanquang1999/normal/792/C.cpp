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

string s, ans;
bool erased[maxN];
int n;

void tryErase(int d, int k) {
    fto(i, 0, n-1) erased[i] = false;
    int cnt = 0;
    fdto(i, n-1, 0) {
        if ((s[i]-'0')%3 == d) {
            ++cnt;
            erased[i] = true;
        }
        if (cnt == k) break;
    }
    if (cnt < k) return;

    string t;
    fdto(i, n-1, 0) {
        if (!erased[i]) t += s[i];
    }
    while (t.size() > 1 && *t.rbegin() == '0') t.erase(t.length()-1);
    reverse(t.begin(), t.end());

//    printf("%d %d\n", d, k);
//    debug(t);
    if (t.length() == 0) return;
    if (ans == "-1" || t.length() > ans.length()) ans = t;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s; n = s.length();

    int sum = 0;
    fto(i, 0, n-1) sum = (sum+s[i]-'0')%3;

    if (sum == 0) ans = s;
    else {
        ans = "-1";
        if (sum == 1) {
            tryErase(1, 1);
            tryErase(2, 2);
        } else {
            tryErase(2, 1);
            tryErase(1, 2);
        }
    }

    cout << ans;

    return 0;
}