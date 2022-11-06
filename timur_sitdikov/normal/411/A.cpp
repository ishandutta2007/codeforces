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
    int i, n;
    cin >> s;
    n = s.length();
    int ans = 0;
    for(i = 0; i < n; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            ans |= 2;
        }
        if (s[i] >= 'a' && s[i] <= 'z'){
            ans |= 4;
        }
        if (s[i] >= '0' && s[i] <= '9'){
            ans |= 8;
        }
    }
    if (n >= 5){
        ans |= 1;
    }
    if (ans == 15){
        cout << "Correct";
    }
    else {
        cout << "Too weak";
    }
}

int main(){ 
    //assert(freopen("in.txt", "r", stdin));assert(freopen("out.txt", "w", stdout));
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}