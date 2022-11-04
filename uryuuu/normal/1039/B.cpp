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
//#include<unordered_map>
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
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;


string s;

int main()
{
    sync;
    srand(unsigned(time(0)));
    
    ll n,k;
    ll l,r,mid;
    cin>>n>>k;
    
    l=1ll;r=n;
    while(1)
    {
        while(r-l>4ll*k)
        {
            mid=(l+r)/2ll;
            cout<<l<<' '<<mid<<endl;
            cin>>s;
            if(s[0]=='B')
                return 0;
            if(s[0]=='Y')
            {
                if(l==mid)
                    return 0;
                l=max(l-k,1ll);
                r=min(mid+k,n);
            }
            else
            {
                l=max(mid+1-k,1ll);
                r=min(r+k,n);
            }
        }
        ll x=1ll*rand()%(r-l+1ll)+l;
        cout<<x<<' '<<x<<endl;
        cin>>s;
        if(s[0]=='B')
            return 0;
        if(s[0]=='Y')
            return 0;
        l=max(l-k,1ll);
        r=min(r+k,n);
    }
    return 0;
}