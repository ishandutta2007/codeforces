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

const int maxn = 1005;
int st[maxn];

int is_1(int a, int b){
    int dif = 0;
    for(; a; ){
        if ((a % 10) != (b % 10))
            dif++;
        a /= 10;
        b /= 10;
    }
    return dif <= 1;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, n, j;
    st[0] = 1000;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> st[i];
    for(i = 1; i <= n; i++){
        for(j = st[i - 1]; j <= 2011; j++){
            if (is_1(st[i], j)){
                st[i] = j;
                break;
            }
        }
        if (j == 2012){
            cout << "No solution";
            return 0;
        }
    }
    for(i = 1; i <= n; i++)
        cout << st[i] << endl;
}