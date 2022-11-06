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
#include <list>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

int v[10], va[10], vb[10];

const int MAXN = 100005;

int oo[MAXN];

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, a, b, i, tmp;
    scanf("%d%d%d", &n, &a, &b);
    if (a == b){
        for(i = 0; i < a; i++){
            printf("1 ");
        }
        for(i = 0; i < a; i++){
            printf("2 ");
        }
        return 0;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &oo[i]);
        v[oo[i]]++;
    }
    if (a > b){
        for(i = 1; i <= 5; i++){
            tmp = min(a, v[i]);
            va[i] += tmp;
            a -= tmp;
        }
        for(i = 1; i <= 5; i++){
            vb[i] = v[i] - va[i]; 
        }
    }
    else{
        for(i = 1; i <= 5; i++){
            tmp = min(b, v[i]);
            vb[i] += tmp;
            b -= tmp;
        }
        for(i = 1; i <= 5; i++){
            va[i] = v[i] - vb[i]; 
        }
    }
    for(i = 0; i < n; i++){
        if (va[oo[i]] > 0){
            printf("1 ");
            va[oo[i]]--;
        }
        else{
            printf("2 ");
            vb[oo[i]]--;
        }
    }
}