#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 30000
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q;


ll b[100500];
vector<ll> g, f;
ll a[1005];

ll gcd(ll a, ll b) {
    return b == 0? a : gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        a[s[i]]++;
    }
    ll z = a['z'];
    ll o = a['n'];
    for (int i = 0; i < o; i++) {
        cout << 1 << " ";
    }
    for (int i = 0; i < z; i++) {
        cout << 0 << " ";
    }
    return 0;
}