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
    //ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    n = s.size();
    ll mn;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("Mike\n");
            mn = s[i];
        } else {
            mn = min(mn, (ll)s[i]);
            if (s[i] > mn) {
                printf("Ann\n");
            } else {
                printf("Mike\n");
            }
        }
    }
    return 0;
}