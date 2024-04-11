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
#define MAXN 300500
#define OFF 200001
#define MOD 1000000007
ll N;
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll a[3][205000], b[200500], w[200500];
vector<ll> f, g[200500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if (a[x][y] == 1) {
            a[x][y] = 0;
            for (int j = 0; j <= 1; j++) {
                w[b[y+j]]--;
                b[y+j] -= (1<<(3*x));
                w[b[y+j]]++;
            }
        } else {
            a[x][y] = 1;
            for (int j = 0; j <= 1; j++) {
                w[b[y+j]]--;
                b[y+j] += (1<<(3*x));
                w[b[y+j]]++;
            }
        }
        bool good = true;
        for (int j = 1; j <= 3; j++){
            for (int k = 1; k <= 3; k++) {
                if (w[8*j + 64*k]) {
                    good = false;
                }
            }
        }
        cout << (good ? "Yes" : "No") << "\n";
    }
    return 0;

}