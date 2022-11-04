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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


int a[30][30],vis[30][30];
string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        mm(a);
        mm(vis);
        cin>>n>>m>>k;
        int j;
        for(int i=1;i<=n;i++)
        {
            s="";
            cin>>s;
            for(j=1;j<=m;j++)
            {
                if(s[j-1]=='*')
                    a[i][j]=1;
            }
        }
        int len;
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]==0)
                    continue;
                len=0;
                while(a[i-len][j-len]&&a[i-len][j+len])
                {
                    len++;
                }
                len--;
                if(len>=k)
                {
                    len=0;
                    while(a[i-len][j-len]&&a[i-len][j+len])
                    {
                        vis[i-len][j-len]=1;
                        vis[i-len][j+len]=1;
                        len++;
                    }
                }
            }
        }
        
        int f=0;
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]&&vis[i][j]==0)
                    f=1;
            }
        }
        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}