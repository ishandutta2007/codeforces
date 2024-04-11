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

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string a, b;
    int cnta, cntb, i;
    cin >> a >> b;
    cnta = cntb = 0;
    for(i = 0; i < (int)a.length(); i++){
        if (a[i] == '1'){
            cnta++;
        }
    }
    for(i = 0; i < (int)b.length(); i++){
        if (b[i] == '1'){
            cntb++;
        }
    }
    if (cnta & 1){
        cnta++;
    }
    if (cnta >= cntb){
        printf("YES");
    }
    else {
        printf("NO");
    }
}