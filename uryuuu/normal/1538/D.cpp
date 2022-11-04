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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=50005;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll num;
ll prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] > maxn) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

int main()
{
    sync;
    sushu();
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;
        if(a>b)
            swap(a,b);
        if(k==1)
        {
            if(b%a==0&&b!=a)
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
            continue;
        }
        
        
        int sum=0;
        for(int i=1;i<=num;i++)
        {
            if(a<prime[i])
                break;
            if(a%prime[i])
                continue;
            while(a%prime[i]==0)
            {
                sum++;
                a/=prime[i];
            }
        }
        if(a>1)
            sum++;
        
        for(int i=1;i<=num;i++)
        {
            if(b<prime[i])
                break;
            if(b%prime[i])
                continue;
            while(b%prime[i]==0)
            {
                sum++;
                b/=prime[i];
            }
        }
        if(b>1)
            sum++;
        
//        cout<<sum<<' '<<k<<endl;
        if(sum>=k)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        
    }
    return 0;
}