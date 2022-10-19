//?????????????,?????????????? ???????n->sqrt(n) ????
//????????????? logn??-> ????????
%:pragma GCC optimize(4)
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
   
#define next girls_in_pali

#define INF 2e9
   
const int N = 100005;
const int sqrtN = (int) sqrt(N) + 5;
   
#define Pair pair<int,int>
   
struct Query {
    int l , r , id;
    friend bool operator < (Query xxx , Query yyy) {
        return xxx.r > yyy.r;
    }
};
   
vector<Query>G[N];
   
int dp[555][N] , val[N] , a[N] , n , pre[N] , next[N] , ans[N * 3] , f[N] , m , Block;
Pair b[N];
   
void prework(void);
void Discretization(void);
void make_link(void);
void Del(int x);
int recover(int x);
void getans(void);
int Min(int x ,int y ,int z);
   
int Min(int x , int y ,int z) {
    return min(x , min(y , z));
}
   
void prework(void) {
    for(int i = 1;i <= n;i ++) dp[1][i] = INF;
    for(int i = 2;i <= Block;i ++) {
        for(int j = i;j <= n;j ++) {
            dp[i][j] = Min(dp[i - 1][j - 1] , dp[i - 1][j] , abs(a[j] - a[j - i + 1]));
        }
    }
    for(int i = 1;i <= n;i ++) dp[1][i] = 0;
}
   
void Discretization(void) {
    for(int i = 1;i <= n;i ++) b[i] = make_pair(a[i] , i);
    sort(b + 1 , b + n + 1);
    int tot = 0;
    for(int i = 1;i <= n;i ++) {
        a[b[i].second] = i;
        val[i] = b[i].first;
    }
}
   
void make_link(void) {
    for(int i = 1;i <= n;i ++) pre[i] = i - 1 , next[i] = i + 1; pre[1] = 0; next[n] = 0; val[0] = INF;
}
   
void Del(int x) {
    pre[next[x]] = pre[x];
    next[pre[x]] = next[x];
}
   
int recover(int x) {
    pre[next[x]] = x;
    next[pre[x]] = x;
    int res = INF;
    res = min(res , abs(val[x] - val[pre[x]]));
    res = min(res , abs(val[next[x]] - val[x]));
    return res;
}
   
void getans(void) {
    scanf("%d",&m);
    for(int i = 1;i <= m;i ++) {
        Query it; scanf("%d%d",&it.l , &it.r);
        it.id = i;
        if(it.r - it.l + 1<= Block) {
            ans[i] = dp[it.r - it.l + 1][it.r];
        }
        else G[it.l / Block].push_back(it);
    }
    for(int i = 0;i <= n;i ++) if(G[i].size() > 0) {
        make_link();
        int beg = i * Block , end = (i + 1) * Block - 1;
        if(!beg) beg = 1;
        if(end > n) end = n;
        for(int j = 1;j <= end - 1;j ++) Del(a[j]);
        for(int j = n;j >= end + 1;j --) Del(a[j]);
        f[end] = INF;
        for(int j = end + 1;j <= n;j ++) f[j] = min(f[j - 1]  , recover(a[j]));
        for(int j = end - 1;j >= beg;j --) recover(a[j]);
        sort(G[i].begin() , G[i].end());
        int now = n;
        for(int j = 0;j <(int)G[i].size();j ++) {
            int l = G[i][j].l , r = G[i][j].r , id = G[i][j].id;
            while(now > r) Del(a[now]) , now --;
            int res = f[r];
            for(int k = beg;k <= end - 1;k ++) Del(a[k]);
            for(int k = end - 1;k >= l;k --) {
                res = min(res , recover(a[k]));
            }
            for(int k = l - 1;k >= beg;k --) recover(a[k]);
            ans[id] = res;
        }
    }
    for(int i = 1;i <= m;i ++) printf("%d\n",ans[i]);
}
   
main(void) {
    scanf("%d",&n);
    Block = (int) sqrt(n) + 1;
    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
    prework();
    Discretization();
    getans();
}