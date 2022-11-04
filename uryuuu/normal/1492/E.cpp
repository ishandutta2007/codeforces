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
const int maxn=300005;
//const ll Mod=1000000007;
const ll Mod=998244353;


vector<int>g[maxn];
unordered_map<int,int>mp;
int ans[maxn],sz[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int i,j;
    int a[n+5][m+5];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    
    for(j=1;j<=m;j++)
    {
//        mp.clear();
        for(i=1;i<=n;i++)
        {
//            if(mp[a[i][j]]==0)
//            {
//                mp[a[i][j]]=1;
//
//            }
            g[j].push_back(a[i][j]);
        }
        sz[j]=g[j].size();
    }
    
    srand(unsigned(time(0)));
    srand(rand());

    int k=2000,f=0,s;
    while(k>0)
    {
        k--;
        for(i=1;i<=m;i++)
        {
            ans[i]=g[i][rand()%sz[i]];
        }
//        for(i=1;i<=m;i++)
//            cout<<ans[i]<<' ';
//        cout<<endl;

        f=0;
        for(i=1;i<=n;i++)
        {
            s=0;
            for(j=1;j<=m;j++)
            {
                if(ans[j]!=a[i][j])
                    s++;
                if(s>2)
                    break;
            }
            if(s>2)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<"Yes"<<endl;
            for(i=1;i<=m;i++)
                cout<<ans[i]<<' ';
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    
    return 0;
}