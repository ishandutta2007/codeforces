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
#define xx first
#define yy second

const int maxn = 1000005, inf = 1000000000;

int len[maxn], a[maxn], b[maxn], ind[maxn], per[maxn], n;

int find_ind(int v){
    int l = 0, r = n, mid;
    for(; l + 1 < r;){
        mid = (l + r) >> 1;
        if (len[mid] < v){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, ind1;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        ind[a[i]] = i;
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &b[i]);
        per[i] = ind[b[i]];
    }
    for(i = 1; i <= n; i++){
        per[i] = n + 1 - per[i];
    }
    for(i = 1; i <= n; i++){
        len[i] = inf;
    }
    for(i = 1; i <= n; i++){
        ind1 = find_ind(per[i]);
        if (len[ind1] > per[i]){
            len[ind1] = per[i];
        }
    }
    ind1 = 0;
    for(i = 1; i <= n; i++){
        if (len[i] < inf){
            ind1 = i;
        }
    }
    printf("%d", ind1);
}