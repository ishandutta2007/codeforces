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
#define maxN 1000005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

char a[maxN], b[maxN], s[2*maxN], rev[256];
int n, pref[2*maxN];

int main () {
    rev['N'] = 'S', rev['S'] = 'N', rev['W'] = 'E', rev['E'] = 'W';
    scanf("%d", &n);
    scanf("%s", a);
    fto(i, 0, n-2) a[i] = rev[a[i]];
    scanf("%s", s);
    strrev(s);
    strcat(s, a);

    int j = 0; pref[0] = 0;
    fto(i, 1, 2*n-3) {
        while (j > 0 && s[i] != s[j]) j = pref[j-1];
//        printf("%d %d\n", i, j);
        if (s[i] == s[j]) ++j;
        pref[i] = j;
    }

    puts((pref[2*n-3] == 0) ? "YES" : "NO");

    return 0;
}