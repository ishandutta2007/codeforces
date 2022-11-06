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

const int MAXN = 2000005;
pair<int, int> pp1[MAXN], pp2[MAXN];

char c[2][MAXN];
char used[MAXN];

int ans[2];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, j, a;
    scanf("%d%s%s", &n, &c[0], &c[1]);
    for(i = 0; i < 2 * n; i++){
        a = (c[0][i] - '0') * 2 + c[1][i];
        pp1[i] = mp(a, i);
        a = (c[1][i] - '0') * 2 + c[0][i];
        pp2[i] = mp(a, i);
    }
    sort(pp1, pp1 + 2 * n);
    reverse(pp1, pp1 + 2 * n);
    sort(pp2, pp2 + 2 * n);
    reverse(pp2, pp2 + 2 * n);
    int i1 = 0, i2 = 0;
    for(i = 1; i <= 2 * n; ){
        if (i & 1){
            if (!used[pp1[i1].second]){
                used[pp1[i1].second] = 1;
                ans[0] += (c[0][pp1[i1].second] - '0');
                i++;
                i1++;
            }
            else {
                i1++;
            }
        }
        else{
            if (!used[pp2[i2].second]){
                used[pp2[i2].second] = 1;
                ans[1] += (c[1][pp2[i2].second] - '0');
                i++;
                i2++;
            }
            else {
                i2++;
            }
        }
    }
    if (ans[0] > ans[1]){
        printf("First");
    }
    else if (ans[0] < ans[1]){
        printf("Second");
    }
    else {
        printf("Draw");
    }
}