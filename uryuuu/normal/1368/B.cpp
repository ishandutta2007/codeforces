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
const ll Mod=1000000007;
//const ll Mod=998244353;


ll a[20];

int main()
{
    sync;
    ll s=1ll;
    ll k;
    cin>>k;
    rep(i,0,15)
    a[i]=1ll;
    int cnt=0;
    int id;
    while(s<k)
    {
        id=cnt%10;
        s/=a[id];
        a[id]+=1ll;
        s=1ll*s*1ll*a[id];
        cnt++;
    }
    for(int i=1;i<=a[0];i++)
    {
        cout<<"c";
    }
    for(int i=1;i<=a[1];i++)
    {
        cout<<"o";
    }
    for(int i=1;i<=a[2];i++)
    {
        cout<<"d";
    }
    for(int i=1;i<=a[3];i++)
    {
        cout<<"e";
    }
    for(int i=1;i<=a[4];i++)
    {
        cout<<"f";
    }for(int i=1;i<=a[5];i++)
    {
        cout<<"o";
    }for(int i=1;i<=a[6];i++)
    {
        cout<<"r";
    }
    for(int i=1;i<=a[7];i++)
    {
        cout<<"c";
    }
    for(int i=1;i<=a[8];i++)
    {
        cout<<"e";
    }
    for(int i=1;i<=a[9];i++)
    {
        cout<<"s";
    }
    cout<<endl;
    return 0;
}