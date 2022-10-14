#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define mp make_pair
#define MOD 1000000007
#define X first
#define Y second
using namespace std;

typedef int ll;
typedef pair<ll, ll> pii;

ll maxx, maxy, n;
int main() {
    ll x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {

            scanf("%d %d", &x, &y);
            if (x > y) {
                swap(x, y);
            }
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        } else {
            scanf("%d %d", &x, &y);
            if (x > y) {
                swap(x, y);
            }
            if (x >= maxx && y >= maxy) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}