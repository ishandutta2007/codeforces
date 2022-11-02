#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

using namespace std;

const int N = 1e5;
const int K = 202;

pair<int, int> a[N];
int n;
int cnt[K];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
    int all = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].second);
        all += a[i].second;
    }
    // cerr << "all = " << all << endl;
    sort(a, a + n);
    int j = -1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i].second;
        // cerr << "sum = " << sum << endl;
        while (a[j + 1].first != a[i].first) {
            ++j;
            cnt[a[j].second]++;
            sum -= a[j].second;
        }
        // cerr << "j = " << j << endl;
        if ((i + 1 == n) || (a[i + 1].first != a[i].first)) {
            int cur = sum;
            int k = i - j - 1;
            for (int e = 200; e >= 1 && k > 0; e--) {
                int l = min(cnt[e], k);
                cur += l * e;
                k -= l;
            }
            ans = max(ans, cur);
        }
    }
    cout << all - ans << endl;
}