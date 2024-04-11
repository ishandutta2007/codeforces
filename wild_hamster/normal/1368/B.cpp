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
#define N 10000000
#define OFF 400001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll ii;
ll a[200500], b[200500], c[200500];
vector<ll> f;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s = "codeforces";
    for (int i = 0; i < 10; i++) {
        f.push_back(1);
    }
    cin >> k;
    for (int i = 0; i < 50000; i++) {
        ll zalupa = 1;
        for (auto x : f) {
            zalupa *= x;
        }
        if (zalupa >= k) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < f[i]; j++) {
                    cout << s[i];
                }
            }
            return 0;
        }
        f[i%10]++;
    }

    return 0;
}