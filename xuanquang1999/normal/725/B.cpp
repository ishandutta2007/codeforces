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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

ll r, c, ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    char ch;
    while (scanf("%c", &ch) != EOF) {
        if ('0' <= ch && ch <= '9') r = r*10 + ch-'0';
        else {
            c = ch-'a';
            break;
        }
    }
    --r;
//    debug(r);
//    debug(c);

    ans = 16*(r/4);
    r %= 4;
    if (r == 0) ans += 0;
    if (r == 1) ans += 7;
    if (r == 2) ans += 0;
    if (r == 3) ans += 7;

    if (c == 5) ans += 1;
    if (c == 4) ans += 2;
    if (c == 3) ans += 3;
    if (c == 2) ans += 6;
    if (c == 1) ans += 5;
    if (c == 0) ans += 4;

    cout << ans;

    return 0;
}