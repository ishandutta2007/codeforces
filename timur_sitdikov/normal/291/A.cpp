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

map<int, int> cnt;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, i, a, ans = 0;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a;
        if (a){
            cnt[a]++;
            if (cnt[a] > 2){
                cout << -1;
                return 0;
            }
            if (cnt[a] == 2){
                ans++;
            }
        }
    }
    cout << ans;
}