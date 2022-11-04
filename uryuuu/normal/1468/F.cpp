#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define mp make_pair
#define ld long double
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, greater<int> > small_heap;
typedef priority_queue<int> big_heap;
typedef tuple<int, int, int> mkgroups;
const ll mod = 1e9 + 7;
const int N = 1e6 + 100;
int T;
int n;
map<pii, ll> mmp;


int fx(int x1, int y1, int x2, int y2) {
    if (x1 <= x2) {
        if (y1 <= y2)return 1;
        else return 4;
    } else {
        if (y1 <= y2)return 2;
        else return 3;
    }
}

int main() {
    int i, x1, x2, y1, y2, fxx, up, down, xx, yy, ggcd;
    double k;
    ll ans = 0;
    for (scanf("%d", &T); T; --T) {
        mmp.clear();
        ans = up = down = 0;
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 != x2) {
                xx = x1 - x2;
                yy = y1 - y2;
                ggcd = __gcd(abs(xx), abs(yy));
                xx /= ggcd;
                yy /= ggcd;
                ans += mmp[mp(-xx, -yy)];
                mmp[mp(xx, yy)]++;
            } else {
                if (y1 > y2) {
                    ans += up;
                    down++;
                } else {
                    ans += down;
                    up++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}