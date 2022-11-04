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


ll a[maxn],b[55];


int main()
{
    sync;
    b[1]=1;
    for(int i=2;i<=60;i++)
    {
        b[i]=2ll*b[i-1];
    }
    for(int i=1;i<=59;i++)
    {
        b[i]=b[i+1]-1;
    }
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        int k=0;
        ll s;
        int pos;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1])
            {
                s=1ll*a[i-1]-a[i];
                pos=lower_bound(b+1,b+59,1ll*s)-b;
                k=max(k,pos);
                a[i]=a[i-1];
            }
        }
        
        cout<<k<<endl;
        
    }
    
    
    return 0;
}