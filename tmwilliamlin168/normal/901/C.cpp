#include <bits/stdc++.h>
using namespace std;
#define pii             pair<int , int >
#define inf             1000000011
#define in(a)           scanf("%d", &a)
#define ins(a)          scanf("%s", a)
#define in2(a, b)       scanf("%d%d", &a, &b)
#define in3(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define pn              printf("\n")
#define pr(a)           printf("%d\n", a)
#define prs(a)          printf("%d ", a)
#define pr2(a, b)       printf("%d %d\n", a, b)
#define pr3(a, b, c)    printf("%d %d %d\n", a, b, c)
#define pcs(a)          printf("Case %d: ", a)
#define mp              make_pair
#define vi              vector<int >
#define _ceil(n, a)     ((n)%(a)==0?((n)/(a)):((n)/(a)+1))
#define pb              push_back
#define mem(a, b)       memset((a), (b), sizeof(a))
#define all(X)          (X).begin(), (X).end ()
#define lg2(n)          (31-__builtin_clz(n))
#define ext(a)          {printf("%s\n", a); return 0;}
#define oka(x, y)       ((x)>=0&&(x)<row&&(y)>=0&&(y)<col)
#define x               first
#define y               second
#define lc              (2*i)
#define rc              (2*i+1)

typedef long long LL;
//int  dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int  dx[]={1,1,0,-1,-1,-1,0,1,0};int dy[]={0,1,1,1,0,-1,-1,-1,0};//8 direction
//int  dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//bool check(int n, int pos) {return (n & (1<<pos))>>pos;} //typecast 1 in case of int
//int  on(int n, int pos) {return n | (1<<pos);} //typecast 1 in case of int
//int  off(int n, int pos) {return n & ~(1<<pos);} //typecast 1 in case of int
//bool operator < (const data &d) const{return cost<d.cost;} //reverse in priority queue

const int M = 300100, mod = 1000000007;

vi A[M];
int visited[M];
stack<int>S;
int L[M];

void dfs(int u, int p) {
    S.push(u);
    visited[u] = 1;

    for (int v : A[u]) {
        if (visited[v] == 0) dfs(v, u);
        else if (visited[v] == 1 && v != p) {
            int maxx = 0, minn = inf;
            while (!S.empty()) {
                int w = S.top();
                S.pop();
                minn = min(minn, w);
                maxx = max(maxx, w);
                if (w == v) break;
            }
            L[maxx] = max(L[maxx], minn);
        }
    }

    if (!S.empty() && S.top() == u) S.pop();
    visited[u] = 2;
}

struct segment_tree {

    LL lazy[4*M], sum[4*M];

    segment_tree() {mem(lazy, 0); mem(sum, 0);}

    LL __value(int i, int l, int r)
    {
        return sum[i] + lazy[i] * (r-l+1);
    }

    void __propagate(int i, int l, int r)
    {
        sum[i] += lazy[i] * (r-l+1);
        if (l != r) lazy[2*i] += lazy[i], lazy[2*i+1] += lazy[i];
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int st, int ed, int val)
    {
        __propagate(i, l, r);
        if (l >= st && r <= ed) lazy[i] += val;
        else if (l > ed || r < st) return ;
        else
        {
            int m = (l+r)/2;
            update(2*i, l, m, st, ed, val);
            update(2*i+1, m+1, r, st, ed, val);
            sum[i] = __value(2*i, l, m) + __value(2*i+1, m+1, r);
        }
    }

    LL query(int i, int l, int r, int st, int ed)
    {
        __propagate(i, l, r);
        if (l >= st && r <= ed) return sum[i];
        else if (l > ed || r < st) return 0;
        else
        {
            int m = (l+r)/2;
            return query(2*i, l, m, st, ed) + query(2*i+1, m+1, r, st, ed);
        }
    }
};

segment_tree seg;
vector < pii > qq[M];
LL ans[M];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/home/lochness/Documents/in.txt", "r", stdin);
//    freopen("/home/lochness/Documents/in.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int i, j, k;
    int n, m;
    int q, l, r;

    in2(n, m);
    while (m--) {
        in2(i, j);
        A[i].pb(j);
        A[j].pb(i);
    }

    for (i = 1; i <= n; i++) if (visited[i] == 0) dfs(i, -1);
    int maxx = 0;
    for (i = 1; i <= n; i++) {
        maxx = max(maxx, L[i]);
        L[i] = maxx+1;
    }

    in(q);
    for (int i = 0; i < q; i++) {
        in2(l, r);
        qq[r].pb(mp(l, i));
    }

    for (i = 1; i <= n; i++) {
        seg.update(1, 1, n, L[i], i, 1);
        for (pii p : qq[i]) {
            int l = p.first;
            int id = p.second;
            ans[id] = seg.query(1, 1, n, l, i);
        }
    }

    for (i = 0; i < q; i++) printf("%I64d\n", ans[i]);


    return 0;
}