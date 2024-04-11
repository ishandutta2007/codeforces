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

const int N = 666;

int v[N], a[N][N], n;

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        --v[i];
    }
    scanf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = getchar() - '0';
        }
        scanf("\n");
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
            a[i][j] |= (a[i][k] & a[k][j]);
    for (int i = 0; i < n; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if ((v[j] < v[mn]) && (a[i][j])) {
                mn = j;
            }
        }
        swap(v[i], v[mn]);
    }
    for (int i = 0; i < n; i++) printf("%d ", v[i] + 1);
    puts("");
}