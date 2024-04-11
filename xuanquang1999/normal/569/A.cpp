using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define e 0.0000001

double T, S, q, curT;
int cnt;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> T >> S >> q;
    curT = S;
    cnt = 1;
    while (true) {
        double l = curT, r = T+1, res = curT;
        while (l <= r) {
            //debug(l);
            //debug(r);
            double mid = (l+r)/2;
            //debug(mid);
            //debug(curT);
            //debug(curT+mid*((q-1)/q));
            if (mid-e < curT+mid*((q-1)/q)) {
                if (mid > res) res = mid;
                l = mid+e;
            }
            else r = mid-e;
        }
        //debug(res);
        if (res > T-e) break;
        curT = res;
        ++cnt;
    }

    printf("%d", cnt);

    return 0;
}