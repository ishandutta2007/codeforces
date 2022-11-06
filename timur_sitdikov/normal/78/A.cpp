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

int sz[3],sz1[3];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, j;
    char c;
    sz[0] = sz[2] = 5;
    sz[1] = 7;
    j = 0;
    for(; (c = getchar()) != EOF; ){
        if (c == '\n'){
            j++;
            continue;
        }
        if (j >= 3){
            printf("NO");
            return 0;
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            sz1[j]++;
        }
    }
    for(i = 0; i < 3; i++){
        if (sz[i] != sz1[i]){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}