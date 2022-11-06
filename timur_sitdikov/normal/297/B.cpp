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

int a[MAXN], b[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int na, nb, i, k;
    cin >> na >> nb >> k;
    if (na > nb){
        printf("YES");
        return 0;
    }
    for(i = 0; i < na; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < nb; i++){
        scanf("%d", &b[i]);
    }
    sort(a, a + na);
    reverse(a, a + na);
    sort(b, b + nb);
    reverse(b, b + nb);
    for(i = 0; i < na; i++){
        if (a[i] > b[i]){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}