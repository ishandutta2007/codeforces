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

int cnt[2][200];
string s[2];

void solve(){
    int i, j, n;
    cin >> s[0] >> s[1];
    for(i = 0; i < 2; i++){
        for(j = 0; j < (int)s[i].length(); j++){
            cnt[i][s[i][j]]++;
        }
    }
    for(i = 'a'; i <= 'z'; i++){
        if (cnt[1][i] > cnt[0][i]){
            printf("need tree\n");
            return;
        }
    }
    if (s[0].length() == s[1].length()){
        printf("array\n");
        return;
    }
    for(i = 0, j = 0; i < s[0].length(); i++){
        if (j < s[1].length() && s[0][i] == s[1][j]){
            j++;
        }
    }
    if (j == s[1].length()){
        printf("automaton\n");
        return;
    }
    printf("both\n");
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