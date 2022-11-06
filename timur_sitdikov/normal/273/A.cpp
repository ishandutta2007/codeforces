#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int maxn = 100005;
long long a[maxn];

int main(){
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/
    int n, m, i, w;
    long long h, ans;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d %I64d", &w, &h);
        ans = max(a[0], a[w - 1]);
        a[0] = ans + h;
        printf("%I64d\n", ans);
    }
}