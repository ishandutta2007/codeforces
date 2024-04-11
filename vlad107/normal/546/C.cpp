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
    vector<int> a, b;
    int m;
    cin >> m;   
    a.resize(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    set< pair< vector<int>, vector<int> > > s;
    int ans = 0;
    while ((a.size() != 0) && (b.size() != 0)) {
        ++ans;
        s.insert(make_pair(a, b));
        int x = a[0];
        int y = b[0];
        a.erase(a.begin());
        b.erase(b.begin());
        if (x > y) {
            a.push_back(y);
            a.push_back(x);
        } else {
            b.push_back(x);
            b.push_back(y);
        }
        if (s.find(make_pair(a, b)) != s.end()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << " ";
    if (a.size() == 0) cout << 2 << endl; else
    cout << 1 << endl;
}