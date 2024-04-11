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
#define maxN 2005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, a[maxN], cnt1, cnt2, m1, m2, tar[maxN];
vector<int> tC, cT;
ii cnt[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &a[i]);
    if (m <= n) {
        m2 = n/m;
        m1 = m2+1;
        cnt1 = n%m;
        cnt2 = m-cnt1;

        fto(i, 1, cnt2) {
            tar[i] = m2;
        }
        fto(i, cnt2+1, cnt2+cnt1) {
            tar[i] = m1;
        }
    //    printf("%d %d %d %d\n", cnt2, m2, cnt1, m1);
    //    fto(i, 1, m) printf("%d ", tar[i]);
    //    puts("");
        fto(i, 1, m) cnt[i].ss = i;
        fto(i, 1, n) {
            if (a[i] <= m) ++cnt[a[i]].ff;
            else tC.pb(a[i]);
        }

        sort(cnt+1, cnt+m+1);
        fto(i, 1, m) {
            fto(j, m2+1, cnt[i].ff) tC.pb(cnt[i].ss);
            fto(j, cnt[i].ff+1, m2) cT.pb(cnt[i].ss);
        }
    //    forit(it, tC) printf("%d ", *it);
    //    puts("");
    //    forit(it, cT) printf("%d ", *it);
    //    puts("");

        fto(i, 0, (int)cT.size()-1) {
            fto(j, 1, n) {
                if (a[j] == tC[i]) {
                    a[j] = cT[i];
                    break;
                }
            }
        }
    }
    else {m2 = 0;}
    printf("%d %d\n", m2, cT.size());
    fto(i, 1, n) printf("%d ", a[i]);






    return 0;
}