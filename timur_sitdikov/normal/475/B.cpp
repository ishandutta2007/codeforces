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

const int MAXN = 25;

string s1, s2;

void solve(){
    int n, m, i;
    cin >> n >> m >> s1 >> s2;
    if (s1[0] == '<' && s1[n - 1] == '>' && s2[0] == 'v' && s2[m - 1] == '^'
         || s1[n - 1] == '<' && s1[0] == '>' && s2[m - 1] == 'v' && s2[0] == '^'){
        cout << "YES\n";
    } else {
        cout << "NO\n";
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