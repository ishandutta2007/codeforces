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
const double pi=acos(-1);
const int maxn=3010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

ll s[maxn][maxn],mp[maxn][maxn];
ll n,m,a,b,x,y,z,g;
ll st[maxn*maxn];
int main()
{
    sync;
    cin>>n>>m>>a>>b>>g>>x>>y>>z;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            s[i][j]=g;
            g=(1ll*g*x+y)%z;
        }
    }

    for(int i=1;i<=m;i++)
    {
        int head=2;
        int tail=1;
        for(int j=1;j<=n;j++)
        {
            while(head<=tail&&st[head]+a<=j)
                head++;
            while(tail>=head&&s[j][i]<=s[st[tail]][i])
                tail--;
            st[++tail]=j;
            mp[j][i]=s[st[head]][i];
        }
    }
    
    ll sum=0;
    for(int i=a;i<=n;i++)
    {
        int head=2;
        int tail=1;
        for(int j=1;j<=m;j++)
        {
            while(head<=tail&&st[head]+b<=j)
                head++;
            while(tail>=head&&mp[i][j]<=mp[i][st[tail]])
                tail--;
            st[++tail]=j;
            if(j>=b)
            {
                sum+=mp[i][st[head]];
            }
        }
    }
    cout<<sum<<endl;

    
    return 0;
}