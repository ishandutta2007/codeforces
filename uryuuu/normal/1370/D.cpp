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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn],dp[2][maxn];

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    int l=1,r=2e9,mid;
    int zx=2e9;
    int m=n;
    int h=n;
    int L=k/2;
    int R=L;
    if(k%2)
    {
        m--;
        L++;
    }
    else
        h--;
    
    while(l<r)
    {
        mid=(l+r)/2;
        int zl=0,zr=0;
        for(int i=1;i<=h;i++)
        {
            if(a[i]<=mid)
            {
                zl++;
                i++;
            }
        }
        for(int i=2;i<=m;i++)
        {
            if(a[i]<=mid)
            {
                zr++;
                i++;
            }
        }
        if(zl>=L||zr>=R)
        {
            zx=min(zx,mid);
            r=mid;
        }
        else
            l=mid+1;
    }
    cout<<zx<<endl;
    return 0;
}