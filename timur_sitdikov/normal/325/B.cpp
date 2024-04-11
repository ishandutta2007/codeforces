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
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

set <long long> ans;
set <long long>::iterator it;

void check(long long a, long long n){
    long long l, r, k;
    l = 1;
    for(r = 1; ; r = r * 2){
        if ((2 * r - 1) * (r - 1 + a) > n){
            break;
        }
    }
    for(; l + 1 < r; ){
        k = (l + r) / 2;
        if ((2 * k - 1) * (k - 1 + a) <= n){
            l = k;
        }
        else {
            r = k;
        }
    }
    if ((2 * l - 1) * (l - 1 + a) == n){
        ans.insert((2 * l - 1) * (a + 1));
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long n, a, k;
    cin >> n;
    for(a = 1; a - 1 <= n; a = a * 2){
        check(a - 1, n);
    }
    if (ans.size() == 0){
        cout << -1;
        return 0;
    }
    for(it = ans.begin(); it != ans.end(); it++){
        cout << (*it) << endl;
    }
}