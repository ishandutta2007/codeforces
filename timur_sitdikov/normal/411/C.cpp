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
    int a[4], b[4];
    int i, j, k;
    for(i = 0; i < 4; i++){
        cin >> a[i] >> b[i ^ 1];
    }
    int fl;
    for(i = 0; i < 2; i++){
        fl = 0;
        for(j = 2; j < 4; j++){
            if (a[i] <= b[j] || b[i] <= a[j]){
                fl = 1;
            }
        }
        if (!fl){
            cout << "Team 1";
            return;
        }
    }
    fl = 0;
    for(i = 0; i < 2; i++){
        for(j = 2; j < 4; j++){
            if (a[j] > b[i] && b[j] > a[i]){
                fl++;
                break;
            }
        }
    }
    if (fl == 2){
        cout << "Team 2";
    }
    else {
        cout << "Draw";
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