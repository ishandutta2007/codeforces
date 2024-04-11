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

int vals[MAXN], sgn[MAXN];
stack<int> stk;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, t, a;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &vals[i]);
    }
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d", &a);
        sgn[a - 1] = 1;
    }
    for(i = n - 1; i >= 0; i--){
        if (sgn[i]){
            stk.push(vals[i]);
            continue;
        }
        if (stk.empty() || stk.top() != vals[i]){
            stk.push(vals[i]);
            sgn[i] = 1;
        }
        else{
            stk.pop();
        }
    }
    if (!stk.empty()){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(i = 0; i < n; i++){
        if (sgn[i]){
            putchar('-');
        }
        printf("%d ", vals[i]);
    }
}