//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
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
#define ll long long
#define maxN 1005
#define MOD 1000000007
#define fmin PleaseLetMeUseThatVariableName

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, f[maxN], fmin[maxN], a[256], cnt[256];
string s;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    cin >> s;
    fto(c, 'a', 'z') scanf("%d", &a[c]);

    f[0] = 1;
    fmin[0] = 0;
    int lmax = 0;
    fto(i, 1, n) {
        fmin[i] = maxN;

        memset(cnt, 0, sizeof cnt);
        fdto(j, i-1, 0) {
            ++cnt[s[j]];
            bool ok = true;
            fto(c, 'a', 'z') {
                if (cnt[c] > 0 && i-j > a[c]) {ok = false; break;}
            }
            if (!ok) break;
            f[i] = (f[i]+f[j])%MOD;
            fmin[i] = min(fmin[i], fmin[j]+1);
            lmax = max(lmax, i-j);
        }
    }

    printf("%d\n%d\n%d\n", f[n], lmax, fmin[n]);



    return 0;
}