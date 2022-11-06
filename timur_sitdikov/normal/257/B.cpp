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

pair<int, int> emulate(int n, int m){
    int x = 0, y = 0, i, last = 0;
    n--;
    for(i = 1; n + m; i++){
        if (!m){
            n--;
            if (last == 0)
                x++;
            else{
                y++;
                last = 0;
            }
            continue;
        }
        if (!n){
            m--;
            if (last == 1)
                x++;
            else{
                y++;
                last = 1;
            }
            continue;
        }
        if (i & 1){
            y++;
            if (last == 0)
                m--;
            else
                n--;
            last ^= 1;
        }
        else{
            x++;
            if (last == 0)
                n--;
            else
                m--;
        }
    }
    return mp(x, y);
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    pair<int, int> p1, p2;
    cin >> n >> m;
    p1 = emulate(n, m);
    p2 = emulate(m, n);
    if (p1.first > p2.first || p1.first == p2.first && p1.second > p2.second){
        cout << p1.first << " " << p1.second;
    }
    else{
        cout << p2.first << " " << p2.second;
    }
}