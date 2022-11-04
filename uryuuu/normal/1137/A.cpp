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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1005;
const ll Mod=1000000007;
//const ll Mod=998244353;


int a[maxn][maxn];
int rmn[maxn][maxn],rmx[maxn][maxn];
int cmn[maxn][maxn],cmx[maxn][maxn];
unordered_map<int,int>pos;
int b[maxn];

int main()
{
    sync;
    int t;
    int n;
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    }
    int cnt;
    for(int i=1;i<=n;i++)
    {
        pos.clear();
        for(int j=1;j<=m;j++)
        {
            b[j]=a[i][j];
        }
        sort(b+1,b+m+1);
        cnt=unique(b+1,b+m+1)-b-1;
        for(int j=1;j<=cnt;j++)
            pos[b[j]]=j;
        for(int j=1;j<=m;j++)
        {
            rmn[i][j]=pos[a[i][j]]-1;
            rmx[i][j]=cnt-pos[a[i][j]];
        }
    }
    
    
    for(int i=1;i<=m;i++)
    {
        pos.clear();
        for(int j=1;j<=n;j++)
        {
            b[j]=a[j][i];
        }
        sort(b+1,b+n+1);
        cnt=unique(b+1,b+n+1)-b-1;
        for(int j=1;j<=cnt;j++)
            pos[b[j]]=j;
        for(int j=1;j<=n;j++)
        {
            cmn[j][i]=pos[a[j][i]]-1;
            cmx[j][i]=cnt-pos[a[j][i]];
        }
    }
    
    int ans;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=max(cmn[i][j],rmn[i][j])+max(rmx[i][j],cmx[i][j])+1;
            cout<<ans<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}