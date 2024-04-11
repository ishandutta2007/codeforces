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
    cin >> n;
    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> s(2 * n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (s[a[i]] != 0) {
            ans++;
            a[i]++;
        }
        s[a[i]] = 1;
    }   
    cout << ans << endl;
}