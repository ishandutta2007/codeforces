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
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

char c1[200], c2[200];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i;
    scanf("%s", &c1);
    n = strlen(c1);
    for(i = 0; i < n; i += 2){
        c2[i / 2] = c1[i];
    }
    n = strlen(c2);
    sort(c2, c2 + n);
    printf("%c", c2[0]);
    for(i = 1; i < n; i++){
        printf("+%c", c2[i]);
    }
}