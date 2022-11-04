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
const int maxn=500010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;

int f[maxn][30];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        f[l][0]=max(f[l][0],r);
    }
    for(int i=1;i<=maxn-5;i++)
    {
        f[i][0]=max(f[i][0],f[i-1][0]);
    }
    for(int i=1;i<=20;i++)
    {
        for(int j=0;j<=maxn-5;j++)
        {
            f[j][i]=f[f[j][i-1]][i-1];
        }
    }
    int s;
    int p;
    int R;
    int L;
    while(m--)
    {
        s=0;
        cin>>l>>r;
        if(f[l][20]<r)
        {
            cout<<-1<<endl;
            continue;
        }
        
        for(int i=20;i>=0;i--)
        {
            if(f[l][i]<r)
            {
                s+=(1<<i);
                l=f[l][i];
            }
        }
        s++;
        cout<<s<<endl;
    }
    return 0;
}