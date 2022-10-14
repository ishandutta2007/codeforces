#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN 4005
ll h,n,i,j,k,l, pshe;

vector<pii> f;
vector<pii> g[25];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        ll p = 0;
        for (int i = 0; i < y.size(); i++) {
            if (y[i] == '1') {
                p = y.size() - i - 1;
            }
        }
        reverse(x.begin(), x.end());
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '1' && i >= p) {
                cout << i - p << endl;
                break;
            }
        }
    }
    return 0;
}