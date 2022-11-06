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
//#include<unordered_map>
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
//const double pi=acos(-1);
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int p[maxn];
int a[maxn];
int nxt[maxn];
int R[maxn];
int b[maxn][20];
string s;

int main()
{
    sync;
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<n;i++)
    {
        nxt[p[i]]=p[i+1];
    }
    nxt[p[n]]=p[1];
    for(int i=1;i<=m;i++)
        cin>>a[i];
    int x;
    s="";
    if(n==1)
    {
        while(q--)
        {
            cin>>x>>x;
            s+='1';
        }
        cout<<s<<endl;
        return 0;
    }
    int d;
    mm(p);
    for(int i=m;i>=1;i--)
    {
        p[a[i]]=i;
        b[i][0]=p[nxt[a[i]]];
    }
    
    for(int i=m;i>=1;i--)
    {
        for(int j=1;j<=20;j++)
        {
            x=b[i][j-1];
            if(x==0)
                break;
            b[i][j]=b[x][j-1];
        }
        d=n-1;
        R[i]=i;
        for(int j=19;j>=0;j--)
        {
            if(d>=(1<<j))
            {
                d-=(1<<j);
                R[i]=b[R[i]][j];
            }
        }
    }
    
    for(int i=m-1;i>=1;i--)
    {
        if(R[i+1])
        {
            if(R[i]==0)
                R[i]=R[i+1];
            else
                R[i]=min(R[i],R[i+1]);
        }
    }
    int l,r;
    
    
//    for(int i=1;i<=m;i++)
//    {
//        cout<<i<<' '<<R[i]<<endl;
//    }
//

    while(q--)
    {
        cin>>l>>r;
        if(R[l]!=0&&R[l]<=r)
            s+='1';
        else
            s+='0';
    }
    cout<<s<<endl;
    return 0;
}