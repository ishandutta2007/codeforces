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
#define maxN 2005
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

int n;
string s, t;
vector<int> ans;

void perform(int k) {
    ans.pb(k);
    string pref = s.substr(0, n-k), suff = s.substr(n-k);
    reverse(suff.begin(), suff.end());
    s = suff+pref;
//    debug(s);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s >> t;

//    fto(i, 0, n-1) {
//        pos.pb(i);
//        reverse(pos.begin(), pos.end());
//    }
//
//    fto(i, 0, n-1) rpos[pos[i]] = i;

    int pos = n/2, sign = (n%2 == 0) ? -1 : 1;
    fto(i, 0, n-1) {
        bool found = false;
        fto(j, 0, n-i-1) {
            if (s[j] == t[pos]) {
                found = true;
                perform(i);
                perform(n-j-i);
                perform(j);
                break;
            }
        }
        if (!found) {
            puts("-1");
            return 0;
        }
        pos += sign*(i+1);
        sign *= -1;
    }

//    debug(s);

    printf("%d\n", sz(ans));
    for(int x: ans) printf("%d ", x);

    return 0;
}