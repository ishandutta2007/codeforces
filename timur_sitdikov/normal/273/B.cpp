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

const int maxn = 100005;
map<int, int> w;
map<int, int>::iterator it;
int a[maxn], b[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long mod, ans, i, f, j, cnt, tmp;
    int n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        w[a[i]]++;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &b[i]);
        w[b[i]]++;
    }
    scanf("%I64d", &mod);
    cnt = 0;
    for(i = 0; i < n; i++){
        if (a[i] == b[i])
            cnt++;
    }
    ans = 1;
    for(it = w.begin(); it != w.end(); it++){
        f = 1;
        j = it->second;
        for(i = 1; i <= j; i++){
            if (i % 2 == 0 && cnt){
                tmp = i / 2;
                cnt--;
            }
            else
                tmp = i;
            f = (f * tmp) % mod;
        }
        ans = (ans * f) % mod;
    }
    cout << ans;
}