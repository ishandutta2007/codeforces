#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

void solve(){
    int n, i, j;
    scanf("%d", &n);
    if (n <= 3){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for(; n > 5; n -= 2){
        printf("%d - %d = %d\n", n, n - 1, 1);
        printf("%d * %d = %d\n", 1, 1, 1);  
    }
    if (n == 5){
        printf("5 - 2 = 3\n");
        printf("3 - 1 = 2\n");
    } else {
        printf("2 * 1 = 2\n");
    }
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}