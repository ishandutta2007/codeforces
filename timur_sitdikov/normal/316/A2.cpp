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

int val[10];
char used[200];

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long ans = 1;
    string a;
    cin >> a;
    int i, j, n, cnt = 0;
    n = a.length();
    for(i = 0; i < 10; i++){
        val[i] = 10 - i;
    }
    j = 0;
    for(i = 0; i < n; i++){
        if (a[i] >= 'A' && a[i] <= 'J'){
            if (used[a[i]])
                continue;
            if (i == 0){
                ans *= 9;
            }
            else {
                ans *= val[j];
            }
            used[a[i]] = 1;
            j++;
        }
        else if (a[i] == '?'){
            if (i == 0){
                ans *= 9;
            }
            else{
                cnt++;
            }
        }
    }
    cout << ans;
    for(i = 0; i < cnt; i++){
        putchar('0');
    }
}