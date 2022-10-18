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

int n, x[3];
string s[3], name[3];

int Solve(const string &s) {
    vector<int> cnt(256, 0);
    for(char c: s) ++cnt[c];

    int ans = 0;
    fto(c, 0, 255) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            int x = min((int)s.length(), cnt[c]+n);
            if (n == 1 && cnt[c] == s.length())
                x = max(x-1, 1);
            ans = max(ans, x);
        }
    }

    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    name[0] = "Kuro";
    name[1] = "Shiro";
    name[2] = "Katie";

    ios::sync_with_stdio(false);
    cin >> n;

    string winner;
    int maxX = 0;
    fto(i, 0, 2) {
        cin >> s[i];
        x[i] = Solve(s[i]);
        maxX = max(maxX, x[i]);
    }

    fto(i, 0, 2) {
        if (x[i] == maxX) {
            if (winner == "") winner = name[i];
            else {
                cout << "Draw";
                return 0;
            }
        }
    }

    cout << winner;

    return 0;
}