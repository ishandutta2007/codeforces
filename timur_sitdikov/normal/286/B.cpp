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
const int OFFSET = 2000005;

int per[MAXN + OFFSET];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, k;
    scanf("%d", &n);
    int head, tail;
    for(i = 0, j = 1; j <= n; j++, i++){
        per[i] = j;
    }
    head = 0;
    tail = 0 + n;
    for(k = 2; k <= n; k++){
        if (n % k){
            per[tail] = per[head + k * (n / k)];
            i = head + k * (n / k);
        }
        else{
            i = tail;
        }
        for(; i - k >= head; i -= k){
            per[i] = per[i - k];
        }
        head++;
        tail++;
    }
    for(i = head; i < tail; i++){
        printf("%d ", per[i]);
    }
}