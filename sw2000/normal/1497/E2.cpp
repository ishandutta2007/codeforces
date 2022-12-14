#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int M = 1e7 + 10;
const int mod = 1e9 + 7;

int arr[N],to[M],f[N][21],l[N][21];
int solve()
{
    int n,k;
    cin>>n>>k;
    int ret=1;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        arr[i]=to[a];
    }
    map<int,int>mp;
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        if(mp[arr[i]])
        {
            s.insert(mp[arr[i]]);
        }
        mp[arr[i]]=i;
        vi v;
        for(int j=0;j<=k;j++)
        {
            if(s.empty())l[i][j]=1;
            else
            {
                l[i][j]=*--s.end()+1;
                v.push_back(*--s.end());
                s.erase(--s.end());
            }
        }
        for(auto j:v)s.insert(j);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            f[i][j]=inf;
            for(int x=0;x<=j;x++)
            {
                f[i][j]=min(f[i][j],f[l[i][x]-1][j-x]+1);
            }
        }
    }
    return f[n][k];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    for(int i=0;i<M;i++)to[i]=i;
    for(int i=2;i*i<M;i++)
    {
        for(int j=i*i;j<M;j+=i*i)
        {
            while(to[j]%(i*i)==0)
            {
                to[j]/=i*i;
            }
        }
    }
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
	return 0;
}