//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define fordit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 15

//template<class T>
//T min(T a, T b, T c) {
//    return min(a, min(b, c));
//}
//T max(T a, T b, T c) {
//    return max(a, max(b, c));
//}

int bx, n, a[maxN], by, m, b[maxN];

ll to10(int n, int b, int a[]) {
    ll curP = 1;
    ll res = 0;
    fdto(i, n, 1) {
        res += a[i]*curP;
        if (i == 1) return res;
        curP *= b;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &bx);
    fto(i, 1, n) scanf("%d", &a[i]);

    scanf("%d%d", &m, &by);
    fto(i, 1, m) scanf("%d", &b[i]);

    ll x = to10(n, bx, a), y = to10(m, by, b);
    if (x < y) printf("<");
    else if (x > y) printf(">");
    else if (x == y) printf("=");

    return 0;
}