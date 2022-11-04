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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=2010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;


int a[maxn];

int zd,n;

void dfs(int L,int R)
{
    int f=0;
    for(int i=L+1;i<=R;i++)
    {
        if(a[i]<a[i-1])
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        zd=max(R-L+1,zd);
        return;
    }
    int mid=(R-L+1)/2;
    dfs(L,L+mid-1);
    dfs(R-mid+1,R);
}


int main()
{
    sync;
    cin>>n;
    rep(i,1,n)
    {
        cin>>a[i];
    }
    zd=0;
    dfs(1,n);
    cout<<zd<<endl;
    
    return 0;
}