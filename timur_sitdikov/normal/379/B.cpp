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

const int MAXN = 305;

int a[MAXN];

void solve(){
    int n, i, j;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < a[i]; j++){
            cout << "PRL";
        }
        cout << "R";
    }
    for(i = 0; i < a[n - 1]; i++){
        cout << "PLR";
    }
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}