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
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

long long xmin, ymin, xmax, ymax;

/*int process(int x1, int y1, int x2, int y2){
}*/

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long x1[5], x2[5], y1[5], y2[5], i, n;
    long long s, s1;
    cin >> n >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    xmin = x1[0];
    xmax = x2[0];
    ymin = y1[0];
    ymax = y2[0];
    for(i = 1; i < n; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (xmin > x1[i]){
            xmin = x1[i];
        }
        if (xmax < x2[i]){
            xmax = x2[i];
        }
        if (ymin > y1[i]){
            ymin = y1[i];
        }
        if (ymax < y2[i]){
            ymax = y2[i];
        }
    }
    if (xmax - xmin != ymax - ymin){
        cout << "NO";
        return 0;
    }
    s = (xmax - xmin) * (ymax - ymin);
    s1 = 0;
    for(i = 0; i < n; i++){
        s1 += (x2[i] - x1[i]) * (y2[i] - y1[i]);
    }
    if (s == s1){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}