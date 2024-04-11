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
const int maxn=2000010;
const ll Mod=1000000007;
//const ll Mod=998244353;


ll a[maxn];
int b[maxn];

int main()
{
    sync;
    int t;
    ll n;
    a[1]=0;
    a[2]=0;
    a[3]=1;
    a[4]=1;
    a[5]=3;
    b[1]=0;
    b[2]=0;
    b[3]=1;
    b[4]=0;
    b[5]=0;
    for(int i=6;i<=2000004;i++)
    {
       if(b[i-1]||b[i-2])
       {
           a[i]=(1ll*a[i-1]+2ll*a[i-2]%Mod)%Mod;
           b[i]=0;
       }
        else
        {
            a[i]=(1ll+1ll*a[i-1]+2ll*a[i-2]%Mod)%Mod;
            b[i]=1;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<4ll*a[n]%Mod<<endl;
    }
    
    return 0;
}