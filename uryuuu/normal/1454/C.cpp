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
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;


vector<int>g[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            g[i].push_back(0);
        }
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            g[x].push_back(i);
        }
        for(int i=1;i<=n;i++)
        {
            g[i].push_back(n+1);
        }
        int sz,j;
        int mn=9999999,sum=0;
        for(int i=1;i<=n;i++)
        {
            sz=g[i].size();
            if(sz==2)
                continue;
            sum=0;
            for(j=1;j<g[i].size();j++)
            {
                if(g[i][j]-1>g[i][j-1])
                    sum++;
            }
            mn=min(mn,sum);
        }
        cout<<mn<<endl;
        
    }
    
    return 0;
}