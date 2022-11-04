#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define pii pair<int,int>
using namespace std;
const ll Mod=1e9+7;
const int maxn=2010;
ll powmod(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
        {
            res=res*x%Mod;
        }
        x=x*x%Mod;
        y/=2;
    }
    return res;
}
 
int a[200005],v[200005],b[200005];
int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            v[i]=0;
        }
        int d,s;
        for(int i=1;i<=n;i++)
        {
            if(v[i])
                continue;
            d=a[i];
            b[0]=i;
            s=1;
            while(d!=i)
            {
                b[s++]=d;
                d=a[d];
            }
            for(int j=0;j<s;j++)
            {
                v[b[j]]=s;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<v[i]<<' ';
        cout<<endl;
    }
    
    return 0;
}