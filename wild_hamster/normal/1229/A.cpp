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

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll a[7050][7050], u[10050], used[10050], dp[1050000];
pair<long long, long long> b[MAXN+555];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b[i].Y;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i].X;
        sum += b[i].X;
    }
    sort(b, b+n);
    ll x = (1LL<<62) - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((b[i].Y & (x - b[j].Y)) != 0) {
                a[i][j] = 1;
                //cout << i << " " << j << endl;
                u[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ll flag = 0;
        for (int j = 0; j < n; j++) {
            if (!used[j] && u[j] == n - i - 1) {
                //cout << b[j].X << endl;
                sum -= b[j].X;
                used[j] = 1;
                for (int k = 0; k < n; k++) {
                    u[k] -= a[k][j];
                    a[k][j] = 0;
                    //cout << k << " " << u[k] << endl;
                }
                flag = 1;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    cout << sum << endl;



    return 0;
}