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


string s;
int a[maxn];
int b[maxn];
int vis[30];
int sum[30];
int d[30];
int pre[30];

int cmp(int L1,int R1,int L2,int R2,int x)
{
    for(int i=L2;i<=R2;i++)
    {
        while(L1<=R1&&a[L1]==x)
        {
            L1++;
        }
        if(L1>R1)
            return 1;
        if(a[L1]!=a[i])
            return 1;
        L1++;
    }
    while(L1<=R1&&a[L1]==x)
    {
        L1++;
    }
//    cout<<"HH"<<' '<<L1<<' '<<R1<<endl;
    if(L1<=R1)
        return 1;
    return 0;
}

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        mm(vis);
        mm(sum);
        mm(d);
        int id,cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            id=ch(s[i]);
            a[i]=id;
            sum[id]++;
            if(vis[id]==0)
            {
                b[++cnt]=id;
                vis[id]=1;
            }
        }
        int f=0;
        pre[0]=0;
        for(int i=1;i<=cnt;i++)
        {
            id=b[i];
//            cout<<id<<' '<<sum[id]<<' '<<(cnt-i+1)<<' '<<sum[id]%(cnt-i+1)<<endl;
            d[id]=sum[id]/(cnt-i+1);
            if(sum[id]%(cnt-i+1))
                f=1;
            pre[i]=pre[i-1]+d[id];
        }
//        cout<<f<<endl;
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        int L1=0,R1,L2,R2;
        
//        for(int i=0;i<n;i++)
//            cout<<a[i]<<' ';
        
        for(int i=cnt;i>1;i--)
        {
            L2=L1+pre[i];
            R1=L2-1;
            R2=L2+pre[i-1]-1;
            f=max(f,cmp(L1,R1,L2,R2,b[i]));
//            cout<<L1<<' '<<R1<<' '<<L2<<' '<<R2<<' '<<b[i]<<' ';
//            for(int i=L1;i<=R1;i++)
//                cout<<a[i];
//            cout<<' ';
//            for(int i=L2;i<=R2;i++)
//                cout<<a[i];
//            cout<<endl;
            
            L1=L2;
        }
        if(f)
            cout<<-1<<endl;
        else
        {
            for(int i=0;i<pre[cnt];i++)
            {
                cout<<s[i];
            }
            cout<<' ';
            for(int i=cnt;i>=1;i--)
                cout<<char('a'+b[i]-1);
            cout<<endl;
        }
//        cout<<"F"<<endl;
        
    }
    return 0;
}