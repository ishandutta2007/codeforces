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
//const ll Mod=1000000007;
const ll Mod = 998244353;

ll a[maxn];
set<pii>ans;
ll pre[maxn];

int main()
{
    sync;
    int t;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
    }
    ll s;
    for(int l=1;l<=n;l++)
    {
        for(int r=l+2;r<=n;r++)
        {
            s=pre[r-1]-pre[l];
            if(s>2*a[l])
                break;
            if(s==(a[l]^a[r]))
            {
                ans.insert(mkp(l,r));
            }
        }
    }
    
    for(int r=n;r>=1;r--)
    {
        for(int l=r-2;l>=1;l--)
        {
            s=pre[r-1]-pre[l];
            if(s>2*a[r])
                break;
            if(s==(a[l]^a[r]))
            {
                ans.insert(mkp(l,r));
            }
        }
    }
    cout<<ans.size()<<endl;
    
    return 0;
}