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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

const ll INF=1e18+2;
ll a[maxn],ans=1e18+2;
int n;
int x;
ll solve(ll k)
{
    ll rs=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>k)
            rs+=min(a[i]%k,k-a[i]%k);
        else
            rs+=k-a[i];
    }
    return rs;
}


ll work(ll k)
{
    ll rs=INF;
    if(k==0)
        return INF;
    for(ll i=2;i<=k/i;i++)
    {
        if(k%i==0)
        {
            rs=min(rs,solve(i));
            while(k%i==0)
                k/=i;
        }
    }
    if(k!=1)
        rs=min(rs,solve(k));
    return rs;
}

int main()
{
    sync;
    cin>>n;
    srand(unsigned(time(0)));
    srand(rand());
//    #include <chrono>
//    #include <random>
//    int count = rand() % 3 + 1;    //1~3
//    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    mt19937 rand_num(seed);  // 
//    uniform_int_distribution<long long> dist(0, 1000000000);  // 
//    cout<<dist(rand_num)<<endl;  //rand_num  dist 
    
//    mt19937_64 ys(time(0));
//    int id=ys()%n+1;
    srand(rand());
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    random_shuffle(a+1,a+n+1);
    for(int i=1;i<=min(n,30);i++)
    {
        ans=min(ans,work(a[i]-1));
        ans=min(ans,work(a[i]+1));
        ans=min(ans,work(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}