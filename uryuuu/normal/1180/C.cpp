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
const double pi=acos(-1);
const int maxn=400005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


int a[maxn];
struct node
{
    int x, y;
}b[maxn];
int d[maxn];

int main()
{
    sync;
    ll n,m;
    cin>>n>>m;
    int zd=0;
    int id;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(zd<a[i])
        {
            id=i;
            zd=a[i];
        }
    }
    int L=1,R=n;
    ll cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(a[L]==zd)
            break;
        b[cnt].x=a[L];
        b[cnt++].y=a[L+1];
        if(a[L]>a[L+1])
        {
            swap(a[L],a[L+1]);
        }
        a[++R]=a[L];
        L++;
    }
    cnt--;
    for(int i=1,pos=L;i<=n;i++,pos++)
    {
        d[i]=a[pos];
//        cout<<d[i]<<' ';
    }
//    cout<<endl<<cnt<<endl;
    ll k;
    while(m--)
    {
        cin>>k;
        if(k<=cnt)
        {
            cout<<b[k].x<<' '<<b[k].y<<endl;
        }
        else
        {
            k-=cnt;
            k=(k-1)%(n-1)+2;
            cout<<d[1]<<' '<<d[k]<<endl;
        }
    }
    return 0;
}