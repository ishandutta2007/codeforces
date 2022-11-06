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

const int MAXN = 1000005;
int cnt[200];
char s1[MAXN], s2[MAXN];

long long gcd(long long a, long long b){
    return b? gcd(b, a % b) : a;
}

void solve(){
    long long n1, n2, l1, l2, g, nans, ans;
    int i, j;
    scanf("%I64d%I64d%s%s", &n1, &n2, &s1, &s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    g = gcd(l1, l2);
    nans = 0;
    for(j = 0; j < g; j++){
        for(i = 'a'; i <= 'z'; i++){
            cnt[i] = 0;
        }
        for(i = j; i < l2; i += g){
            cnt[s2[i]]++;
        }
        for(i = j; i < l1; i += g){
            nans += cnt[s1[i]];
        }
    }
    ans = l1 * l2 / g - nans;
    ans *= n1 / (l2 / g);
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