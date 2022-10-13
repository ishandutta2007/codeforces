#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <math.h>
#include <array>
 
using namespace std;
 
int main() {
    int n, a, b; cin >> n >> a >> b;
    int ans = -1;
    for (int i = 1; i <= 8 && ans == -1; i++) {
        for (int j = 1; j <= n / (1 << i); j++) {
            int st = (j - 1) * (1 << i) + 1;
            int en = j * (1 << i);
            if (st <= a && a <= en
                    && st <= b && b <= en) {
                ans = i;
                break;
            }
        }
    }
    if (1 << ans == n) cout << "Final!" << "\n";
    else cout << ans << "\n";
}