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

const int MAXN = 300005;

long long per[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i;
    long long ans = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%I64d", &per[i + 1]);
    }
    sort(per + 1, per + n + 1);
    for(i = 1; i <= n; i++){
        ans += abs(i - per[i]);
    }
    cout << ans;
}