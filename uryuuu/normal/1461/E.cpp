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
//const ll Mod=1000000007;
const ll Mod = 998244353;



int main()
{
    sync;
    ll k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    if(x==y)
    {
        if(k+x<=r||k-x>=l)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        return 0;
    }
    if(x>y)
    {
        if(k+y<=r)
            k+=y;
        if(1ll*(k-l)/(x-y)<(t-1ll))
        {
            cout<<"No"<<endl;
            return 0;
        }
        k=1ll*k-1ll*(t-1)*(x-y);
        if(k-x<l)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        return 0;
    }
    ll g,m;
    ll now=k;
    ll fk=0ll;
    ll lmt=r-y;
//    cout<<"FUCK"<<endl;
    for(ll i=1ll;i<=x;i++)
    {
//        cout<<"FUCK"<<endl;
        if(now+y<r)
        {
            if(i!=1ll)
            {
                now-=x;
                fk++;
                if(now<l)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            now+=1ll*y;
            continue;
        }
        g=now-lmt;
        m=g/x;
        if(g%x)
            m++;
//        cout<<fk<<' '<<m<<' '<<t<<endl;
        if(fk+m>=t)
        {
            if(now-1ll*(t-fk)*x>=l)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        now=now-1ll*m*x;
//        cout<<now<<' ';
        if(now<l)
        {
            cout<<"No"<<endl;
            return 0;
        }
        now+=1ll*y;
//        cout<<now<<endl;
        fk+=m;
    }
    cout<<"Yes"<<endl;
    
    
    return 0;
}