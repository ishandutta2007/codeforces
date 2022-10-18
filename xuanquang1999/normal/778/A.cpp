//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 400005
#define oo 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

void fastCin(string &s) {
    char tmp[maxN];
    scanf("%s", tmp);
    s.assign(tmp);
}

string s, t;
int n, p[maxN];
bool avail[maxN];

bool Check(int mid) {
    memset(avail, true, sizeof avail);
    fto(i, 1, mid) avail[p[i]] = false;

    string w;
    fto(i, 1, n) {
        if (avail[i]) w += s[i-1];
    }

    int i = 0;
    fto(j, 0, t.length()-1) {
        while (i < w.length() && w[i] != t[j]) ++i;
        if (i == w.length()) return false;
        ++i;
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    fastCin(s);
    fastCin(t);
    n = s.length();
    fto(i, 1, n) scanf("%d", &p[i]);

    int l = 0, r = n, res = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (Check(mid)) {
            res = mid;
            l = mid+1;
        } else r = mid-1;
    }

    printf("%d", res);

    return 0;
}