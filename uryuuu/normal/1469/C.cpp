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
//const double pi=acos(-1);
const int maxn=500010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;


ll a[maxn];


int main()
{
    sync;
    int t;
    int n;
    ll k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        ll L=a[1],R=a[1];
        int f=0;
        for(int i=2;i<=n;i++)
        {
            L=L-k+1ll;
            R=R+k-1ll;
            if(R<a[i]||L>a[i]+k-1ll)
            {
                f=1;
                break;
            }
            L=max(L,a[i]);
            R=min(R,a[i]+k-1);
            if(L>R)
            {
                f=1;
                break;
            }
//            cout<<L<<' '<<R<<endl;
        }
        if(f==0&&(L>a[n]||R<a[n]))
        {
            f=1;
        }
        if(f)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    
    
    return 0;
}