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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;

ll a[maxn];
map<ll,int>mp;
map<ll,int>vis;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
//        mmp.clear();
        vis.clear();
        ll x=0;
        ll n,m;
        cin>>n>>m;
        ll nn=n;
        for(int i=0;i<m;i++)
            cin>>a[i];
        sort(a,a+m);
        for(int i=0;i<m;i++)
        {
            x=a[i];
            mp[a[i]]++;
            if(a[i]>n)
                break;
        }
        ll p=1ll;
        while(p<=n)
            p*=2;
        p/=2;
        while(p)
        {
            while(p<=n)
            {
                n-=p;
                vis[p]++;
//                cout<<p<<' ';
            }
            if(n==0)
                break;
            p/=2;
        }
//        cout<<endl;
        p=1ll;
        int f=0;
        ll s=0ll;
        while(p<=nn)
        {
            if(vis[p])
            {
                if(mp[p])
                    mp[p]--;
                else
                {
                    f=0;
                    ll pp=p;
                    while(pp<=x)
                    {
                        if(mp[pp])
                        {
                            f=1;
                            mp[pp]--;
                            break;
                        }
                        mp[pp]++;
                        pp*=2;
                        s++;
                    }
                    if(f==0)
                    {
                        f=2;
                        break;
                    }
                }
            }
            mp[p*2]+=mp[p]/2;
            mp[p]=mp[p]%2;
            p*=2;
        }
        
        if(f==2)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<s<<endl;
    }
    return 0;
}