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
 
string s;
int a[maxn];

int dfs(int l,int r,int st)
{
    int ls=0,rs=0;
    int len=(r-l+1)/2;
    int mid=(l+r)/2;
    if(l==r)
    {
        if(a[l]==st)
            return 0;
        else
            return 1;
    }
    for(int i=l;i<=mid;i++)
    {
        if(a[i]==st)
            ls++;
    }
    for(int i=mid+1;i<=r;i++)
    {
        if(a[i]==st)
            rs++;
    }
    return min(dfs(l,mid,st+1)+len-rs,dfs(mid+1,r,st+1)+len-ls);
}

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        for(int i=1;i<=n;i++)
        {
            a[i]=ch(s[i-1]);
        }
        cout<<dfs(1,n,1)<<endl;
        
        
    }
    return 0;
}