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
        ll n;
        cin>>n;
        ll cnt=0;
        ll x=n;
        while(x)
        {
            a[cnt++]=x%3;
            x/=3;
        }
        int flag=0;
        ll k=cnt;
        int id;
        for(int i=0;i<k;i++)
        {
            if(a[i]>1)
            {
                flag=1;
                id=i;
            }
        }
        if(flag)
        {
            for(int i=0;i<id;i++)
                a[i]=0;
            for(int i=id;i<k;i++)
            {
                if(a[i]==0)
                {
                    continue;
                }
                else if(a[i]==1)
                    continue;
                else if(a[i]==2)
                {
                    if(i==k-1)
                    {
                        a[k]=0;
                        cnt++;
                    }
                    a[i+1]++;
                    a[i]=0;
                }
                else if(a[i]==3)
                {
                    if(i==k-1)
                    {
                        a[k]=0;
                        cnt++;
                    }
                    a[i+1]++;
                    a[i]=0;
                }
                else
                    continue;
            }
        }
        ll ss=1,sum=0;
//        for(int i=cnt-1;i>=0;i--)
//            cout<<a[i];
//        cout<<endl;
        for(int i=0;i<cnt;i++)
        {
            sum+=(ss*a[i]);
            if(i!=cnt-1)
            {
                ss*=3;
//                cout<<ss<<endl;
            }
        }
        cout<<sum<<endl;
    }
    
    return 0;
}