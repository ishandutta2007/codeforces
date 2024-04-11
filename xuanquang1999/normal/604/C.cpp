//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 100005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN];
char s[maxN];

int Flip(int l, int r) {
    fto(i, l, r) a[i] = 1-a[i];
}

void Work() {
    fto(i, 2, n-1)
        if (a[i-1] == a[i] && a[i] == a[i+1]) {
            Flip(i, i);
            return;
        }

    int x[3], cnt = 0;
    fto(i, 1, n-1) {
        if (a[i] == a[i+1]) {
            ++cnt;
            x[cnt] = i;
        }
        if (cnt == 2) {
            Flip(x[1]+1, x[2]);
            return;
        }
    }

    if (cnt == 1) Flip(1, x[1]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%s", &n, s);
    fto(i, 1, n) a[i] = (s[i-1]-'0');

    Work();
    int ans = 1, cur = a[1];
    fto(i, 2, n) {
        if (a[i] == 1-cur) {
            ++ans;
            cur = 1-cur;
        }
    }

    cout << ans;

    return 0;
}