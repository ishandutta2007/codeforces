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
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


ll a[maxn];
int s1[maxn],s0[maxn],s[maxn];
int main()
{
    sync;
    int n;
    cin>>n;
    int x;
    int cnt0=0,cnt1=0;
    int j;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x=0;
        for(j=0;j<=62;j++)
        {
            if(a[i]&(1ll<<j))
                x++;
        }
        a[i]=x;
    }
    
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
        if(s[i]%2==0)
        {
            s0[++cnt0]=i;
        }
        else
        {
            s1[++cnt1]=i;
        }
    }
    
    ll pre,pos;
    ll ans=0,r,mx;
    
    for(int i=1;i<=n;i++)
    {
        pre=0;
        r=min(n,i+65);
        pre=a[i];
        mx=a[i];
        for(j=i+1;j<=r;j++)
        {
            pre+=a[j];
            mx=max(a[j],mx);
            if(pre%2==0&&2ll*mx<=pre)
                ans++;
        }
        r++;
        if(s[i-1]%2==0)
        {
            pos=lower_bound(s0+1,s0+cnt0+1,r)-s0;
            ans+=1ll*(cnt0-pos+1);
        }
        else
        {
            pos=lower_bound(s1+1,s1+cnt1+1,r)-s1;
            ans+=1ll*(cnt1-pos+1);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}