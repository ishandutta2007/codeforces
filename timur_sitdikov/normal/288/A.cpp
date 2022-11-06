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

const int MAXN = 1000005;
char c[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k, i, j;
    scanf("%d %d", &n, &k);
    if (k > n || k == 1 && n > 1){
        printf("-1");
        return 0;
    }
    for(i = 0; i < n; i++){
        c[i] = i & 1;
    }
    for(i = n - 1, j = k - 1; j >= 2; j--, i--){
        c[i] = j;
    }
    for(i = 0; i < n; i++){
        c[i] += 'a';
    }
    printf("%s", &c);
}