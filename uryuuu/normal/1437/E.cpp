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
const double pi=acos(-1);
const int maxn=500010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn];
int b[maxn];
ll d[maxn];
ll dp[maxn];

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int x;
    a[0]=-2e13;
    a[n+1]=2e13;
    int cnt=1;
    b[1]=0;
    for(int i=1;i<=k;i++)
    {
        cin>>x;
        b[++cnt]=x;
    }
    b[++cnt]=n+1;
    int f=0;
    for(int i=2;i<=cnt;i++)
    {
        if(a[b[i]]-a[b[i-1]]<=b[i]-b[i-1]-1)
        {
            f=1;
//            cout<<b[i-1]<<' '<<b[i]<<' '<<a[b[i-1]]<<' '<<a[b[i]]<<endl;
        }
    }
    if(f)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans=0;
    int len;
    int L,R;
    int l,r;
    for(int i=2;i<=cnt;i++)
    {
        L=b[i-1]+1;
        R=b[i]-1;
        l=b[i-1];
        r=b[i];
        len=0;
        while(L<=R)
        {
            if(L-l<=a[L]-a[l]&&a[r]-a[L]>=r-L)
            {
                d[++len]=a[L]-(L-l)-a[l];
            }
            L++;
        }
        for(int j=0;j<=len+2;j++)
            dp[j]=2e15;
        int ss=0,tmp;
        for(int j=1;j<=len;j++)
        {
//            cout<<d[j]<<' ';
            tmp=upper_bound(dp+1,dp+len+1,d[j])-dp;
            dp[tmp]=d[j];
            ss=max(tmp,ss);
        }
//        cout<<len<<' '<<l<<' '<<r<<' '<<ss<<endl;
        ans=ans+(r-l-1-ss);
    }
    cout<<ans<<endl;
    return 0;
}