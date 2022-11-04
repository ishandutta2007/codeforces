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
#include<map>
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
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;

map<ll,int>mp;

ll a[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
//        ll d=1ll*(1ll*a[0]%n+n+n)%n;
        int f=0;
        ll s;
        for(ll i=0;i<n;i++)
        {
            s=(i+1ll*(1ll*a[i]%n+n+n)%n+n+n)%n;
//            cout<<a[i]<<' '<<s<<endl;
            
            if(mp[s])
            {
                f=1;
                break;
            }
            mp[s]=1;
        }
        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    
    
    return 0;
}