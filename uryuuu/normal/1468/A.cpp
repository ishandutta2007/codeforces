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

int a[maxn],b[maxn],dp[maxn],R[maxn];
struct BIT
{
    int s[maxn];
    void upd(int x,int y)
    {
        while(x<maxn)
        {
            s[x]=max(s[x],y);
            x+=lb(x);
        }
    }
    inline int qry(int x)
    {
        int mx=-99999999;
        while(x)
        {
            mx=max(mx,s[x]);
            x-=lb(x);
        }
        return mx;
    }
}A,B;

vector<int>g[maxn];
int st[maxn],pos[maxn];
int c[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]++;
        }
        for(int i=0;i<=n+2;i++)
        {
            g[i].clear();
            A.s[i]=B.s[i]=0;
        }
        int l=0;
        a[n+3]=99999999;
        st[0]=n+3;
        for(int i=n;i>=1;i--)
        {
            while(a[i]>a[st[l]])
            {
                l--;
            }
            R[i]=st[l];
            st[++l]=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(R[i]!=n+3)
            {
                g[R[i]].push_back(i);
            }
        }
        
        int ans=0;
        int x,y;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt=0;
            dp[i]=A.qry(a[i])+1;
//            cout<<dp[i]<<' ';
            ans=max(dp[i],ans);
            for(int v:g[i])
            {
                dp[v]++;
                A.upd(a[v],dp[v]);
            }
            A.upd(a[i],dp[i]);
            if(i==1)
            {
                A.upd(1,1);
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}