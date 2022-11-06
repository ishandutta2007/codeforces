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
    int t, i, a, b;
    double res;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        if (b == 0){
            printf("1.000000000\n");
            continue;
        }
        if (4 * b <= a){
            res = 1.0 - b / (a + 0.);       
        }
        else{
            res = 0.5 + a / (16.0 * b);
        }
        printf("%.9lf\n", res);
    }
}