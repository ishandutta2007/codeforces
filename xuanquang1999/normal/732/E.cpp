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

int n, m, s[maxN], p[maxN], cntS, cntA, ansS[maxN], ansA[maxN];
set<ii> sp, ss;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) scanf("%d", &p[i]), sp.insert(mp(p[i], i));
    fto(i, 1, m) scanf("%d", &s[i]), ss.insert(mp(s[i], i));

    while (!ss.empty()) {
        int sX = ss.begin()->ff, sID = ss.begin()->ss;
        ss.erase(ss.begin());
        int d = 0;
        while (true) {
            set<ii>::iterator it = sp.lower_bound(mp(sX, 0));
            if (it != sp.end()) {
                int cX = it->ff, cID = it->ss;
                if (cX == sX) {
                    ++cntS;
                    cntA += d;
                    ansA[sID] = d;
                    ansS[cID] = sID;
                    sp.erase(it);
                    break;
                }
            }
            ++d;
            if (sX == 1) break;
            else sX = (sX+1)/2;
        }
    }

    printf("%d %d\n", cntS, cntA);
    fto(i, 1, m) printf("%d ", ansA[i]);
    puts("");
    fto(i, 1, n) printf("%d ", ansS[i]);
    puts("");




    return 0;
}