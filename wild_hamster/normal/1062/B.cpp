#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <time.h>
#include <sstream>
#include <random>
#include <utility>
using namespace std;
vector<int> f;
int l;
int main() {
    //freopen("input.txt", "w", stdout);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << " " << 0 << endl;
        return 0;
    }
    int ans = 1;
    int r = 500500;
    for (int i = 2; i <= 1000000; i++) {
        int k = 0;
        while (n%i == 0) {
            k++;
            n /= i;
        }
        if (k) {
            ans *= i;
            f.push_back(k);
            l = max(l, k);
            r = min(r, k);
        }

    }
    int x = 0;
    for (int i = 0; i < 30; i++) {
        if ((1 << i) >= l) {
            l = (1 << i);
            x = i;
            break;
        }
    }
    cout << ans << " ";
    if (l > r)
        x++;
    cout << x << endl;
    return 0;
}