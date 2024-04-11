#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

set<int> e[maxn+5],pool;

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        e[x].insert(y);
        e[y].insert(x);
    }
    queue<int> q;
    rep(i,1,n) pool.insert(i);
    int ans=0;
    while(pool.size())
    {
        ans++;
        q.push(*pool.begin());
        pool.erase(pool.begin());
        while(q.size())
        {
            int now=q.front(); q.pop();
            for(auto it=pool.begin();it!=pool.end();)
            {
                if(e[now].find(*it)==e[now].end())
                {
                    q.push(*it);
                    pool.erase(it++);
                }
                else it++;
            }
        }
    }
    printf("%d\n",ans-1);
    return 0;
}