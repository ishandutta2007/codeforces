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

const int MAXN = 3e5 + 5;

int v[MAXN], x[MAXN];

int gcd(int a, int b){
    return b? gcd(b, a % b) : a;
}

map<int, ll> ans;

pii pp[2][100];
int top[2];

void solve(){
    int n, i, j, q, tmp, last;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d", &x[i]);
    }
    pp[0][0] = mp(0, v[0]);
    ans[v[0]]++;
    top[0] = 1;
    for(i = 1; i < n; i++){
        int ind = i & 1;
        top[ind] = 0;
        last = 0;
        for(j = 0; j < top[ind ^ 1]; j++){
            tmp = gcd(pp[ind ^ 1][j].second, v[i]);
            if (tmp != last){
                pp[ind][top[ind]++] = mp(pp[ind ^ 1][j].first, tmp);
                last = tmp;
            } 
        }
        if (last != v[i]){
            pp[ind][top[ind]++] = mp(i, v[i]);
        }
        for(j = 0; j < top[ind] - 1; j++){
            ans[pp[ind][j].second] += pp[ind][j + 1].first - pp[ind][j].first;
        }
        ans[pp[ind][j].second] += i + 1 - pp[ind][j].first;
    }
    for(i = 0; i < q; i++){
        if (ans.find(x[i]) == ans.end()){
            printf("0\n");
        } else {
            printf("%lld\n", ans[x[i]]);
        }
    }
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