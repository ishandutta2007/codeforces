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

const long long mod = 1000000007;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long n, k, i, ans, f;
    cin >> n >> k;
    ans = 1;
    for(i = 1; i <= k - 1; i++){
        ans = (ans * k) % mod;
    }
    //ans = (ans * (k - 1)) % mod;
    for(i = 1; i <= n - k; i++){
        ans = (ans * (n - k)) % mod;
    }
    cout << ans;

}