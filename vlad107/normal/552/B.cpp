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

int main() {
    int n;
    scanf("%d", &n);    
    long long x = 1;
    int len = 1;
    long long res = 0;
    while (x <= n) {
        long long y = x * 10;
        long long u = min(y - 1, n * 1LL);
        res += len * (u - x + 1);
        x = y;
        ++len;
    }
    cout << res << endl;
}