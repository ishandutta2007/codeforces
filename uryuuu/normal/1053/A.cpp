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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
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

int main()
{
    sync;
    ll n,m,k,gd,lst,nn,mm;
    cin>>n>>m>>k;
    nn=2ll*n;
    gd=gcd(nn,k);
    lst=k/gd;
    if(m%lst==0)
    {
        nn/=gd;
        if(nn<=n)
        {
            m/=lst;
            cout<<"YES"<<endl;
            cout<<0<<' '<<0<<endl;
            cout<<nn<<' '<<0<<endl;
            cout<<nn<<' '<<m<<endl;
            return 0;
        }
    }
    
    
    mm=2ll*m;
    gd=gcd(mm,k);
//    cout<<mm<<' '<<k<<' '<<gd<<endl;
    lst=k/gd;
    if(n%lst==0)
    {
        mm/=gd;
        if(mm<=m)
        {
            n/=lst;
            cout<<"YES"<<endl;
            cout<<0<<' '<<0<<endl;
            cout<<n<<' '<<0<<endl;
            cout<<n<<' '<<mm<<endl;
            return 0;
        }
    }
    
    cout<<"NO"<<endl;
    
    return 0;
}