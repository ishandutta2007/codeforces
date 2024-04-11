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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;



int fa[maxn];

int getf(int x)
{
    if(x==fa[x])
        return x;
    return fa[x]=getf(fa[x]);
}


int d[maxn];
int r[maxn];
int l[maxn];
int R[maxn];
int L[maxn];

int main()
{
    sync;
    int n;
    int x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        l[i]=i;
        r[i]=i;
        fa[i]=i;
        L[i]=i;
        R[i]=i;
    }
    int fx,fy;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        fx=getf(x);
        fy=getf(y);
//        cout<<fx<<' '<<fy<<' '<<l[fx]<<' '<<r[fx]<<' '<<l[fy]<<' '<<r[fy]<<endl;
        swap(r[R[fx]],l[L[fy]]);
        L[fy]=L[fx];
        fa[fx]=fy;
    }
    int st=1;
    for(int i=1;i<=n;i++)
    {
//        cout<<l[i]<<' '<<r[i]<<endl;
       if(l[i]==i)
       {
           st=i;
           break;
       }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<st<<' ';
        st=r[st];
    }
    cout<<endl;
    
    return 0;
}