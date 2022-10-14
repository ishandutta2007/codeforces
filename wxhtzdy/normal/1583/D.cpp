#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, p[105];
vector<int> G[105], T[105];

void add_edge(int x, int y)
{
        G[x].push_back(y);
        T[y].push_back(x);
}

int askl(int id)
{
        printf("? ");
        rep1(i, n) printf("%d ", (i == id ? 1 : 2));
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        return ret;
}

int askr(int id)
{
        printf("? ");
        rep1(i, n) printf("%d ", (i == id ? 2 : 1));
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
        return ret;
}

void dfs(int id, int val) 
{
        p[id] = val;
        rep(i, G[id].size()) dfs(G[id][i], val + 1);
}

int main()
{
        scanf("%d", &n);
        rep1(i, n) {
                int idl = askl(i);
                if(idl != 0 && idl != i) add_edge(idl, i);
                int idr = askr(i);
                if(idr != 0 && idr != i) add_edge(i, idr);
        }
        rep1(i, n) if(T[i].empty()) dfs(i, 1);
        printf("! ");
        rep1(i, n) printf("%d ", p[i]);
        fflush(stdout);
        return 0;
}