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
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;



ll a[maxn];
map<ll,ll>q,e;
ll pre[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    ll s=0;
    ll sum=0;
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=1ll*a[i]^pre[i-1];
    }
    
    e[0]=1ll;
    for(int i=1;i<=n;i++)
    {
//        cout<<pre[i]<<' ';
        if(i%2)
        {
//            cout<<q[pre[i]]<<endl;
            sum+=1ll*q[pre[i]];
            q[pre[i]]++;
        }
        else
        {
//            cout<<e[pre[i]]<<endl;
            sum+=1ll*e[pre[i]];
            e[pre[i]]++;
        }
    }
    

    
    cout<<sum<<endl;
    
    return 0;
}