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

int v[200], col[200];

void solve(){
    string st;
    int n, i, j, s[3];
    s[0] = s[1] = s[2] = 0;
    v['q'] = v['Q'] = 9;
    v['R'] = v['r'] = 5;
    v['B'] = v['b'] = 3;
    v['N'] = v['n'] = 3;
    v['P'] = v['p'] = 1;
    for(i = 'A'; i <= 'Z'; i++){
        col[i] = 1;
        col[i + 'a' - 'A'] = 2;
    }
    for(i = 0; i < 8; i++){
        cin >> st;
        for(j = 0; j < 8; j++){
            s[col[st[j]]] += v[st[j]];
        }
    }
    if (s[1] > s[2]){
        cout << "White";
    } else if (s[2] > s[1]){
        cout << "Black";
    } else {
        cout << "Draw";
    }
    cout << endl;

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