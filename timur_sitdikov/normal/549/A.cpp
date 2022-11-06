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

const int MAXN = 55;

int cnt[200];

string s[MAXN];

void solve(){
    int i, j, ans = 0, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> s[i];
    }
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < m - 1; j++){
            cnt['f'] = cnt['a'] = cnt['c'] = cnt['e'] = 0;
            cnt[s[i][j]]++;
            cnt[s[i + 1][j]]++;
            cnt[s[i][j + 1]]++;
            cnt[s[i + 1][j + 1]]++;
            if (cnt['f'] && cnt['a'] && cnt['c'] && cnt['e']){
                ans++;
            }
        }
    }
    cout << ans << endl;
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