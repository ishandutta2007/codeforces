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

const int MAXN = 100005;

int per[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j;
    scanf("%d", &n);
    if (n % 4 == 2 || n % 4 == 3){
        printf("-1");
        return 0;
    }
    if (n & 1){
        per[n/2] = n/2;
    }
    for(i = 0; i < n/2; i += 2){
        per[i] = i + 1;
        per[i + 1] = n - i - 1;
        per[n - i - 1] = n - i - 2;
        per[n - i - 2] = i;
    }
    for(i = 0; i < n; i++){
        printf("%d ", per[i] + 1);
    }
}