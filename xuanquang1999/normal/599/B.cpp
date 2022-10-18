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
#define maxN 100005

//template<class T>
//T min(T a, T b, T c) {
//    return min(a, min(b, c));
//}
//T max(T a, T b, T c) {
//    return max(a, max(b, c));
//}

int n, m, f[maxN], b[maxN], pos[maxN], cnt[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &f[i]);
    fto(i, 1, m) scanf("%d", &b[i]);

    fto(i, 1, n) {
        pos[f[i]] = i;
        ++cnt[f[i]];
    }

    fto(i, 1, m)
        if (cnt[b[i]] == 0) {
            puts("Impossible");
            return 0;
        }

    fto(i, 1, m)
        if (cnt[b[i]] > 1) {
            puts("Ambiguity");
            return 0;
        }

    puts("Possible");
    fto(i, 1, m) printf("%d ", pos[b[i]]);


    return 0;
}