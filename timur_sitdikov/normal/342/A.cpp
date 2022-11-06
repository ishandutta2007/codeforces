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

int cnt[10];

int ans[100000][3], top;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, a;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a]++;
    }
    for(i = 0; i < cnt[4]; ){
        if (cnt[1] == 0 || cnt[2] == 0){
            printf("-1");
            return 0;
        }
        ans[top][0] = 1;
        ans[top][1] = 2;
        ans[top][2] = 4;
        top++;
        cnt[1]--;
        cnt[2]--;
        cnt[4]--;
    }
    for(i = 0; i < cnt[3]; ){
        if (cnt[1] == 0 || cnt[6] == 0){
            printf("-1");
            return 0;
        }
        ans[top][0] = 1;
        ans[top][1] = 3;
        ans[top][2] = 6;
        top++;
        cnt[1]--;
        cnt[3]--;
        cnt[6]--;
    }
    for(i = 0; i < cnt[6]; ){
        if (cnt[1] == 0 || cnt[2] == 0){
            printf("-1");
            return 0;
        }
        ans[top][0] = 1;
        ans[top][1] = 2;
        ans[top][2] = 6;
        top++;
        cnt[1]--;
        cnt[2]--;
        cnt[6]--;
    }
    for(i = 1; i <= 7; i++){
        if (cnt[i] > 0){
            printf("-1");
            return 0;
        }
    }
    for(i = 0; i < top; i++){
        printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
    }
}