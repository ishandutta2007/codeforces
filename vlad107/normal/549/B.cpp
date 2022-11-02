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

const int N = 1111;
const double EPS = 1e-9;

int n;
int a[N][N];
int t[N];
int nom[N];
vector<int> ans;

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = getchar();
            a[i][j] = c - '0';
        }
        scanf("\n");
    }
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) {
        int x = -1;
        for (int j = 0; j < n; j++) if (t[j] == 0) x = j;
        if (x == -1) break;
        ans.push_back(x + 1);
        for (int j = 0; j < n; j++) t[j] -= a[x][j];
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}