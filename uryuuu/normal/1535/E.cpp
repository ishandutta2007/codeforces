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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn],c[maxn];
int anc[maxn][21];

int main()
{
    sync;
    int q;
    cin>>q>>a[1]>>c[1];
    int op;
    int u=1;
    int j;
    int v;
    int sum;
    ll cost;
    int nd;
    int fv;
    int s;
    for(int i=2;i<=q+1;i++)
    {
        cin>>op;
        if(op==1)
        {
            u=i;
//            cout<<u<<endl;
            cin>>anc[u][0]>>a[u]>>c[u];
            anc[u][0]++;
            for(j=1;j<=20;j++)
                anc[u][j]=anc[anc[u][j - 1]][j - 1];
        }
        else
        {
            cin>>v>>nd;
            v++;
            sum=0;
            cost=0;
//            cout<<v<<' '<<anc[v][0]<<' '<<a[v]<<' '<<a[anc[v][0]]<<endl;
            while(a[v]>0&&nd>0)
            {
                fv=v;
                for(j=20;j>=0;j--)
                {
                    if(a[anc[fv][j]]>0)
                    {
                        fv=anc[fv][j];
                    }
                }
                s=min(a[fv],nd);
                nd-=s;
                a[fv]-=s;
                sum+=s;
                cost+=1ll*c[fv]*s;
            }
            cout<<sum<<' '<<cost<<endl;
        }
    }
    
    return 0;
}