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

map<pair<int, int>, int> ind;
map<pair<int, int>, int>::iterator it;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, i, j, k, t, a, b;
    scanf("%d %d %d %d", &n, &m, &k, &t);
    for(i = 0; i < k; i++){
        scanf("%d %d", &a, &b);
        ind[mp(a, b)] = 0;
    }
    ind[mp(50005, 50005)] = 0;
    for(i = 0, it = ind.begin(); it != ind.end(); it++, i++){
        it->second = i;
    }
    for(i = 0; i < t; i++){
        scanf("%d %d", &a, &b);
        it = ind.lower_bound(mp(a, b));
        if (it->first == mp(a, b)){
            printf("Waste\n");
            continue;
        }
        j = ((a - 1) * m + b - it->second) % 3;
        if (j == 0){
            printf("Grapes\n");
        }
        else if (j == 1){
            printf("Carrots\n");
        }
        else {
            printf("Kiwis\n");
        }
    }
}