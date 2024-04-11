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
    string a, b, ans;
    int cur = 0;
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            ans += a[i];
            continue;
        }
        if (cur & 1) {
            ans += a[i];
        } else {
            ans += b[i];
        }
        cur ^= 1;
    }   
    if (cur & 1) {
        ans = "impossible";
    }
    cout << ans << endl;
}