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
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int num;
int prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <=200000; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] > 200000) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

long long gcd(long long a,long long b)
{
    if(a==0)
        return 1;
    if(a<0)
        return gcd(-a,b);
    while(b)
    {
        long long t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int a[maxn];
unordered_map<int,int>mp[maxn];
int cnt[maxn];
int b[maxn];

int main()
{
    sync;
    num=0;
    sushu();
    int n,q;
    cin>>n>>q;
    int i,j;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll gd=1ll*a[1];
    for(int i=1;i<=n;i++)
    {
        gd=gcd(gd,1ll*a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i]/gd;
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=num;j++)
        {
            if(a[i]==1)
                break;
            if(sf[a[i]])
            {
                mp[i][a[i]]++;
                cnt[a[i]]++;
                break;
            }
            if(a[i]%prime[j]==0)
                cnt[prime[j]]++;
            while(a[i]%prime[j]==0)
            {
                mp[i][prime[j]]++;
                a[i]/=prime[j];
            }
        }
    }
    
    int tot;
    int pos,x;
    while(q--)
    {
        cin>>pos>>x;
        tot=0;
        if(x==1)
        {
            cout<<gd<<endl;
            continue;
        }
        for(j=1;j<=num;j++)
        {
            if(x==1)
                break;
            if(sf[x])
            {
                b[++tot]=x;
                break;
            }
            while(x%prime[j]==0)
            {
                b[++tot]=prime[j];
                x/=prime[j];
            }
        }
        for(i=1;i<=tot;i++)
        {
            x=b[i];
            if(mp[pos][x]==0)
            {
                mp[pos][x]++;
                cnt[x]++;
                if(cnt[x]==n)
                {
                    gd=1ll*gd*(1ll*x)%Mod;
                    cnt[x]=0;
                    for(int j=1;j<=n;j++)
                    {
                        mp[j][x]--;
                        if(mp[j][x]>0)
                            cnt[x]++;
                    }
                }
            }
            else
            {
                mp[pos][x]++;
            }
        }
        cout<<gd<<endl;
    }
    return 0;
}