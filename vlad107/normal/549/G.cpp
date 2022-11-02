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

const int N = 2e5 + 100;

pair<int, int> a[N];

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].first += i;
        a[i].second = i;
    }
    stable_sort(a, a + n);
    for (int i = 0; i < n; i++) a[i].first -= i;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i].first == a[i + 1].first + 1) {
            cout << ":(\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i].first);
    }
    puts("");
}