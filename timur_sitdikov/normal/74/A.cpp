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

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int mx = -1000000000;
    int n, a, b, c, d, e, v1, v2, i, cur;
    string s, ans;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s >> v1 >> v2 >> a >> b >> c >> d >> e;
        cur = 100 * v1 - 50 * v2 + a + b + c + d + e;
        if (mx < cur){
            mx = cur;
            ans = s;
        }
    }
    cout << ans;
}