#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

string a, c;

const int MAXN = 105;
int dp[MAXN];

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int b, d, p, i, j, ind, na, nc, ans;
    cin >> b >> d >> a >> c;
    na = a.length();
    nc = c.length();
    for(i = 0; i < nc; i++){
        ind = i;
        for(j = 0; j < na; j++){
            if (a[j] == c[ind % nc]){
                ind++;
            }
        }
        dp[i] = ind - i;
    }
    ind = 0;
    for(i = 0; i < b; i++){
        ind += dp[ind % nc];
    }
    ans = ind / (nc * d);
    cout << ans;
}