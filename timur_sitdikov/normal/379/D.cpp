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

const int MAXN = 55;
long long v1[MAXN], v2[MAXN], v12[MAXN], v21[MAXN], v22[MAXN];

string a1, a2;

void output(){
    cout << a1 << endl << a2;
}

void solve(){
    long long x, curi, curj, curk, curl, curm;
    int i, j, k, l, m, n, l1, l2, ii, offset1, offset2;
    cin >> n >> x >> l1 >> l2;
    if (x == 0){
        for(i = 0; i < l1; i++){
            putchar('A');
        }
        putchar('\n');
        for(i = 0; i < l2; i++){
            putchar('A');
        }
        return;
    }
    v1[1] = 1, v1[2] = 0;
    v2[1] = 0, v2[2] = 1;
    v12[1] = 0, v12[2] = 0, v12[3] = 1;
    v21[1] = 0, v21[2] = 0;
    v22[1] = 0, v22[2] = 0;
    for(i = 3; i <= n; i++){
        v1[i] = v1[i - 2] + v1[i - 1];
        v2[i] = v2[i - 2] + v2[i - 1];
        if (i != 3){
            v12[i] = v12[i - 2] + v12[i - 1];
        }
        v21[i] = v21[i - 2] + v21[i - 1];
        if (i % 2 == 0){
            v21[i]++;
        }
        v22[i] = v22[i - 2] + v22[i - 1];
        if ((i != 3) && (i % 2 == 1)){
            v22[i]++;
        }
    }

    for(i = 0; i < 2; i++){
        curi = x - i * v12[n];
        if (curi < 0){
            continue;
        }
        for(j = 0; j < 2; j++){
            curj = curi - j * v21[n];
            if (curj < 0){
                continue;
            }
            if (i == 1 && j == 1 && (l1 == 1 || l2 == 1)){
                continue;
            }
            for(m = 0; m < 2; m++){
                curm = curj - m * v22[n];
                if (curm < 0){
                    continue;
                }
                if (m == 1 && l2 == 1){
                    continue;
                }
                offset1 = l1 - i - j;
                for(k = 0; k <= offset1 / 2; k++){
                    curk = curm - k * v1[n];
                    if (curk < 0){
                        continue;
                    }
                    offset2 = l2;
                    if (m == 1){
                        offset2 -= 2;
                    }
                    else {
                        offset2 -= i + j;
                    }
                    for(l = 0; l <= offset2 / 2; l++){
                        curl = curk - l * v2[n];
                        if (curl == 0){
                            if (i){
                                a2 = "C";
                            }
                            if (j){
                                a1 = "C";
                            }
                            if (m){
                                a2 = "C";
                            }
                            for(ii = 0; ii < k; ii++){
                                a1 += "AC";
                            }
                            for(ii = 0; ii < l; ii++){
                                a2 += "AC";
                            }
                            while(a1.length() < l1 - i){
                                a1 += "B";
                            }
                            if (i){
                                a1 += "A";
                            }
                            while(a2.length() < l2 - max(j, m)){
                                a2 += "B";
                            }
                            if (j || m){
                                a2 += "A";
                            }
                            output();
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!";
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