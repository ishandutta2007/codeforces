#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l + r >> 1)
#define lo (o << 1)
#define ro (lo | 1)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e2 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct tri{int x,y,z;};

int n,ans[maxn];
string s;
bool edg[maxn][maxn];

bool dfs(int u,int f)
{
    if(ans[u]==f)return 1;
    else if(ans[u]!=-1)return 0;
    ans[u]=f;
    for(int i=0;i<n;i++)if(edg[i][u])
    {
        if(!dfs(i,1-f))return 0;
    }
    return 1;
}

bool solve()
{
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[j]<s[i])edg[i][j]=edg[j][i]=1;
        }
    }
    for(int i=0;i<n;i++)if(ans[i]==-1)
    {
        if(!dfs(i,0))return 0;
    }
    return 1;
}
 
int main()
{
    // freopen("in.txt","r",stdin);
    cin>>n;
    cin>>s;
    if(!solve())puts("NO");
    else 
    {
        puts("YES");
        for(int i=0;i<n;i++)cout<<ans[i];
    }
    return 0;
}