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

long long ans[20];
const long long mod = 1000000007;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ans[1] = 1;
    ans[3] = 3;
    ans[5] = 15;
    ans[7] = 133;
    ans[9] = 2025;
    ans[11] = 37851;
    ans[13] = 1030367;
    ans[15] = 36362925;
    long long i, n, v;
    cin >> n;
    v = ans[n];
    for(i = 1; i <= n; i++){
        v = (v * i) % mod;
    }
    cout << v;
}