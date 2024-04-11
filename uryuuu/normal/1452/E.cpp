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
const int maxn=200010;  // 
//const ll Mod=1000000007;
const ll Mod = 998244353;


struct node
{
    int l,r;
}p[2005];

int pre[4005];

int main()
{
    sync;
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i].l>>p[i].r;
    }
    int ans=0,sum=0;
    int l,r,w,L;
    for(int R=k;R<=n;R++)
    {
        L=R-k+1;
        sum=0;
        for(int j=1;j<=m;j++)
        {
            l=p[j].l;
            r=p[j].r;
            w=max(min(R,r)-max(L,l)+1,0);
            sum+=w;
            if(l+w-1<=min(l+k-1,r))
            {
                pre[l+w-1]++;
                pre[l+k-1]--;
                pre[r]--;
                pre[r+k-w]++;
            }
        }
        w=pre[0];
        pre[0]=0;
        for(int j=1;j<=n;j++)
        {
            sum+=w;
            w+=pre[j];
            pre[j]=0;
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}