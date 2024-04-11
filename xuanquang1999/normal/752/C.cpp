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

int n, dx[256], dy[256];
char s[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    dx['D'] = 1; dy['D'] = 0;
    dx['U'] = -1; dy['U'] = 0;
    dx['L'] = 0; dy['L'] = -1;
    dx['R'] = 0; dy['R'] = 1;

    scanf("%d", &n);
    scanf("%s", s);

    int lastX = 0, lastY = 0, x = 0, y = 0, cnt = 0, ans = 1;
    fto(i, 0, n-1) {
        if (abs(x+dx[s[i]]-lastX)+abs(y+dy[s[i]]-lastY) < cnt+1) {
            ++ans;
            lastX = x; lastY = y;
            cnt = 0;
        }
        x += dx[s[i]]; y += dy[s[i]];
        ++cnt;
    }

    printf("%d", ans);

    return 0;
}