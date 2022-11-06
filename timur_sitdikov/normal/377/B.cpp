#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int MAXN = 200005, INF = 1e9 + 5;

pair<int, pair<int, int> > pp[MAXN];
set<pair<int, int> > vals;
int n, m, s;
int get_ind;
vector<int> goods;
int ind[MAXN];

int check(int mid){
    int i, cnt, cur, tmp;
    vals.clear();
    cnt = 0;
    cur = 0;
    for(i = 0; i < n + m; i++){
        if (pp[i].second.first == -1){
            if (cnt > 0){
                cnt--;
                continue;
            }
            if (vals.empty()){
                return 1;
            }
            else {
                tmp = vals.begin()->first;
                if (get_ind == 1){
                    goods.pb(vals.begin()->second);
                }
                cur += tmp;
                if (cur > s){
                    return 1;
                }
                cnt += mid;
                cnt--;
                vals.erase(vals.begin());           
            }
        }
        else {
            vals.insert(mp(pp[i].second.first, pp[i].second.second));
        }
    }
    return 0;
}

void solve(){
    int i, j, l, r, mid;
    scanf("%d%d%d", &n, &m, &s);
    for(i = 0; i < m; i++){
        scanf("%d", &pp[i].first);
        pp[i].second.first = -1;
        pp[i].second.second = i + 1;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &pp[i + m].first);
        pp[i + m].second.second = i + 1;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &pp[i + m].second.first);
    }
    sort(pp, pp + n + m);
    reverse(pp, pp + n + m);
    l = 0;
    r = m + 1;
    while(l + 1 < r){
        mid = (l + r) >> 1;
        if (check(mid)){
            l = mid;
        }
        else {
            r = mid;
        }
    }
    if (r == m + 1){
        printf("NO");
        return;
    }
    printf("YES\n");
    get_ind = 1;
    check(r);
    int cur = r;
    for(i = 0, j = 0; i < n + m; i++){
        if (pp[i].second.first == -1){
            if (cur == 0){
                j++;
                cur = r;
            }
            cur--;
            ind[pp[i].second.second] = goods[j];        
        }
    }
    for(i = 1; i <= m; i++){
        printf("%d ", ind[i]);
    }
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}