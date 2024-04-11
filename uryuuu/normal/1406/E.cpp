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
const int maxn=100005;
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
    for(int i = 2;i <=100000; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] >100000) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

int b[maxn];
vector<int>g[maxn];

int main()
{
    sync;
    sushu();
//    cout<<num<<endl;
    int cnt=0;
    int n;
    cin>>n;
    int ans;
    int sq=int(sqrt(num))+1;
    
    int m=0;
    for(int i=1;i<=num;i++)
    {
        if(prime[i]>n)
            break;
        g[i/sq].push_back(prime[i]);
        m=i/sq;
    }
    
    int lst=n;
    int d=0;
    for(int i=0;i<=m;i++)
    {
        d=lst;
        for(int v:g[i])
        {
            cout<<"B "<<v<<endl;
            cin>>ans;
            d-=ans;
        }
        cout<<"A "<<1<<endl;
        cin>>ans;
        if(ans==d)
        {
            lst=d;
            continue;
        }
        lst=ans;
        for(int v:g[i])
        {
            cout<<"B "<<v<<endl;
            cin>>ans;
            if(ans)
                b[++cnt]=v;
        }
    }
    
    ll x=1ll;
    ll pre,s;
    for(int i=1;i<=cnt;i++)
    {
        s=b[i];
        pre=s;
        while(pre<=n)
        {
            cout<<"A "<<pre<<endl;
            cin>>ans;
            if(ans==0)
                break;
            pre*=s;
        }
        pre/=s;
        x*=pre;
    }
    cout<<"C "<<x<<endl;
    
    
    return 0;
}