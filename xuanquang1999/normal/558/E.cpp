//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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

//template <class T>
//T min(T a, T b, T c) {
//    return min(a, min(b, c));
//}
//
//template <class T>
//T max(T a, T b, T c) {
//    return max(a, max(b, c));
//}

int n, q, cnt[256];
string str;
map<int, char> m;

int next(map<int, char>::iterator it) {
    return (++it)->ff;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    cin >> str;
    fto(l, 0, n-1) {
        m[l+1] = str[l];
        while (l < n-1 && str[l+1] == str[l]) ++l;
    }
    m[n+1] = '*';

    fto(i, 1, q) {
        int l, r, z;
        scanf("%d%d%d", &l, &r, &z);

        memset(cnt, 0, sizeof cnt);
//        printf("%d %d %d\n", l, r, z);
//        forit(it, m) printf("(%d, %c) ", it->ff, it->ss);
//        puts("");
        map<int, char>::iterator it = --m.upper_bound(l);
        while (it->ff <= r) {
//            debug(it->ff);
            cnt[it->ss]+=min(r, next(it)-1)-max(l, it->ff)+1;
            ++it;
        }
        it = --m.upper_bound(r);
        if (r+1 != next(it)) m[r+1] = it->ss;
        m.erase(m.lower_bound(l), m.upper_bound(r));

        if (z == 1) {
            fto(c, 'a', 'z') {
                if (cnt[c] != 0) {
                    m[l] = c;
                    l += cnt[c];
                }
            }
        }
        else {
            fdto(c, 'z', 'a') {
                if (cnt[c] != 0) {
                    m[l] = c;
                    l += cnt[c];
                }
            }
        }
    }

    forit(it, m) {
        fto(i, 1, next(it)-it->ff) printf("%c", it->ss);
    }

    return 0;
}