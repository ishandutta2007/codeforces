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
#define xx first
#define yy second

int m[20];

int get_num(int mm, int dd){
    int i, ans = 0;
    for(i = 1; i < mm; i++)
        ans += m[i];
    ans += dd;
    return ans + 200;
}

int val[1000];

int main()
{   
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    m[1] = m[3] = m[5] = m[7] = m[8] = m[10] = m[12] = 31;
    m[4] = m[6] = m[9] = m[11] = 30;
    m[2] = 28;
    int n, i, j, mm, dd, p, t, mx;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> mm >> dd >> p >> t;
        dd = get_num(mm, dd);
        for(j = dd - t; j < dd; j++){
            val[j] += p;
        }
    }
    mx = 0;
    for(i = 0; i < 1000; i++){
        mx = max(mx, val[i]);
    }
    cout << mx;
}