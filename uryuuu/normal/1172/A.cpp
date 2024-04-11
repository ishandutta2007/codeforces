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
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn],b[maxn],p[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    rep(i,1,n)
    cin>>a[i];
    rep(i,1,n)
    cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        p[b[i]]=i;
    }
    int f=0;
    if(p[1])
    {
        for(int i=p[1]+1;i<=n;i++)
        {
            if(b[i]!=b[i-1]+1)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            int l=b[n]+1;
            int ct=0;
            for(int i=l;i<=n;i++)
            {
                if(p[i]>ct)
                {
                    f=1;
                    break;
                }
                ct++;
            }
            if(f==0)
            {
                cout<<n-l+1<<endl;
                return 0;
            }
        }
    }
    
    int zd=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i])
        {
            zd=max(zd,p[i]-(i-1));
        }
    }
    cout<<zd+n<<endl;
    
    
    return 0;
}