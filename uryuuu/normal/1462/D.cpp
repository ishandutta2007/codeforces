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
const int maxn=3010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;


ll a[maxn];
ll pre[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        pre[0]=0ll;
        rep(i,1,n)
        {
            cin>>a[i];
            pre[i]=1ll*pre[i-1]+1ll*a[i];
//            cout<<pre[i]<<' ';
        }
        
        int ans=n,L=1,R;
        ll d;
        for(int i=n;i>=1;i--)
        {
            if(pre[n]%(1ll*i))
                continue;
            d=1ll*pre[n]/(1ll*i);
            L=1;
            int f=0;
//            cout<<"FUCK"<<' '<<i<<endl;
            while(L<=n)
            {
                R=upper_bound(pre+L,pre+n+1,d+pre[L-1])-pre-1;
//                cout<<d<<' '<<pre[L-1]<<' '<<R<<endl;
                if(pre[R]!=d+pre[L-1])
                {
//                    cout<<"CCC"<<' '<<pre[R]<<' '<<d+pre[L-1]<<endl;
                    f=1;
                    break;
                }
                L=R+1;
            }
            if(f==0)
            {
                ans=i;
                break;
            }
        }
        cout<<n-ans<<endl;

    }
    
    
    return 0;
}