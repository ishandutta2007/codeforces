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

const int MAXN = 100005;

int prv[MAXN];
int g[MAXN][2], top[MAXN], v[MAXN], vals[MAXN];

long long sum, cnt;
double ans[MAXN];
pair<int, int> qq[MAXN];

map<int, int> ind_of;

void dfs(int s, int l, int r){
    if (top[s] == 0){
        double me = (double)sum / (double)cnt;
        for(int i = l; i <= r; i++){
            ans[qq[i].second] = me;
        }
        return;
    }
    int i, m, ind;
    for(i = l; i <= r && qq[i].first < v[s]; i++);
    m = i - 1;
    ind = ind_of[v[s]];
    sum += vals[ind + 1];
    cnt++;
    dfs(g[s][0], l, m);
    sum -= vals[ind + 1];
    sum += vals[ind - 1];
    dfs(g[s][1], m + 1, r);
    sum -= vals[ind - 1];
    cnt--;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, k, i, a, b, root;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        scanf("%d %d", &prv[i], &v[i]);
        if (prv[i] == -1){
            root = i;
        }
        else{
            g[prv[i]][top[prv[i]]++] = i;
        }
        vals[i - 1] = v[i];
    }
    for(i = 1; i <= n; i++){
        if (top[i]){
            if (v[g[i][0]] > v[g[i][1]]){
                swap(g[i][0], g[i][1]);
                //swap(v[g[i][0]], v[g[i][1]]);
            }
        }
    }
    sort(vals, vals + n);
    for(i = 0; i < n; i++){
        ind_of[vals[i]] = i;
    }
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        scanf("%d", &a);
        qq[i] = mp(a, i);
    }
    sort(qq, qq + k);
    dfs(root, 0, k - 1);
    for(i = 0; i < k; i++){
        printf("%.12lf\n", ans[i]);
    }
}