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
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

ll a[maxn];

int main()
{
    sync;
    ll k;
    ll pre,suc,L,R;
    ll m,n,ss,sum,d;
    cin>>k;
    for(L=1ll;L<2000;L++)
    {
        suc=(1ll*k+L+1ll)/L+1ll;
        ss=L*suc-k;
//        cout<<L<<' '<<suc<<' '<<ss<<endl;
        for(ll d=2000ll;d>L;d--)
        {
            R=d-L;
            if(ss%d==0)
            {
                pre=ss/d;
//                cout<<L<<' '<<pre<<' '<<R<<' '<<suc<<endl;
                if(suc>1000000ll*R||pre>1000000ll*L)
                    break;
                
                for(int i=L;i>=1;i--)
                {
                    a[i]=min(1000000ll,pre);
                    pre-=a[i];
                    a[i]*=-1ll;
                }
                for(int i=R;i>=1;i--)
                {
                    a[i+L]=min(1000000ll,suc);
                    suc-=a[i+L];
                }
                cout<<d<<endl;
                for(int i=1;i<=d;i++)
                    cout<<a[i]<<' ';
                cout<<endl;
                return 0;
                
            }
        }
    }
    
    cout<<-1<<endl;
    
    return 0;
}