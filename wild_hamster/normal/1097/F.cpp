#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD ((1<<30)-1)
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  q, good[1500050], b[505000], p[500500], prime[500500], ans;
string d[55];
vector<ll> divisors[7005];
ll gcd(ll a, ll b) {
    return b==0?a:gcd(b, a%b);
}

bitset<7005> sets[100500];
bitset<7005> precalc[7005];
int main() {
    for (int i = 2; i <= 7000; i++)
        prime[i] = 1;
    for (int i = 2; i <= 7000; i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= 7000; j += i) {
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i <= 7000; i++) {
        good[i] = 1;
        for (int j = 2; j <= 7000; j++) {
            if (prime[j]) {
                if (i % (j*j) == 0) {
                    good[i] = 0;
                }
            }
        }
    }

    for (int i = 1; i <= 7000; i++) {
        precalc[i][i] = 1;
        for (int j = 1; j*j <= i; j++) {
            if (i%j == 0) {
                if (j * j != i) {
                    divisors[i].push_back(i/j);
                }
                divisors[i].push_back(j);
            }
        }
        for (int j = 2; j*i <= 7000; j++)
            if (good[j]) {
                precalc[i][i*j] = 1;
            }

    }

    cin >> n >> q;
    string s;
    for (int i = 0; i < q; i++) {
        ll t, x, y, z;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d %d", &x, &y);
            sets[x].reset();
            for (int j = 0; j < divisors[y].size(); j++) {

                sets[x][divisors[y][j]] = 1;
            }
        } else if (t == 2) {
            scanf("%d %d %d", &x, &y, &z);
            sets[x] = (sets[y] ^ sets[z]);
        } else if (t == 3) {
            scanf("%d %d %d", &x, &y, &z);
            sets[x] = (sets[y] & sets[z]);
        } else {
            scanf("%d %d", &x, &y);
            int ans = (sets[x] & precalc[y]).count();
            s.push_back(ans % 2 + '0');
        }
        /*for (int x = 1; x <= 4; x++) {

            for (int i = 1; i <= 6; i++) {
                cout << sets[x][i];
            }
            cout << endl;
        }
        cout << endl;*/
    }
    cout << s << endl;
    return 0;
}