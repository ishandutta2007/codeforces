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
    int n, m, k, d;
    string s, s1, s2;
    int i, zx, cx;
    cin >> n >> m >> k >> s1 >> s2 >> s;
    if (s2[0] == 'h'){
        d = -1;
    }
    else{
        d = 1;
    }

    zx = m;
    cx = k;
    for(i = 0; i < (int)s.length(); i++){
        if (s[i] == '0'){
            if (zx < cx){
                zx--;
                if (zx == 0){
                    zx++;
                }
            }
            else{
                zx++;
                if (zx == n + 1){
                    zx--;
                }
            }
        }

        if (d == 1){
            cx++;
            if (cx == n + 1){
                cx = n - 1;
                d = -d;
            }
        }
        else{
            cx--;
            if (cx == 0){
                cx = 2;
                d = -d;
            }
        }

        if (s[i] == '0' && cx == zx){
            cout << "Controller " << i + 1;
            return 0;
        }

        if (s[i] == '1'){
            if (d == 1){
                zx = 1;
            }
            else{
                zx = n;
            }
        }
    }
    cout << "Stowaway";
}