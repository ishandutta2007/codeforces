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
//#include<unordered_map>
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
const int maxn =200010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn];
map<int,int>mp,vis;

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        
        int d;
        int ans;
        int f=0;
        int fl;
        
        for(int k=1;k<=2048;k++)
        {
            vis.clear();
            fl=0;
            for(int i=1;i<=n;i++)
            {
                d=a[i]^k;
                vis[d]++;
                if(vis[d]>mp[d])
                {
                    fl=1;
                    break;
                }
            }
            if(fl==0)
            {
                ans=k;
                f=1;
                break;
            }
        }
        if(f)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
        
    }
    
    return 0;
}