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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

void solve(){
    string s;
    int n, i, x1, x2, x;
    cin >> n >> s;
    x1 = x2 = 0;
    for(i = 0; i < n; i++){
        if (s[i] == 'x'){
            x1++;
        }
        else {
            x2++;
        }
    }
    x = 0;
    for(i = 0; i < n; i++){
        if (x1 > x2 && s[i] == 'x'){
            s[i] = 'X';
            x++;
            x1--;
            x2++;
        }
        else if (x1 < x2 && s[i] == 'X'){
            s[i] = 'x';
            x++;
            x1++;
            x2--;
        }
    }
    cout << x << endl << s;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}