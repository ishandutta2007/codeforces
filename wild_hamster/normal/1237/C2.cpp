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

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;

ll b[600500], p[600500];
struct hyu {
    ll x;
    ll y;
    ll z;
    ll num;
};

map<ll, vector<hyu> > hyus;

hyu a[100500];
vector<ll> f, g, ans;
bool cmp(const hyu& l, const hyu& r) {
    return std::tie(l.x, l.y, l.z) < std::tie(r.x, r.y, r.z);
}

vector<ll> hyu3;
map<pii, vector<hyu>> hyu1;
map<ll, vector<hyu>> hyu2;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].num = i + 1;
    }

    for (int i = 0; i < n; i++) {
        hyu1[mp(a[i].x, a[i].y)].push_back(a[i]);
    }
    for (auto it = hyu1.begin(); it != hyu1.end(); it++) {
        ll sz = (it->second).size();
        sort((it->second).begin(), (it->second).end(), cmp);
        for (int i = 0; i + 1 < sz; i+=2) {
            ans.push_back(it->second[i].num);

            ans.push_back(it->second[i+1].num);
        }
        if (sz % 2) {
            hyu2[(it->second).back().x].push_back((it->second).back());
        }
    }

    for (auto it = hyu2.begin(); it != hyu2.end(); it++) {
        ll sz = (it->second).size();
        sort((it->second).begin(), (it->second).end(), cmp);
        for (int i = 0; i + 1 < sz; i+=2) {
            ans.push_back(it->second[i].num);

            ans.push_back(it->second[i+1].num);
        }
        if (sz % 2) {
            hyu3.push_back((it->second).back().num);
        }
    }
    for (auto x : hyu3) {
        ans.push_back(x);
    }
    for (int i = 0; i < ans.size(); i+=2) {
        cout << ans[i] << " " << ans[i+1] << "\n";
    }
    return 0;
}