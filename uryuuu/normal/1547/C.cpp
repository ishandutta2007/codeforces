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


int a[maxn],b[maxn],ans[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>k>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        
        int La=1,Lb=1;
        int cnt=0;
        while(La<=n&&Lb<=m)
        {
            if(a[La]<b[Lb])
            {
                ans[++cnt]=a[La];
                La++;
            }
            else
            {
                ans[++cnt]=b[Lb];
                Lb++;
            }
        }
        while(La<=n)
        {
            ans[++cnt]=a[La];
            La++;
        }
        while(Lb<=m)
        {
            ans[++cnt]=b[Lb];
            Lb++;
        }
        int f=0;
        for(int i=1;i<=cnt;i++)
        {
            if(ans[i]==0)
                k++;
            else
            {
                if(ans[i]>k)
                {
                    f=1;
                    break;
                }
            }
        }
//        
//        cout<<t<<' ';
//        for(int i=1;i<=cnt;i++)
//            cout<<ans[i]<<' ';
//        cout<<endl;
        
        if(f)
            cout<<-1<<endl;
        else
        {
            for(int i=1;i<=cnt;i++)
                cout<<ans[i]<<' ';
            cout<<endl;
        }
        
    }
    
    return 0;
}