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
#define maxK 20
#define oo 1000000007

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

int a, b, c, d;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d", &a, &b, &c, &d);

    string ans = "";
    if (c == d-1) {
        if (a < d || b < d) {puts("-1"); return 0;}
        ans += "74";
        fto(i, 1, a-d) ans += "4";
        fto(i, 1, d-2) ans += "74";
        fto(i, 1, b-d) ans += "7";
        ans += "74";
    }
    else if (c-1 == d) {
        if (a < c || b < c) {puts("-1"); return 0;}
        fto(i, 1, a-c) ans += "4";
        fto(i, 1, c) ans += "47";
        fto(i, 1, b-c) ans += "7";
    }
    else if (c == d) {
        if (a >= c+1 && b >= d) {
            fto(i, 1, a-c-1) ans += "4";
            fto(i, 1, c) ans += "47";
            fto(i, 1, b-c) ans += "7";
            ans += "4";
        }
        else if (a == d && b >= c+1) {
            fto(i, 1, c) ans += "74";
            fto(i, 1, b-c) ans += "7";
        }
        else ans = "-1";
    }
    else ans = "-1";

    printf("%s", ans.c_str());

    return 0;
}