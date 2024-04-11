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
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[100],d[100][100];
vector<int>g[10],ans[100];
int vis[100];
int pos[100];
int mp[100][100];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int cnt=0;
    int L,mid,R;
    for(int i=1;i<=n;i++)
    {
        pos[i]=1;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=5;i++)
            g[i].clear();
        mm(vis);
        int f=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[a[i]+1])
            {
                f=1;
                L=vis[a[i]+1];
                R=i;
                mid=R-pos[a[i]]+1;
//                pos[a[i]+1]=pos[a[i]]+1;
                mp[a[i]][a[i]+1]=1;
                for(int j=a[i];j<n;j++)
                {
                    if(mp[j][j+1])
                        pos[j+1]=pos[j]+1;
                    else
                        break;
                }
                break;
            }
            vis[a[i]]=i;
        }
        if(f==0)
            break;
        for(int i=1;i<L;i++)
            g[1].push_back(a[i]);
        for(int i=L;i<mid;i++)
            g[2].push_back(a[i]);
        for(int i=mid;i<=R;i++)
            g[3].push_back(a[i]);
        for(int i=R+1;i<=n;i++)
            g[4].push_back(a[i]);
        for(int i=1;i<=4;i++)
        {
            if(g[i].size()>0)
                ans[k].push_back(g[i].size());
        }
        int c=0;
        for(int i=4;i>=1;i--)
        {
            for(int v:g[i])
            {
                a[++c]=v;
            }
        }
        cnt=k;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
        cout<<ans[i].size()<<' ';
        for(int v:ans[i])
            cout<<v<<' ';
        cout<<endl;
    }
    
    return 0;
}