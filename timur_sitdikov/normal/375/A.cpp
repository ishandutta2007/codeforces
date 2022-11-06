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
#define xx real()
#define yy imag()

int v[7];
const int MAXN = 1000005;

int cnt[10];
char c[MAXN];
char is_good[10];
int per[4];

void solve(){
    int n, i, j, rem, rem1;
    scanf("%s", &c);
    n = strlen(c);
    for(i = 0; i < n; i++){
        cnt[c[i] - '0']++;
    }
    is_good[1] = is_good[6] = is_good[8] = is_good[9] = 1;
    rem = 0;
    for(i = 1; i <= 9; i++){
        for(j = 0; j < cnt[i] - is_good[i]; j++){
            rem = (rem * 10 + i) % 7;
            putchar(i + '0');
        }   
    }
    rem = (rem * 10000) % 7;
    rem1 = rem;
    per[0] = 1;
    per[1] = 6;
    per[2] = 8;
    per[3] = 9;
    for(i = 0; i < 24; i++){
        rem = 0;
        for(j = 0; j < 4; j++){
            rem = (rem * 10 + per[j]) % 7;
        }
        if ((rem1 + rem) % 7 == 0){
            for(j = 0; j < 4; j++){
                putchar(per[j] + '0');
            }
            break;
        }
        next_permutation(per, per + 4);
    }
    for(i = 0; i < cnt[0]; i++){
        putchar('0');
    }
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}