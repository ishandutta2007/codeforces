#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=700005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

map<string,int>mp;
int a[20][5];
string t,tmp;
string s[maxn];
vector<int>g[maxn];
int d[maxn];
int ans[maxn];

int main()
{
    sync;
    int n,m,k;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i&(1<<j))
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        mp[s[i]]=i;
    }
    
    int dg=1<<k,id,f,j,h,u;
    for(int i=1;i<=m;i++)
    {
        cin>>t>>id;
        f=0;
        for(j=0;j<k;j++)
        {
            if(s[id][j]=='_')
                continue;
            if(s[id][j]!=t[j])
                f=1;
        }
        if(f)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for(j=0;j<dg;j++)
        {
            tmp=t;
            for(h=0;h<k;h++)
            {
                if(a[j][h]==0)
                    tmp[h]='_';
            }
            u=mp[tmp];
            if(u&&u!=id)
            {
                g[id].push_back(u);
                d[u]++;
            }
        }
    }
    
    int cnt=0;
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
            q.push(i);
    }
    while(q.size())
    {
        u=q.front();
        q.pop();
        ans[++cnt]=u;
        for(int v:g[u])
        {
            d[v]--;
            if(d[v]==0)
                q.push(v);
        }
    }
    if(cnt<n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    
    return 0;
}