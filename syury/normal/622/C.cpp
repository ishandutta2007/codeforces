#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<complex>
#include<ctime>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<stack>

#define X first
#define Y second

using namespace std;
typedef long long int lint;
typedef long double ldb;

const int inf = 1e9;

vector<pair<int, int> > t;
vector<set<int> > pos;
vector<int> a;
int n;

void build(int v, int l, int r){
    if(l == r){
        t[v] = make_pair(a[l], a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(v + v, l, mid);
    build(v + v + 1, mid + 1, r);
    t[v] = make_pair(min(t[v + v].X, t[v + v + 1].X), max(t[v + v].Y, t[v + v + 1].Y));
}

pair<int, int> get(int v, int l, int r, int ul, int ur){
    if(ul > ur)
        return make_pair(inf, -1);
    if(l == ul && r == ur)
        return t[v];
    int mid = (l + r) >> 1;
    pair<int, int> p1, p2;
    p1 = get(v + v, l, mid, ul, min(ur, mid));
    p2 = get(v + v + 1, mid + 1, r, max(mid + 1, ul), ur);
    int f = inf, s = inf;
    f = min(p1.X, p2.X);
    s = max(p1.Y, p2.Y);
    return make_pair(f, s);
}

int m;

int main(){
    scanf("%d%d", &n, &m);
    a.resize(n); t.resize(4 * n + 1); pos.resize(1e6 + 2);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        pos[a[i]].insert(i);
    }
    build(1, 0, n - 1);
    for(int i = 0; i < m; i++){
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        l--; r--;
        pair<int, int> tm = get(1, 0, n - 1, l, r);
        int ans = (tm.first == x) ? tm.second : tm.first;
        if(ans == x){
            printf("-1\n");
            continue;
        }
        auto it = pos[ans].lower_bound(l);
        printf("%d\n", *it + 1);
    }
    return 0;
}