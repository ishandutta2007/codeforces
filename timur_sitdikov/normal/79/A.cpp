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

int x[3], y[3];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int a, b, i, j;
    cin >> a >> b;
    x[0] = 2;
    y[0] = 2;
    x[1] = 1;
    y[1] = 12;
    x[2] = 0;
    y[2] = 22;
    for(i = 0; ; i++){
        if (i % 2 == 0){
            for(j = 0; j < 3; j++){
                if (x[j] <= a && y[j] <= b){
                    a -= x[j];
                    b -= y[j];
                    break;
                }
            }
            if (j == 3){
                printf("Hanako");
                return 0;
            }
        }
        else{
            for(j = 2; j >= 0; j--){
                if (x[j] <= a && y[j] <= b){
                    a -= x[j];
                    b -= y[j];
                    break;
                }
            }
            if (j == -1){
                printf("Ciel");
                return 0;
            }
        }
    }
}