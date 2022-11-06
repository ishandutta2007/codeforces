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
typedef vector<int> vi;

const int MAXN = 4005;

char c[MAXN];
int sum[MAXN][MAXN];
map<int, int> cnt;
map<int, int>::iterator it;

void solve(){
    int n, i, j, a;
    scanf("%d%s", &a, &c);
    n = strlen(c);
    for(i = 0; i < n; i++){
        c[i] -= '0';
    }
    for(i = n - 1; i >= 0; i--){
        sum[i][i] = c[i];
        for(j = i + 1; j < n; j++){
            sum[i][j] = sum[i][j - 1] + c[j];
        }
    }
    long long ans = 0, tmp, tmp1, cnt1;
    if (a == 0){
        cnt1 = 0;
        for(i = 0; i < n; i++){
            for(j = i; j < n; j++){
                if (sum[i][j] == 0){
                    cnt1++;
                    ans += n * (n + 1);
                }
            }
        }
        ans -= cnt1 * cnt1;
        printf("%I64d", ans);
        return;
    }
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if (sum[i][j] != 0 && a % sum[i][j] == 0){
                cnt[sum[i][j]]++;
            }
        }
    }
    for(it = cnt.begin(); it != cnt.end(); it++){
        tmp = it->first;
        tmp1 = (cnt.find(a / tmp) == cnt.end()? 0: cnt[a / tmp]);
        ans += (long long)cnt[tmp] * tmp1;
    }
    printf("%I64d", ans);
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