
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
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
pii a[205005];
multiset<ll> f;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].Y;
    }
    sort(a, a+n);
    ll last_taken = -1;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].X == last_taken) {
            f.insert(a[i].Y);
            sum += a[i].Y;
        } else {
            ll diff = a[i].X - last_taken;
            while (!f.empty() && diff > 0) {
                auto it = prev(f.end());
                sum -= *it;
                ans += sum;
                f.erase(it);
                diff--;
            }
            f.insert(a[i].Y);
            sum += a[i].Y;
            last_taken = a[i].X;
        }
    }
    while (!f.empty()) {
        auto it = prev(f.end());
        sum -= *it;

        ans += sum;
        f.erase(it);
    }
    cout << ans << "\n";
    return 0;
}