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

void read(vector<int> &s) {
    string tmp;
    cin >> tmp;
    s.clear();
    s.pb(0);
    for(char c: tmp) s.pb(c-'0');
}

int nTest, n, f[maxN];
vector<int> s, ans;

bool Check(int i, int mask, bool lo) {
    vector<int> miss;
    fto(d, 0, 9)
        if (mask&(1<<d)) miss.pb(d);

//    printf("%d %d %d\n", i, mask, lo);
//    for(int x: miss) printf("%d ", x);
//    puts("");

    if (n-i < sz(miss)) return false;
    if (lo || f[n-sz(miss)]-f[i] < n-sz(miss)-i) return true;

    fto(j, 1, sz(miss)) {
        if (miss[j-1] > s[n-sz(miss)+j]) return false;
        if (miss[j-1] < s[n-sz(miss)+j]) return true;
    }
    return false;
}

void Solve() {
    read(s);
    n = sz(s)-1;

    f[0] = 0;
    fto(i, 1, n) f[i] = f[i-1]+(s[i] == 0);

    int mask = 0;
    bool lo = false;
    ans.assign(n+1, -1);
    fto(i, 1, n) {
        int upb = (lo) ? 9 : s[i], lob = (i == 1) ? 1 : 0;
        fdto(d, upb, lob) {
            int newMask = mask^(1<<d);
            bool newLo = lo|(d < s[i]);
            if (Check(i, newMask, newLo)) {
                ans[i] = d;
                mask = newMask;
                lo = newLo;
                break;
            }
        }
        if (ans[i] == -1) {
            fto(i, 1, n-2) printf("9");
            puts("");
            return;
        }
    }

    fto(i, 1, n) printf("%d", ans[i]);
    puts("");
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &nTest);
    fto(iTest, 1, nTest) {
        Solve();
    }

    return 0;
}