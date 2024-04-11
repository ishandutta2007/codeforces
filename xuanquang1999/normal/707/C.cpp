//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n;
map<int, int> m;
ll x;

void Try(map<int, int>::iterator it) {
    if (x > n) return;
    if (it == m.end()) {
        ll y = (ll)n*n/x;
        if ((x+y)%2 == 0) {
            ll b = (x+y)/2;
            ll c = y-b;
            if (b > 0 && c > 0) {
                cout << b << " " << c;
                exit(0);
            }
        }
        return;
    }
    Try(++it);
    --it;
    fto(i, 1, it->ss*2) {
        x *= it->ff;
        Try(++it);
        --it;
        x /= it->ff;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    x = n;
    fto(a, 2, (int)sqrt(n)) {
        while (n%a == 0) {
            n /= a;
            ++m[a];
        }
    }
    if (n > 1) ++m[n];
    n = x;
//    forit(it, m) printf("%d %d\n", it->ff, it->ss);
    x = 1;
    Try(m.begin());

    puts("-1");

    return 0;
}