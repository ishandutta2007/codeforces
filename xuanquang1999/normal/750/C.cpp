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

int n, c[maxN], d[maxN];

bool CheckD2(int x) {
    fto(i, 1, n) {
        if (d[i] == 2 && x > 1899) return false;
        x += c[i];
    }
    return true;
}

bool CheckD1(int x) {
    fto(i, 1, n) {
        if (d[i] == 1 && x < 1900) return false;
        x += c[i];
    }
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d%d", &c[i], &d[i]);

    int l = -oo, r = oo, resR = l-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (CheckD2(mid)) {
            resR = max(resR, mid);
            l = mid+1;
        }
        else r = mid-1;
    }

    l = -oo, r = oo; int resL = r+1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (CheckD1(mid)) {
            resL = min(resL, mid);
            r = mid-1;
        }
        else l = mid+1;
    }

    if (resL > resR) puts("Impossible");
    else if (resR == oo) puts("Infinity");
    else {
        fto(i, 1, n) resR += c[i];
        printf("%d\n", resR);
    }


    return 0;
}