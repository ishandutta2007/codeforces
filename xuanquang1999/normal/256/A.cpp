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
#define maxN 4005
#define maxX 1000005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN];
int s[maxX], m[maxX];
vector<int> vs, vm;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    int ans = 0;
    fto(i, 1, n) ++m[a[i]];
    fto(i, 1, maxX-1) ans = max(ans, m[i]);
    memset(m, 0, sizeof m);

    fto(i, 1, n) {
//        debug(i);
        fto(j, i+1, n) {
            if (a[j] != a[i]) {
                if (s[a[j]] == 0) vs.pb(a[j]);
                ++s[a[j]];
            }
            else {
                forit(it, vs) {
//                    printf("%d ", *it);
                    if (m[*it] == 0) vm.pb(*it);
                    m[*it] += 2;
                    s[*it] = 0;
                }
                vs.clear();
//                puts("");
            }
        }
        forit(it, vs) {
            if (m[*it] == 0) vm.pb(*it);
            ++m[*it];
            s[*it] = 0;
        }
        vs.clear();
        forit(it, vm) {
//            printf("%d %d\n", *it, m[*it]);
            ans = max(ans, 1+m[*it]);
            m[*it] = 0;
        }
        vm.clear();
    }

    cout << ans;

    return 0;
}