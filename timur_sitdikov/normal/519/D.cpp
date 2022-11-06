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

const int MAXN = 1e5 + 5;

map<pair<char, ll>, int> cnt;

int v[200];
char c[MAXN];

void solve(){
    int n, i;
    ll s;
    for(i = 'a'; i <= 'z'; i++){
        scanf("%d", &v[i]);
    }
    scanf("%s", &c[0]);
    s = 0;
    ll ans = 0;
    for(i = 0; c[i]; i++){
        if (cnt.find(mp(c[i], s)) != cnt.end()){
            ans += cnt[mp(c[i], s)];    
        }
        s += v[c[i]];
        cnt[mp(c[i], s)]++;
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