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

#define mp make_pair

using namespace std;

pair<int, int> get(int l, int a1, int b1, int a2, int b2) {
    int x = min(l - a2, b1);
    return mp(x, l - x);
}

int main() {
    // freopen("input.txt", "r", stdin);
    pair<pair<int, int>, int > ans;
    ans = mp(mp(0,0),0);
    int n, a1, b1, a2, b2, a3, b3;
    cin >> n;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    for (int i = a1 + a2; i <= b1 + b2; i++) {
        if ((a3 <= n - i) && (n - i <= b3)) {
            ans=max(ans, mp(get(i, a1, b1, a2, b2), n - i));
        } 
    }
    cout << ans.first.first << " " << ans.first.second << " " << ans.second << endl;
}