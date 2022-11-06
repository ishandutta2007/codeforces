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

const int maxn = 200005;
vector<pair<pair<int, int>, pair<int, int> > >g[maxn];
set<pair<int, int> > st;
int ans[maxn], w[maxn];
char used[maxn];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m, i, j, a, b, c, to;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++){
        scanf("%d %d %d", &a, &b, &c);
        g[a].pb(mp(mp(b, c), mp(i, 0)));
        g[b].pb(mp(mp(a, c), mp(i, 1)));
        w[a] += c;
        w[b] += c;
    }
    w[1] = 0;
    for(i = 1; i < n; i++){
        st.insert(mp(w[i], i));
    }
    for(j = 1; j < n; j++){
        a = st.begin()->second;
        used[a] = 1;
        st.erase(st.begin());
        for(i = 0; i < (int)g[a].size(); i++){
            to = g[a][i].first.first;
            if (used[to])
                continue;
            ans[g[a][i].second.first] = g[a][i].second.second;
            if (to != n){
                st.erase(mp(w[to], to));
                w[to] -= 2 * g[a][i].first.second;
                st.insert(mp(w[to], to));
            }
        }
    }
    for(i = 1; i <= m; i++)
        printf("%d\n", ans[i]);

}