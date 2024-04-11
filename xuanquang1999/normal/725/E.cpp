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
#define maxN 300005
#define oo 1000000007
#define EPS 1e-11

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int c, n, cnt[maxN], f[maxN], p[maxN];
vector<int> v;

bool Try(int ex) {
    int cur = c, i = v.size()-1;
    while (true) {
        if (cur == 0) return true;
        if (v[i] > f[cur]) i = p[f[cur]];
        int x = v[i];
//        printf("%d %d\n", cur, x);
        if (x == 0) return false;
        if (cur >= ex && ex > x) {
            cur -= ex;
            ex = 0;
        }
        else {
            cur -= x*min(cnt[x], cur/x);
            --i;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &c);
    scanf("%d", &n);
    fto(i, 1, n) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    v.pb(0);
    fto(i, 1, c) {
        if (cnt[i] > 0) {
            f[i] = i;
            p[i] = v.size();
            v.pb(i);
        }
        else f[i] = f[i-1];
    }
//    fto(i, 1, c) printf("%d ", f[i]);
//    puts("");

    fto(i, 1, c) {
        if (!Try(i)) {
            printf("%d", i);
            return 0;
        }
    }

    puts("Greed is good");


    return 0;
}