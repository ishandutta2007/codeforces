#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

set<int> ban[maxn+5],S;
int q[maxn+5],cnt;

void bfs(int s)
{
    int rear=0;
    q[rear]=s;
    rep(front,0,rear)
    {
        int now=q[front];
        for(set<int>::iterator it=S.begin();it!=S.end();)
        {
            int v=*it;
            if(ban[now].find(v)==ban[now].end())
            {
                q[++rear]=v;
                S.erase(it++);
            }
            else it++;
        }
    }
}

int main()
{
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        ban[x].insert(y);
        ban[y].insert(x);
    }
    rep(i,2,n) S.insert(i);
    if(n-1-ban[1].size()<k) puts("impossible");
    else
    {
        rep(i,2,n) if(S.find(i)!=S.end() && ban[1].find(i)==ban[1].end()) bfs(i),cnt++;
        if(S.empty() && cnt<=k) puts("possible");
        else puts("impossible");
    }
    return 0;
}