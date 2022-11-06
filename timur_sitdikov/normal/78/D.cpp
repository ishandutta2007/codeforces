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

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long i, j, r, ans = 1;
    cin >> r;
    j = 0;
    for(i = 1; ; i++){
        while(1){
            if (i - 2 * j < 0){
                cout << ans;
                return 0;
            }
            if ((3 * i + 2) * (3 * i + 2) + 3 * (i - 2 * j) * (i - 2 * j) <= 4 * r * r){
                break;
            }
            j++;
        }
        if (j == 0){
            ans += 6 * i;
        }
        else{
            ans += 6 * (i - 2 * j + 1);
        }
    }
}