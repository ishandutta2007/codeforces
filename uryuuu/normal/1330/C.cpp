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
#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;




ll a[maxn];
ll p[maxn];
ll b[maxn];
ll cnt[maxn];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    int f=0;
    ll s=0;
    for(int i=1;i<=m;i++)
    {
        cin>>p[i];
        b[i]=s+1;
        s+=p[i];
        if(p[i]+i-1>n)
            f=1;
    }
    if(s<n||f==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll d=s-n;
    ll mx;
    for(int i=2;i<=m;i++)
    {
        mx=min(p[i-1]-1,d);
        d-=mx;
        cnt[i]-=mx;
        if(d==0)
            break;
    }
    for(int i=3;i<=m;i++)
    {
        cnt[i]+=cnt[i-1];
    }
//    for(int i=1;i<=m;i++)
//    {
//        cout<<b[i]<<' ';
//    }
//    cout<<endl;
//    for(int i=1;i<=m;i++)
//    {
//        cout<<cnt[i]<<' ';
//    }
//    cout<<endl;
    
    for(int i=1;i<=m;i++)
    {
        b[i]+=cnt[i];
        cout<<b[i]<<' ';
    }
    
    cout<<endl;
    
    return 0;
}