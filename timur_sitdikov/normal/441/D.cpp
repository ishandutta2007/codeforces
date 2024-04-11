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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()
#define pii pair<int, int>
#define ll long long

#define FILE "file"

const int MAXN = 3005;

vector<int> s;
int p[MAXN];
int used[MAXN];

void solve(){
    int n, i, j, ind, k, m;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> p[i];
    }
    cin >> m;
    for(i = 1; i <= n; i++){
        if (!used[i]){
            s.pb(i);
            used[i] = 1;
            for(ind = p[i]; ind != i; ind = p[ind]){
                used[ind] = 1;
            }
        }
    }
    k = n - s.size();
    if (k == m){
        printf("0\n");
        return;
    }
    if (k < m){
        printf("%d\n", m - k);
        for(i = 1; k < m; i++, k++){
            printf("%d %d ", s[0], s[i]);
        }
        return;
    } 
    printf("%d\n", k - m);
    for(i = 1; i <= n; ){
        if (p[i] == i){
            i++;
            continue;
        }
        int mn = n + 1;
        for(ind = p[i]; ind != i; ind = p[ind]){
            mn = min(mn, ind);
        }
        printf("%d %d ", i, mn);
        swap(p[i], p[mn]);
        k--;
        if (k == m){
            break;
        }
    }

}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}