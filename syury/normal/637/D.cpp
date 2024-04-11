#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return

int n, m, js, d;
vector<int> x, dp, ri;
set<pair<int, int> > s;

void restore(int pos){
    if(pos == 0){
        printf("RUN %d\n", ri[pos]- x[pos] - 1);
        ret;
    }
    restore(dp[pos]);
    printf("JUMP %d\n", x[pos] + 1 - ri[dp[pos]]);
    if(pos != n){
        printf("RUN %d\n", ri[pos]- x[pos] - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d%d%d%d", &n, &m, &js, &d);
    x.rs(n + 1); dp.rs(n + 1); dp.asg(n + 1, -1); ri.rs(n + 1);
    x[0] = -1;
    F(i, 1, n + 1)
        scanf("%d", &x[i]);
    sort(all(x));
    if(x[1] - 1 >= js){
        s.insert(mk(x[1] - 1, 0));
        ri[0] = x[1] - 1;
    }
    F(i, 1, n + 1){
        if(i < n && x[i + 1] - 1 == x[i])
            continue;
        while(!s.empty() && (s.begin()->X) + d < x[i] + 1)
            s.erase(s.begin());
        if(s.empty())
            continue;
        dp[i] = s.begin()->Y;
        if(i < n){
            int r = x[i + 1] - 1;
            int l = x[i] + 1;
            ri[i] = r;
            if(r - l < js)
                continue;
            s.insert(mk(r, i));
        }
    }
    if(dp[n] == -1){
        printf("IMPOSSIBLE");
        ret 0;
    }
    restore(n);
    if(x[n] + 1 < m)
        printf("RUN %d\n", m - x[n] - 1);
    ret 0;
}