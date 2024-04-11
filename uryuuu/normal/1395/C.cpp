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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef pair<ll,ll> pll;
//const double pi=acos(-1);
const int maxn = 210;
//const ll Mod=1000000007;
const ll Mod = 998244353;

int a[maxn],b[maxn];


int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=1;j<=m;j++)
        cin>>b[j];
    int s=512;
    int f=0,fl=0;
    for(int k=511;k>=0;k--)
    {
        f=0;
        for(int i=1;i<=n;i++)
        {
            fl=0;
            for(int j=1;j<=m;j++)
            {
                if((k|(a[i]&b[j]))==k)
                {
                    fl=1;
                    break;
                }
            }
            if(fl==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            s=k;
    }
    cout<<s<<endl;
    return 0;
}