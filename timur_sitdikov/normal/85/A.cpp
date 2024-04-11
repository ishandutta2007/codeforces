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

const int MAXN = 105;
char m[4][MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j;
    cin >> n;
    for(j = 0; j < 4; j++){
        for(i = 0; i < n; i++){
            m[j][i] = 'a';
        }
    }
    for(i = 0; i < n - 1; i++){
        if (i % 4 == 0){
            m[2][i] = m[2][i + 1] = 'f';
            m[3][i] = m[3][i + 1] = 'g';
        }
        if (i % 4 == 2){
            m[2][i] = m[2][i + 1] = 'h';
            m[3][i] = m[3][i + 1] = 'i';
        }
        if (i % 4 == 1){
            m[0][i] = m[0][i + 1] = 'b';
            m[1][i] = m[1][i + 1] = 'c';
        }
        if (i % 4 == 3){
            m[0][i] = m[0][i + 1] = 'd';
            m[1][i] = m[1][i + 1] = 'e';
        }
    }
    if (n == 1 || n == 2){
        m[0][0] = m[1][0] = 'z';
    }
    for(j = 0; j < 4; j++){
        printf("%s\n", m[j]);
    }
}