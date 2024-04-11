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

string s[2010];
int L[2010][2010],R[2010][2010];
int a[2010][2010];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
        {
            a[i][j+1]=ch(s[i][j]);
        }
    }
    
    for(int i=1;i<=n;i++)
        R[i][1]=1;
    for(int j=2;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]==a[i+1][j-1]&&a[i][j]==a[i-1][j-1]&&a[i][j]==a[i][j-1])
            {
                R[i][j]=min(R[i][j-1],min(R[i+1][j-1],R[i-1][j-1]))+1;
            }
            else
            {
                R[i][j]=1;
            }
        }
    }
    
    
    for(int i=1;i<=n;i++)
        L[i][m]=1;
    for(int j=m-1;j>=1;j--)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]==a[i+1][j+1]&&a[i][j]==a[i-1][j+1]&&a[i][j]==a[i][j+1])
            {
                L[i][j]=min(L[i+1][j+1],min(L[i-1][j+1],L[i][j+1]))+1;
            }
            else
            {
                L[i][j]=1;
            }
        }
    }
    
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cout<<L[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=m;j++)
//        {
//            cout<<R[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    
    
    int l,r,mid,ans,pos;
    ll sum=0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            l=1;
            r=L[i][j];
            mid=l;
            ans=1;
            while(l<r)
            {
                mid=(l+r)/2;
                pos=j+2*(mid-1);
                if(pos>m)
                {
                    r=mid;
                    continue;
                }
                if(a[i][pos]==a[i][j]&&R[i][pos]>=mid)
                {
//                    cout<<i<<' '<<j<<' '<<' '<<i<<' '<<pos<<' '<<mid<<endl;
                    ans=max(ans,mid);
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
            
            mid=l;
            pos=j+2*(mid-1);
            if(pos<=m&&a[i][pos]==a[i][j]&&R[i][pos]>=mid)
            {
                ans=max(ans,mid);
            }
            
//            cout<<ans<<' ';
            sum=1ll*sum+1ll*ans;
        }
//        cout<<endl;
    }
    cout<<sum<<endl;

    
    
    return 0;
}