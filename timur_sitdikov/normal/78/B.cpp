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

char c[4];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j;
    cin >> n;
    cout << "BIVROYG";
    c[0] = 'R';
    c[1] = 'O';
    c[2] = 'Y';
    c[3] = 'G';
    for(i = 8, j = 0; i <= n; i++, j = (j + 1) % 4){
        putchar(c[j]);
    }
}