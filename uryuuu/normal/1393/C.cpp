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
//#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int maxn = 300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

int vis[maxn];


int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=n;i++)
            vis[i]=0;
        int x;
        int mx=0;
        int num=0;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            vis[x]++;
            if(vis[x]>mx)
            {
                mx=vis[x];
                num=1;
            }
            else if(vis[x]==mx)
            {
                num++;
            }
        }
        int ans=0;
        for(int i=n-1;i>=1;i--)
        {
            if(1ll*(i+1)*(mx-1)+num<=n)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
        
    }

    
    
    return 0;
}