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

const int MAXN = 100005;

int per[MAXN], col[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, s, t, i, ans;
    cin >> n >> s >> t;
    for(i = 0; i < n; i++){
        cin >> per[i + 1];
    }
    ans = 0;
    for(i = s; !col[i]; i = per[i]){
        if (i == t)
            break;
        col[i] = 1;
        ans++;
    }
    if (col[i]){
        cout << -1;
    }
    else {
        cout << ans;
    }
}