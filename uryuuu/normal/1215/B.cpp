#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;

ll a[maxn];
ll s[maxn];
ll d[maxn];
ll w[maxn];
ll e[maxn];
int main()
{
    sync
    ll n;
    cin>>n;
    
    s[0]=0;
    d[0]=0;
    
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1];
        w[i]=w[i-1];
        e[i]=e[i-1];
        if(a[i]<0)
            s[i]++;
        else
        {
            if(s[i]%2==0)
            {
                w[i]++;
            }
            else
                e[i]++;
        }
        
    }
//    for(int i=0;i<=n;i++)
//    cout<<w[i]<<' '<<e[i]<<endl;
    ll sum=0;
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]>0)
        {
            sum++;
            sum+=(s[i-1]/2);
            if(s[i]%2==0)
            {
                sum+=w[i-1];
            }
            else
            {
                sum+=e[i-1];
            }
//            cout<<sum<<' ';
        }
        else
        {
//            cout<<"yes"<<endl;
            sum+=(s[i-1]+1)/2;
            if(s[i]%2==0)
            {
                sum+=w[i-1];
            }
            else
            {
                sum+=e[i-1];
            }
//            cout<<sum<<' ';
        }
    }
    cout<<n*(n+1)/2-sum<<' '<<sum<<endl;
    
    return 0;
}