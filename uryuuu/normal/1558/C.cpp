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
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=5025;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
int ans[maxn*10];
int n;

void solve()
{
    int cnt=0;
    int i;
    int pos,j;
    for(int k=n;k>=3;k-=2)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i]==k)
            {
                if(i%2==0)
                {
                    cout<<-1<<endl;
                    return;
                }

                for(j=1;j<=n;j++)
                {
                    if(a[j]==k-1)
                    {
                        pos=j;
                        break;
                    }
                }
                if(pos%2)
                {
                    cout<<-1<<endl;
                    return;
                }
                ans[++cnt]=i;
                reverse(a+1,a+i+1);
                for(j=1;j<=n;j++)
                {
                    if(a[j]==k-1)
                    {
                        pos=j;
                        break;
                    }
                }
                ans[++cnt]=pos-1;
                reverse(a+1,a+pos);
                
                i=pos-1;
                ans[++cnt]=i+2;
                reverse(a+1,a+i+3);
                ans[++cnt]=3;
                reverse(a+1,a+4);
                ans[++cnt]=k;
                reverse(a+1,a+k+1);
                break;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
//        cout<<a[i]<<' ';
        if(a[i]!=i)
        {
            cout<<-1<<endl;
            return;
        }
    }
    
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        solve();
    }
    return 0;
}