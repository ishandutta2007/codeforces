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
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

ll a[maxn],b[maxn],s[maxn];
unordered_map<ll,int>mp;

int suc[maxn],pre[maxn];
struct node
{
    ll L;
    int Rid;
}p[maxn];

bool cmp(node a,node b)
{
    return a.L>b.L;
}

int main()
{
    sync;
    int t;
    int n;
    int m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        
        int cnt,sum,L,ans=0,mx;
        
        mp.clear();
        cnt=0;
        sum=0;
        mx=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                mp[a[i]]=1;
            }
        }
        
        for(int i=1;i<=m;i++)
        {
            if(b[i]>0)
            {
                s[++cnt]=b[i];
            }
        }
        
        suc[cnt+1]=0;
        for(int i=cnt;i>=1;i--)
        {
            suc[i]=suc[i+1]+mp[s[i]];
        }
    
        L=1;
        while(L<=n&&a[L]<=0)
        L++;
        sum=0;
        for(int i=1;i<=cnt;i++)
        {
            while(L<=n&&a[L]<=s[i])
            {
                L++;
                sum++;
            }
            p[i].L=s[i]-sum+1;
            p[i].Rid=i;
        }
        sort(p+1,p+cnt+1,cmp);
//        for(int i=1;i<=cnt;i++)
//            cout<<p[i].L<<' '<<p[i].Rid<<endl;
        
        L=cnt;
        for(int i=1;i<=cnt;i++)
        {
            while(L>0&&s[L]>=p[i].L)
                L--;
            pre[p[i].Rid]=p[i].Rid-L;
        }
        
        L=1;
        while(L<=n&&a[L]<=0)
        L++;
        sum=0;
        for(int i=1;i<=cnt;i++)
        {
            while(L<=n&&a[L]<=s[i])
            {
                L++;
                sum++;
            }
            if(sum==0)
                pre[i]=0;
        }
        
        if(cnt>0)
            mx=suc[1];
        for(int i=1;i<=cnt;i++)
        {
            mx=max(pre[i]+suc[i+1],mx);
//            cout<<s[i]<<' '<<pre[i]<<' '<<suc[i]<<endl;
        }
        ans+=mx;
        

        
        mp.clear();
        for(int i=1;i<=n;i++)
            a[i]=-a[i];
        for(int i=1;i<=m;i++)
            b[i]=-b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        
        cnt=0;
        sum=0;
        mx=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                mp[a[i]]=1;
            }
        }
        
        for(int i=1;i<=m;i++)
        {
            if(b[i]>0)
            {
                s[++cnt]=b[i];
            }
        }
        
        suc[cnt+1]=0;
        for(int i=cnt;i>=1;i--)
        {
            suc[i]=suc[i+1]+mp[s[i]];
        }
    
        L=1;
        while(L<=n&&a[L]<=0)
        L++;
        sum=0;
        for(int i=1;i<=cnt;i++)
        {
            while(L<=n&&a[L]<=s[i])
            {
                L++;
                sum++;
            }
            p[i].L=s[i]-sum+1;
            p[i].Rid=i;
        }
        sort(p+1,p+cnt+1,cmp);
        
        L=cnt;
        for(int i=1;i<=cnt;i++)
        {
            while(L>0&&s[L]>=p[i].L)
                L--;
            pre[p[i].Rid]=p[i].Rid-L;
        }
        
        L=1;
        while(L<=n&&a[L]<=0)
        L++;
        sum=0;
        for(int i=1;i<=cnt;i++)
        {
            while(L<=n&&a[L]<=s[i])
            {
                L++;
                sum++;
            }
            if(sum==0)
                pre[i]=0;
        }
        if(cnt>0)
            mx=suc[1];
        for(int i=1;i<=cnt;i++)
        {
            mx=max(pre[i]+suc[i+1],mx);
        }
        ans+=mx;
        cout<<ans<<endl;
    }
    
    return 0;
}