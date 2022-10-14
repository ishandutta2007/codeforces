#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 998244353
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x, r, x2, y2;
ll aa[300500], b[300500], c[300500];
ll Abs(ll x) {
    return (x > 0 ? x : -x);
}
struct suck {
    ll x;
    ll y;
    ll z;
};
suck a[300500];
std::vector<suck> f;
vector<ll> ans1, ans2;
bool cmp(suck x, suck y) {
    return x.y > y.y;
}
bool cmp2(suck x, suck y) {
    return x.y < y.y;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
        a[i].z = i + 1;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].x < a[i].y) {
            f.push_back(a[i]);
        }
    }
    sort(f.begin(), f.end(), cmp);
    for (int i = 0; i < f.size(); i++) {
        ans1.push_back(f[i].z);
    }
    f.clear();
    for (int i = 0; i < n; i++) {
        if (a[i].x > a[i].y) {
            f.push_back(a[i]);
        }
    }
    sort(f.begin(), f.end(), cmp2);
    for (int i = 0; i < f.size(); i++) {
        ans2.push_back(f[i].z);
    }
    if (ans2.size() > ans1.size()) {
        cout << ans2.size() << endl;
        for (auto i: ans2) {
            cout << i << " ";
        }
    } else {
        cout << ans1.size() << endl;
        for (auto i: ans1) {
            cout << i << " ";
        }
    }
    return 0;
}