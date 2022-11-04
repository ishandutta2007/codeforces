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
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;



ll s[maxn];
ll p[maxn];
ll w[105];

int main()
{
    sync;
    int t;
    cin>>t;
    ll a,b,m;
    p[0]=1ll;
    p[1]=1ll;
    for(int i=2;i<=61;i++)
    {
        p[i]=2ll*p[i-1];
    }
    while(t--)
    {
        mm(w);
        cin>>a>>b>>m;
        if(a==b)
        {
            cout<<1<<' '<<a<<endl;
            continue;
        }
        ll x;
        int pos;
        ll d;
        for(int i=1;i<=60;i++)
        {
            if(1ll*p[i]*(a+1ll)<=b&&1ll*p[i+1]*(a+1ll)>b)
            {
                x=p[i];
                d=b-1ll*p[i]*(a+1ll);
                pos=i;
                break;
            }
        }
        
        
        ll y=1ll;
        for(ll i=min(d/x,m-1);i>=1;i--)
        {
            if(1ll*i*x<=d)
            {
                y+=i;
                d-=1ll*i*x;
                break;
            }
        }
//        cout<<d<<endl;
//        cout<<x<<endl;
//        cout<<y<<endl;
        
        if(d>x||(d&&m==y))
        {
            cout<<-1<<endl;
            continue;
        }
        
        int cnt=1;
        ll g=1ll*x/2ll;
        for(int i=1;i<=pos;i++)
            w[i]=1ll*y;
        while(d)
        {
            if(d>=g&&g)
            {
                w[cnt]+=1ll;
                d-=g;
            }
            g/=2ll;
            cnt++;
        }
        if(d)
            w[cnt]+=1ll;
        w[0]=a;
        ll sm=a;
        for(int i=1;i<=pos;i++)
        {
            w[i]=sm+w[i];
            sm+=w[i];
        }
        cout<<pos+1<<' ';
        for(int i=0;i<=pos;i++)
        {
            cout<<w[i]<<' ';
        }
        cout<<endl;
        
    }
    
    return 0;
}