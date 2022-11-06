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
int v[maxn];
string s;

int bad(int j){
    if (s[j] == 'L' && v[j] <= v[j + 1])
        return 1;
    if (s[j] == '=' && v[j] != v[j + 1])
        return 1;
    return 0;
}

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j;
    cin >> n >> s;
    v[0] = 1;
    for(i = 0; i < n - 1; i++){
        if (s[i] == 'L')
            v[i + 1] = min(1, v[i] - 1);
        else if (s[i] == 'R')
            v[i + 1] = v[i] + 1;
        else v[i + 1] = v[i];
        if (v[i + 1] == 0){
            v[i + 1]++;
            for(j = i; j >= 0 && bad(j); j--){
                v[j]++;
            }
        }
    }
    for(i = 0; i < n; i++)
        cout << v[i] << " ";
    
}