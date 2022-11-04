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
typedef vector<int> vi;
const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;



ll a[205],b[305];
ll v[205];
int f=0;
ll k;
int cnt;

void dfs(ll x,int s)
{
    if(x==0)
        return ;
    while(x%k==0)
    {
        x/=k;
        s++;
    }
    if(x==1)
    {
        if(v[s]==1)
        {
            f=1;
        }
        else
        {
            v[s]=1;
        }
        return;
    }
    x-=1;
    if(v[s]==1)
    {
        f=1;
        return;
    }
    else
    {
        v[s]=1;
    }
    
    if(x%k==0)
        dfs(x,s);
    else
    {
        f=1;
        return;
    }
    return;
}



int main()
{
    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        mm(v);
        cin>>n>>k;
        ll zd=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            zd=max(a[i],zd);
        }
        mm(b);
        cnt=n;
        b[0]=1ll;
        for(int i=1;i<=n;i++)
        {
            b[i]=1ll*b[i-1]*k;
            if(b[i]>zd)
            {
                cnt=i-1;
                break;
            }
        }
        if(zd==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
                continue;
            f=0;
            dfs(a[i],0);
            if(f)
                break;
        }
        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    return 0;
}