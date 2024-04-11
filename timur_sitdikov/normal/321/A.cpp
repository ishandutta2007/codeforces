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

int check(long long a, long long b, long long c, long long d, long long x, long long y){
    long long k;
    if (x == 0 && y == 0){
        if (a == c && b == d){
            return 1;
        }
        return 0;
    }
    if (x != 0){
        if ((c - a) % x != 0){
            return 0;
        }
        k = (c - a) / x;
        if (k < 0){
            return 0;
        }
        if (k * y == d - b){
            return 1;
        }
        return 0;
    }
    if ((d - b) % y != 0){
        return 0;
    }
    k = (d - b) / y;
    if (k < 0){
        return 0;
    }
    if (k * x == c - a){
        return 1;
    }
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long a, b, x, y, c, d;
    int i;
    string s;
    cin >> c >> d >> s;
    x = y = 0;
    for(i = 0; i < (int)s.length(); i++){
        if (s[i] =='U'){
            y++;
        }
        if (s[i] =='D'){
            y--;
        }
        if (s[i] =='R'){
            x++;
        }
        if (s[i] =='L'){
            x--;
        }
    }
    a = 0;
    b = 0;
    int f = 0;
    f = check(a, b, c, d, x, y);
    for(i = 0; i < (int)s.length(); i++){
        if (s[i] =='U'){
            b++;
        }
        if (s[i] =='D'){
            b--;
        }
        if (s[i] =='R'){
            a++;
        }
        if (s[i] =='L'){
            a--;
        }
        if (check(a, b, c, d, x, y)){
            f = 1;
        }
    }
    if (f){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}