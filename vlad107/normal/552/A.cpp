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
    int tt;
    int res = 0;
    scanf("%d", &tt);
    while (tt--) {
        int x0, y0, x1, y1;
        scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
        res += (x1-x0+1)*(y1-y0+1);
    }
    printf("%d\n", res);
}