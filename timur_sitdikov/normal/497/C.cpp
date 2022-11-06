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
const int INF = 1e9 + 5;

/*struct act{
    int a, b, k, ind;
} actors[MAXN], scenes[MAXN];

bool operator < (const act &v1, const act &v2){
    return v1.a < v2.a;
}*/

int ans[MAXN];

pii a[MAXN], c[MAXN];
int d[MAXN], b[MAXN], k[MAXN];

set<pii> st;
set<int>::iterator it;

void solve(){
    int n, m, i, j, ia, ic;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d%d", &a[i].first, &b[i]);
        a[i].second = i;
    }
    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d%d%d", &c[i].first, &d[i], &k[i]);
        c[i].second = i;
    }
    sort(a, a + n);
    a[n] = mp(INF, 0);
    sort(c, c + m);
    c[m] = mp(INF, 0);
    for(ia = 0, ic = 0; ia < n; ){
        int v = min(a[ia].first, c[ic].first);
        //printf("%d %d %d\n", v, ia, ic);
        for(; ic < m && c[ic].first == v; ic++){
            int ind = c[ic].second;
            st.insert(mp(d[ind], ind));
        }
        for(; ia < n && a[ia].first == v; ia++){
            int v1 = b[a[ia].second];
            if (st.lower_bound(mp(v1, -1)) == st.end()){
                printf("NO\n");
                return;
            }
            pii tmp = *st.lower_bound(mp(v1, -1));
            int ind = tmp.second;
            ans[a[ia].second] = ind;
            k[ind]--;
            if (k[ind] == 0){
                st.erase(tmp);
            }
        }
    }
    /*if (ia < n){
        printf("NO\n");
        return;
    }*/
    printf("YES\n");
    for(i = 0; i < n; i++){
        printf("%d ", ans[i] + 1);
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