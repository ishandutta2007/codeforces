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
int l, a[100500];
int main() {
    //freopen("input.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 0;
    a[n+1] = 1001;
    int x = 1;
    for (int i = 0; i < n+2; i++) {
        if (a[i] + 1 == a[i+1])
            x++;
        else
            x = 1;
        l = max(l, x);
    }
    l = max(l ,x);
    cout << max(0, l-2) << endl;
    return 0;
}