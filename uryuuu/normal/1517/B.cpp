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
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;

int b[200][200];
int ans[200][200];
struct node
{
    int val,id;
}a[200];
bool cmp(node a,node b)
{
    return a.val>b.val;
}

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int j;
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                cin>>b[i][j];
            sort(b[i]+1,b[i]+m+1);
        }
        for(int i=1;i<=m;i++)
        {
            a[i].id=i;
            a[i].val=2e9;
        }
        for(int i=1;i<=n;i++)
        {
            sort(a+1,a+m+1,cmp);
            for(j=1;j<=m;j++)
            {
                ans[i][a[j].id]=b[i][j];
                a[j].val=min(a[j].val,b[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                cout<<ans[i][j]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    
    return 0;
}