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

set<pii> st;
set<pii>::iterator it, it1;

int v[MAXN];
int ans[MAXN];

void solve(){
    int n, i, a, b, mx, va, vb, fl = 0;
    scanf("%d%d%d", &n, &a, &b);
    if (a > b){
        swap(a, b);
        fl = 1;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
        st.insert(mp(v[i], i));
    }
    while(!st.empty()){
        it = st.end();
        it--;
        mx = it->first;
        vb = b - mx;
        va = a - mx;
        it1 = st.lower_bound(mp(va, -1));
        if (it1 != st.end() && it1->first == va){
            ans[it->second] = fl;
            ans[it1->second] = fl;
            if (va != mx){
                st.erase(it1);
            }
            st.erase(it);
        } else {
            it1 = st.lower_bound(mp(vb, -1));
            if (it1 == st.end() || it1->first != vb){
                printf("NO\n");
                return;
            } else {
                ans[it->second] = fl ^ 1;
                ans[it1->second] = fl ^ 1;
                if (vb != mx){
                    st.erase(it1);
                }
                st.erase(it);
            }
        }
    }
    printf("YES\n");
    for(i = 0; i < n; i++){
        printf("%d ", ans[i]);
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