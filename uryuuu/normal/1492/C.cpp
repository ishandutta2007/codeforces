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
#include <chrono>
#include <random>
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
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

string ss;
int s[maxn],t[maxn],mx[maxn],mn[maxn];
int nxt[maxn][28],pre[maxn][28];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    cin>>ss;
    for(int i=1;i<=n;i++)
        s[i]=ch(ss[i-1]);
    cin>>ss;
    for(int i=1;i<=m;i++)
        t[i]=ch(ss[i-1]);
    for(int i=1;i<=26;i++)
    {
        nxt[n+1][i]=n+1;
        pre[0][i]=0;
    }
    int j;
    for(int i=1;i<=n;i++)
    {
        for(j=1;j<=26;j++)
            pre[i][j]=pre[i-1][j];
        pre[i][s[i]]=i;
    }
    for(int i=n;i>=1;i--)
    {
        for(j=1;j<=26;j++)
            nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]]=i;
    }
    
    int pos;
    
    pos=1;
    for(int i=1;i<=m;i++)
    {
        mn[i]=nxt[pos][t[i]];
        pos=mn[i]+1;
    }
    
    pos=n;
    for(int i=m;i>=1;i--)
    {
        mx[i]=pre[pos][t[i]];
        pos=mx[i]-1;
    }
//    for(int i=1;i<=m;i++)
//        cout<<mn[i]<<' ';
//    cout<<endl;
//    for(int i=1;i<=m;i++)
//        cout<<mx[i]<<' ';
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//        cout<<nxt[i][3]<<' ';
//    cout<<endl;
    
    int ans=0;
    for(int i=2;i<=n;i++)
    {
        ans=max(ans,mx[i]-mn[i-1]);
    }
    cout<<ans<<endl;
    
    return 0;
}