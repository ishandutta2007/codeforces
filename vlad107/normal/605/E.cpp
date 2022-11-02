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

const double EPS = 1e-8;
const int N = 1e3+10;

int n;
int a[N][N];
double e[N];
double pr[N], curs[N];
bool used[N];

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
    }
    e[n-1] = 0;
    used[n - 1] = 1;
    for (int i = 0; i < n - 1; i++) pr[i] = 1-a[i][n-1]*1.0/100;
    while (!used[0]) {
        double mx = 1e9;
        int x = -1;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            double cur = 1+e[i];
            if (fabs(pr[i]-1)>EPS) cur /= (1-pr[i]); else cur += 1e9+1;
            if (cur < mx) {
                mx = cur;
                x = i;
            }
        }
        assert(x != -1);
        e[x] = (e[x]+1)/(1-pr[x]);
        used[x] = 1;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                e[i] += pr[i]*(a[i][x]*1.0/100)*e[x];
                pr[i] *= (1-a[i][x]*1.0/100);
            }
        }
    }   
    printf("%.10lf\n", e[0]);
    return 0;
}