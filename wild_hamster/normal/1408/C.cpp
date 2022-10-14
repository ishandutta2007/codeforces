#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;
#define OFF 400001
#define C 13000
#define NN 1000000
#define MOD 1000000007
ll n, k, z, m, pos, q, ans_v, y, root, xx;
ll ii, r1, r2, r3, l;
ll d[1005005], a[1005000], b[1005000], pb[1005000];

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int nn, lll;
        scanf("%d %d", &nn, &lll);
        n = nn;
        l = lll;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        n += 2;
        a[n-2] = 0;
        a[n-1] = l;
        sort(a, a+n);
        long double L = 0;
        ll vL = 1, pL = 0;
        ll vR = 1, pR = n-1;
        long double R = l;
        long double ans = 0;
        while (pL + 1 < pR) {
            long double left_dist = a[pL + 1] - L;
            long double right_dist = R - a[pR - 1];
            if (left_dist * vR < right_dist * vL) {
                double t = 1. * left_dist / vL;
                L = a[pL + 1];
                pL++;
                R -= vR * t;
                vL += 1;
                ans += t;
            } else {

                double t = 1. * right_dist / vR;
                R = a[pR - 1];
                pR--;
                L += vL * t;
                vR += 1;
                ans += t;
            }
        }
        ans += 1. * (R - L) / (vL + vR);
        printf("%.12f\n", (double)ans);

    }
    return 0;
}