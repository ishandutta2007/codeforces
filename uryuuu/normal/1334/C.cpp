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
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[maxn],b[maxn];

bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        ll sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i];
        if(n==1)
        {
            cout<<a[1]<<endl;
            continue;
        }
        ll zx=min(a[1],b[n]);
        a[1]-=min(a[1],b[n]);
        sum+=1ll*a[1];
        for(int i=2;i<=n;i++)
        {
            if(zx>min(a[i],b[i-1]))
            {
                zx=min(a[i],b[i-1]);
            }
            a[i]-=min(a[i],b[i-1]);
            sum+=1ll*a[i];
        }
        cout<<1ll*sum+1ll*zx<<endl;
    }
    return 0;
}