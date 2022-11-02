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

const int N = 2e5;

int n;
pair<int, int> a[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }   
    sort(a, a + n);
    int last = -2e9 - 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first - a[i].second > last) {
            last = a[i].first;
            cnt++;
        } else
        if ((i + 1 == n) || (a[i].first + a[i].second < a[i + 1].first)) {
            last = a[i].first + a[i].second;
            cnt++;
        } else {
            last = a[i].first;
        }
    }
    cout << cnt << endl;
}