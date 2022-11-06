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
int v[maxn], per[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, k, n, a, dif;
    cin >> n >> k;
    for(i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(i = 0; i < n; i++){
        for(j = 1; v[j]; j++);
        v[j]--;
        per[i] = j;
        for(j -= k; j >= 1; j--){
            v[j]--;
        }
    }
    for(i = 0; i < n; i++){
        cout << per[i] << " ";
    }
}