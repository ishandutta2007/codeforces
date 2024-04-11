//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
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
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

char s[maxN], ans[maxN];
int n, cnt[256];


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%s", s);
    strcpy(ans, s);
    int n = strlen(s);
    fto(i, 0, n-1) ++cnt[s[i]];

    char c1 = 'a', c2 = 'z';
    while (true) {
        while (c1 < c2 && cnt[c1]%2 == 0) ++c1;
        while (c1 < c2 && cnt[c2]%2 == 0) --c2;
        if (c1 >= c2) break;
        --cnt[c2];
        ++c1;
        --c2;
    }
    if (n%2 == 1 && cnt[c1]%2 == 1) {
        ans[n/2] = c1;
        --cnt[c1];
    }
    int i = 0;
    fto(c, 'a', 'z') {
//        if (cnt[c]%2 == 0) {
//            fto(j, 1, cnt[c]/2) {
//                ans[i] = ans[n-i-1] = c;
//                ++i;
//            }
//        }
//        printf("%c %d\n", c, cnt[c]);
        fto(j, 1, (cnt[c]+1)/2) {
            ans[i] = ans[n-i-1] = c;
            //debug(i);
            ++i;
        }
    }
    printf("%s", ans);

    return 0;
}