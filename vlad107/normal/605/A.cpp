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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]); 
    vector<int> b(n+1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        --a[i];
        int cnt = b[a[i]]+1;
        // cerr << i << " " << cnt << endl;
        ans = max(ans, cnt);
        b[a[i]+1] = cnt;
    }
    cout << n-ans << endl;
}