#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,cnt[1010];
vi edg[1010];

int main()
{
    // freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==1)q.push(i);
    }
    while(!q.empty())
    {   
        int u=q.front();q.pop();
        if(q.empty())
        {
            cout<<"! "<<u<<endl;
            return 0;
        }
        int v=q.front();q.pop();
        cout<<"? "<<u<<' '<<v<<endl;
        int a;cin>>a;
        if(a==u||a==v)
        {
            cout<<"! "<<a<<endl;
            return 0;
        }
        for(auto i:edg[u])
        {
            cnt[i]--;
            if(cnt[i]==1)q.push(i);
        }
        for(auto i:edg[v])
        {
            cnt[i]--;
            if(cnt[i]==1)q.push(i);
        }
    }
    return 0;
}