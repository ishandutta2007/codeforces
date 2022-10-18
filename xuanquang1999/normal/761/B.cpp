//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ftoa(i, l, r, a) for(int i = (l); i <= (r); i += a)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 105
#define maxK 20
#define MOD 1000000007

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

int n, L, a[maxN], b[maxN], c[maxN], d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &L);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    fto(i, 0, n-1) scanf("%d", &b[i]);

    fto(i, 0, n-2) c[i] = a[i+1]-a[i];
    c[n-1] = a[0]+L-a[n-1];
    fto(i, 0, n-2) d[i] = b[i+1]-b[i];
    d[n-1] = b[0]+L-b[n-1];

    fto(i, 0, n-1) {
        bool ok = true;
        fto(j, 0, n-1) {
            if (d[(i+j)%n] != c[j%n]) {ok = false; break;}
        }
        if (ok) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}