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

const int maxn = 100005;
long long cnt[maxn];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, mini, x;
    long long mn, sum;
    scanf("%d %d", &n, &x);
    for(i = 0; i < n; i++)
        scanf("%I64d", &cnt[i]);
    x--;
    mn = 10000000000;
    for(i = x; i >= 0; i--){
        if (cnt[i] < mn){
            mn = cnt[i];
            mini = i;
        }
    }
    for(i = n - 1; i > x; i--){
        if (cnt[i] < mn){
            mn = cnt[i];
            mini = i;
        }
    }
    sum = 0;
    if (mini == x){
        for(i = 0; i < n; i++){
            cnt[i] -= mn;
            sum += mn;
        }
    }
    else{
        for(i = x; i != mini; i = (i + n - 1) % n){
            sum += mn + 1;
            cnt[i] -= mn + 1;
        }
        for(i = mini; i != x; i = (i + n - 1) % n){
            sum += mn;
            cnt[i] -= mn;
        }       
    }
    cnt[mini] = sum;
    for(i = 0; i < n; i++)
        printf("%I64d ", cnt[i]);
}