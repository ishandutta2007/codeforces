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
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn][maxn];
int ans[200000][5];
string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int i,j;
        for(i=0;i<=n+1;i++)
            for(j=0;j<=m+1;j++)
                a[i][j]=0;
        int cnt=0;
        for(i=1;i<=n;i++)
        {
            cin>>s;
            for(j=1;j<=m;j++)
            {
                a[i][j]=int(s[j-1]-'0');
            }
        }
        if(a[1][1])
        {
            cout<<-1<<'\n';
            continue;
        }
        
        for(i=1;i<=n;i++)
        {
            for(j=m;j>=2;j--)
            {
                if(a[i][j]==0)
                    continue;
                cnt++;
                ans[cnt][1]=i;
                ans[cnt][2]=j-1;
                ans[cnt][3]=i;
                ans[cnt][4]=j;
            }
        }
        for(i=n;i>=2;i--)
        {
            if(a[i][1]==0)
                continue;
            cnt++;
            ans[cnt][1]=i-1;
            ans[cnt][2]=1;
            ans[cnt][3]=i;
            ans[cnt][4]=1;
        }
        cout<<cnt<<'\n';
        for(i=1;i<=cnt;i++)
        {
            for(j=1;j<=4;j++)
                cout<<ans[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}