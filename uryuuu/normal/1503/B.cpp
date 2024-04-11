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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;



struct node
{
    int x,y;
}a[3][maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    int x,y,op;
    int f;
    int s1=0;
    int s2=0;
    int L1=0,L2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2==0)
                a[1][++s1]={i,j};
            else
                a[2][++s2]={i,j};
        }
    }
    
    for(int i=1;i<=n*n;i++)
    {
        cin>>op;
        if(op==1)
        {
            if(L2==s2)
            {
                L1++;
                cout<<3<<' '<<a[1][L1].x<<' '<<a[1][L1].y<<endl;
            }
            else
            {
                L2++;
                cout<<2<<' '<<a[2][L2].x<<' '<<a[2][L2].y<<endl;
            }
        }
        else if(op==2)
        {
            if(L1==s1)
            {
                L2++;
                cout<<3<<' '<<a[2][L2].x<<' '<<a[2][L2].y<<endl;
            }
            else
            {
                L1++;
                cout<<1<<' '<<a[1][L1].x<<' '<<a[1][L1].y<<endl;
            }
        }
        else
        {
            if(L1==s1)
            {
                L2++;
                cout<<2<<' '<<a[2][L2].x<<' '<<a[2][L2].y<<endl;
            }
            else
            {
                L1++;
                cout<<1<<' '<<a[1][L1].x<<' '<<a[1][L1].y<<endl;
            }
        }
    }
    
    
    return 0;
}