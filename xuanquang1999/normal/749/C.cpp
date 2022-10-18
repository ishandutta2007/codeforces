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
#define oo 3000000000000000000LL

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

int n;
char s[maxN];
bool avail[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%s", &n, s);

    int cntD = 0, cntR = 0;
    fto(i, 0, n-1) {
        if (s[i] == 'D') ++cntD;
        else ++cntR;
    }
    memset(avail, true, sizeof avail);
    int i = 0, j = 0;
    while (true) {
        if (cntR == 0) {puts("D"); return 0;}
        if (cntD == 0) {puts("R"); return 0;}
        while (s[i%n] != 'D' || !avail[i%n]) i = i+1;
        while (s[j%n] != 'R' || !avail[j%n]) j = j+1;
        //printf("%d %d %d %d\n", i, j, cntD, cntR);
        if (i < j) {
            --cntR;
            avail[j%n] = false;
            ++i;
        }
        else {
            --cntD;
            avail[i%n] = false;
            ++j;
        }
    }


    return 0;
}