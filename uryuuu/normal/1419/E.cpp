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
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,ll> pii;
const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod = 998244353;
//#define int long long

int num;
int prime[maxn];      //
bool sf[maxn];        //sf[i]i1maxn
void sushu()
{         // 
    num=0;        //num 
    memset(sf,true,sizeof(sf));
    sf[1] = false;
    sf[0] = false;  //1 0 
    for(int i = 2;i <= maxn-5; i ++)
    {          //1~maxn
        if(sf[i]) prime[++num] = i;      //
        for(int j = 1;j <= num;j ++)
        {       //num
            if(i * prime[j] > maxn-5) break; //
            sf[i * prime[j]] = false;      //...
            if(i % prime[j] == 0) break;   //
        }
    }
}

int a[maxn],p[maxn],ans[maxn];
map<int,int>mp,vis;

int main()
{
    sync;
    sushu();
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        vis.clear();
        int x;
        cin>>x;
        int cnt=0;
        a[++cnt]=x;
        for(int i=2;i<=100000;i++)
        {
            if(i*i==x)
            {
                a[++cnt]=i;
                break;
            }
            if(i*i>x)
                break;
            if(x%i==0)
            {
                a[++cnt]=i;
                a[++cnt]=x/i;
            }
        }

        int d=x;
        int m=0;
        for(int i=1;i<=num;i++)
        {
            if(d%prime[i]==0)
            {
                p[++m]=prime[i];
                while(d%prime[i]==0)
                {
                    d/=prime[i];
                    vis[prime[i]]++;
                }
            }
            if(d==1)
                break;
        }
        if(d!=1)
            p[++m]=d;
        if(m==1)
        {
            for(int i=1;i<=cnt;i++)
                cout<<a[i]<<' ';
            cout<<endl;
            cout<<0<<endl;
            continue;
        }
//
//        for(int i=1;i<=cnt;i++)
//            cout<<a[i]<<' ';
//        cout<<endl;
//
        for(int i=1;i<=m;i++)
        {
            if(vis[p[i]]>1)
            {
                swap(p[1],p[m]);
            }
        }
        
        
        
        int n=0;
        ans[++n]=x;
        mp[x]=1;
       
        for(int i=1;i<m;i++)
        {
            ans[++n]=p[i];
            mp[p[i]]=1;
            for(int j=1;j<=cnt;j++)
            {
                if(a[j]%p[i]==0&&mp[a[j]]==0)
                {
                    if(a[j]!=p[i]*p[i+1])
                    {
                        ans[++n]=a[j];
                        mp[a[j]]=1;
                    }
                }
            }
            if(mp[p[i]*p[i+1]]==0)
            {
                ans[++n]=p[i]*p[i+1];
                mp[p[i]*p[i+1]]=1;
            }
        }
        for(int i=m;i<=m;i++)
        {
            ans[++n]=p[i];
            mp[p[i]]=1;
            for(int j=1;j<=cnt;j++)
            {
//                cout<<a[j]<<' ';
                if((a[j]%p[i]==0)&&(mp[a[j]]==0))
                {
                    ans[++n]=a[j];
                    mp[a[j]]=1;
                }
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
        if(m==2&&vis[p[1]]==1)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    return 0;
}