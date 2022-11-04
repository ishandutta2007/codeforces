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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;
//typedef pair<pii,int> piii;

int a[maxn];
int vis[maxn];
int ans[maxn][3];

int main()
{
    sync;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>a[i];
    ans[1][0]=1;
    ans[n][2]=1;
    for(int i=k;i>=1;i--)
    {
        ans[a[i]][1]=1;
        if(vis[a[i]-1])
            ans[a[i]][0]=1;
        if(vis[a[i]+1])
            ans[a[i]][2]=1;
        vis[a[i]]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=2;j++)
            if(ans[i][j]==0)
                sum++;
    }
    cout<<sum<<endl;
    return 0;
}