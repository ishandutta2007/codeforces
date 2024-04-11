#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
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
typedef pair<int,double> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;


ll a[maxn],b[maxn];
ll suc[maxn],pre[maxn];
ll p[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,1,n)
        cin>>a[i];
        ll lst=a[1];
        ll d;
        
        
        int f1=0;
        lst=a[1];
        for(int i=2;i<=n;i++)
        {
            pre[i]=lst;
            lst=a[i]-lst;
            if(lst<0)
                f1=1;
            suc[i]=lst;
        }
        
        suc[n+1]=2e18;
        pre[1]=0ll;
        suc[1]=a[1];
        p[1]=suc[1];
        p[0]=0;
        for(int i=2;i<=n;i++)
        {
            p[i]=suc[i];
            p[i]=min(p[i],p[i-1]);
        }
        for(int i=n-1;i>=2;i-=2)
        {
            suc[i]=min(suc[i+2],suc[i]);
        }
        for(int i=n-2;i>=2;i-=2)
        {
            suc[i]=min(suc[i+2],suc[i]);
        }
        
        
        
        if(lst==0&&f1==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        
        
        int f=0;
        for(int i=2;i<=n;i++)
        {
//            cout<<p[i-1]<<' ';
            d=0ll;
            if((n-i)%2==0)
            {
                d=d-2ll*a[i];
                d=d+2ll*a[i-1];
                if(p[i-2]>=0&&a[i]>=pre[i-1]&&d+lst==0ll&&suc[i]+d>=0&&suc[i+1]-d>=0)
                {
                    f=1;
                    break;
                }
            }
            else
            {
                d=d-2ll*a[i];
                d=d+2ll*a[i-1];
                if(p[i-2]>=0&&a[i]>=pre[i-1]&&lst-d==0ll&&suc[i]+d>=0&&suc[i+1]-d>=0)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
        
    }
    
    return 0;
}