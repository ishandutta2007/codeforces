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

const int MAXN = 1000005;

int lll[MAXN], rrr[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, s, f, cur, i, t, l, r;
    scanf("%d%d%d%d", &n, &m, &s, &f);
    for(i = 0; i < m; i++){
        scanf("%d%d%d", &t, &l, &r);
        if (t < MAXN){
            lll[t] = l;
            rrr[t] = r;
        }
    }
    cur = s;
    for(i = 1; ; i++){
        if (cur == f){
            break;
        }
        if (lll[i] > 0 && cur >= lll[i] && cur <= rrr[i]){
            putchar('X');
            continue;
        }
        if (cur < f && (lll[i] == 0 || cur + 1 != lll[i])){
            cur++;
            putchar('R');
            continue;
        }
        if (cur > f && (lll[i] == 0 || cur - 1 != rrr[i])){
            cur--;
            putchar('L');
            continue;
        }
        putchar('X');
    }
}