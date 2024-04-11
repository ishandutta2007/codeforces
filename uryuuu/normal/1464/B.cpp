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

string s;

ll x,y;
int cnt;
int a[maxn];
int b[maxn];
ll pre[maxn];

int main()
{
    sync;
    cin>>s;
    cin>>x>>y;
    int n=s.length();
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='1')
            a[i]=1;
        else if(s[i-1]=='0')
            a[i]=0;
        else
        {
            a[i]=0;
            b[++cnt]=i;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if(a[i]==1)
            pre[i]++;
    }
    
    
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            sum+=1ll*pre[i-1]*y;
        }
        else
        {
            sum+=1ll*(i-1-pre[i-1])*x;
        }
    }
    ll ans=sum;
    ll ss=sum;
    
    for(int j=1;j<=cnt;j++)
    {
        int i=b[j];
        sum-=1ll*(pre[i-1]+j-1)*y;
        sum-=1ll*(pre[n]-pre[i])*x;
        
        sum+=1ll*(i-1-pre[i-1]-(j-1))*x;
        sum+=1ll*(n-i-(pre[n]-pre[i]))*y;
        
        ans=min(ans,sum);
    }
    
    sum=ss;
    for(int j=1;j<=cnt;j++)
    {
        int i=b[cnt-j+1];
        sum-=1ll*(pre[i-1])*y;
        sum-=1ll*(pre[n]-pre[i]+j-1)*x;
        
        sum+=1ll*(i-1-pre[i-1])*x;
        sum+=1ll*(n-i-(pre[n]-pre[i])-(j-1))*y;
        
        ans=min(ans,sum);
    }
    
    cout<<ans<<endl;
    
    
    
    return 0;
}