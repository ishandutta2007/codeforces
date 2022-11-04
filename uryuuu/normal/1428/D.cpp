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
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[maxn];
struct node
{
    int y1,y2;
}X[maxn];

int b1[maxn],b2[maxn],b3[maxn];
struct nod
{
    int x,y;
}ans[maxn];

int visx[maxn],visy[maxn],vis[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    int st=1;
    int m1=0,m2=0,m3=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {
            b1[++m1]=i;
        }
        else if(a[i]==2)
        {
            b2[++m2]=i;
        }
        else if(a[i]==3)
        {
            b3[++m3]=i;
        }
        X[i].y1=0;
        X[i].y2=0;
    }
    int L=1;
    for(int i=1;i<m3;i++)
    {
        X[b3[i]].y1=st;
        X[b3[i+1]].y2=st;
        st++;
    }
    int F=0;
    L=1;
    if(m3)
    {
        while(b2[L]<=b3[m3]&&L<=m2)
        {
            L++;
        }
        if(L<=m2)
        {
            F=1;
            X[b3[m3]].y1=st;
            X[b2[L]].y2=st;
            X[b2[L]].y1=st+1;
            st++;
            st++;
        }
    }
    L=1;
    if(m3&&F==0)
    {
        while(b1[L]<=b3[m3]&&L<=m1)
        {
            L++;
        }
        if(L>m1)
        {
            cout<<-1<<endl;
            return 0;
        }
        vis[b1[L]]=1;
        X[b3[m3]].y1=st;
        X[b1[L]].y2=st;
        X[b1[L]].y1=st+1;
        st++;
        st++;
    }
    
    L=1;
    for(int i=1;i<=m2;i++)
    {
        while(b1[L]<=b2[i]&&L<=m1)
        {
            L++;
        }
        if(L>m1)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(vis[b1[L]])
        {
            L++;
        }
        if(L>m1)
        {
            cout<<-1<<endl;
            return 0;
        }
        if(X[b2[i]].y1==0)
        {
            if(st>n)
            {
                cout<<-1<<endl;
                return 0;
            }
            X[b2[i]].y1=st;
            st++;
        }
        X[b1[L]].y1=X[b2[i]].y1;
        L++;
    }

    for(int i=1;i<=m1;i++)
    {
        if(X[b1[i]].y1==0)
        {
            if(st>n)
            {
                cout<<-1<<endl;
                return 0;
            }
            X[b1[i]].y1=st;
            st++;
        }
    }
    
    
    int c=0;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        if(X[i].y2)
        {
            ans[++c].x=X[i].y2;
            ans[c].y=i;
        }
        if(X[i].y1)
        {
            ans[++c].x=X[i].y1;
            ans[c].y=i;
        }
    }
    for(int i=1;i<=c;i++)
    {
        visx[ans[i].x]++;
        visy[ans[i].y]++;
        if(visx[ans[i].x]>2)
            f=1;
        if(visy[ans[i].y]>2)
            f=1;
    }
    if(f)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    
    cout<<c<<endl;
    for(int i=1;i<=c;i++)
    {
        cout<<ans[i].x<<' '<<ans[i].y<<endl;
    }
    
    
    return 0;
}