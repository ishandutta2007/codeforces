#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <complex>
using namespace std;

#define pb push_back 
#define mp make_pair

#define point complex<double>
#define xx real()
#define yy imag()

const int MAXN = 200005;
long long top;

long long vv[MAXN];

void _copy(long long l, long long c){
    int i, j;
    for(i = 0; i < c; i++){
        for(j = 1; j <= l; j++){
            if (top == MAXN){
                return;
            }
            vv[top++] = vv[j];
        }
    }
}

long long qq[MAXN][2], qq_t[MAXN];
long long len[MAXN];

void solve(){
    int n, i, j, q;
    long long l, c, offset, v;
    scanf("%d", &n);
    top = 1;
    len[0] = 0;
    for(i = 1; i <= n; i++){
        scanf("%I64d", &qq_t[i]);
        if (qq_t[i] == 1){
            scanf("%I64d", &qq[i][0]);
            if (top < MAXN){
                vv[top++] = qq[i][0];
            }
            len[i] = len[i - 1] + 1;
        }
        else {
            scanf("%I64d%I64d", &l, &c);
            qq[i][0] = l;
            qq[i][1] = c;
            _copy(l, c);
            len[i] = len[i - 1] + l * c;
        }
    }
    scanf("%d", &q);
    j = 0;
    for(i = 0; i < q; i++){
        scanf("%I64d", &v);
        if (v < MAXN){
            printf("%I64d ", vv[v]);
            continue;
        }
        for(; len[j] < v; j++);
        if (qq[j][1] == 0){
            printf("%I64d ", qq[j][0]);
            continue;
        }
        offset = (v - len[j - 1]) % qq[j][0];
        if (offset == 0){
            offset = qq[j][0];
        }
        printf("%I64d ", vv[offset]);

    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}