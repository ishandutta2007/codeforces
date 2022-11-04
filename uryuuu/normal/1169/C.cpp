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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int n,m;
int a[maxn];
int check(int x)
{
    int zx=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]+x<zx)
            return 0;
        if(a[i]>zx)
        {
            if(x<zx+m-a[i])
                zx=a[i];
        }
    }
    return 1;
}


int main()
{
    sync;
    cin>>n>>m;
    rep(i,1,n)
    cin>>a[i];
    int L=0,R=maxn;
    int ans=maxn;
    while(L<R)
    {
        int mid=(L+R)/2;
        if(check(mid))
        {
            ans=min(ans,mid);
            R=mid;
        }
        else
        {
            L=mid+1;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}