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

const int N = 2020;

int n;
int x[N], y[N], cnt;
pair<pair<int, int>, int> v[N];
long long ans;

int gcd(int x, int y) {
    while ((x > 0) && (y > 0)) {
        if (x > y) x %= y; else y %= x;
    }
    return x + y;
}

long long C3(int n) {
    long long res = 1LL * n * (n - 1);
    res = res * (n - 2);
    return res / 6;
}

void go(int k) {
    ans-=k*(k-1)/2;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }   
    ans=C3(n);
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = i + 1; j < n; j++) {
            int a = y[j] - y[i];
            int b = x[i] - x[j];
            int c = -a*x[i]-b*y[i];
            if ((a < 0) || ((a == 0) && (b < 0))) {a=-a;b=-b;c=-c;}
            int d = gcd(abs(a), abs(b));
            d = gcd(d, abs(c));
            a/=d;b/=d;c/=d;
            v[cnt++]=mp(mp(a,b),c);
        }
        sort(v,v+cnt);
        int lt = 1;
        for (int j = 1; j < cnt; j++) {
            if (v[j]==v[j-1])lt++; else {
                go(lt);
                lt=1;
            }
        }
        go(lt);
    }
    cout << ans << endl;
}