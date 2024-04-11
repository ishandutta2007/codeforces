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
#define maxN 1005
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

ll mul(ll a, ll b) {
    if (a*b/a != b) return oo;
    return min(oo, a*b);
}

void read(vector<int> &a) {
    string s; cin >> s;
    fto(i, 0, sz(s)-1) a.pb(s[i]-'0');
}

int cnt[10];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ll a, b; cin >> a >> b;

    int n; ll x = a;
    while (x > 0) {
        ++cnt[x%10];
        x /= 10;
        ++n;
    }

    ll ans = 0;
    fto(i, 1, n) {
        fdto(d, 9, 0) {
            if ((i == 19 && d > 1) || cnt[d] == 0) continue;
            --cnt[d];
            x = ans*10+d;
            fto(k, 0, 9) {
                fto(j, 1, cnt[k]) x = x*10+k;
            }
            if (x <= b) {
                ans = ans*10+d;
                break;
            } else ++cnt[d];
        }
    }

    cout << ans;


    return 0;
}