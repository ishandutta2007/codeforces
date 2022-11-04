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

ll a[maxn];

int main()
{
    sync;
    int t;
    ll n;
    for(int i=1;i<=100000;i++)
    {
        a[i]=1ll*(2ll*i+1ll)*(2ll*i+1ll)/2ll+1ll;
    }
    a[0]=0;
    
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
//        for(int i=1;i<=4;i++)
//            cout<<a[i]<<' ';
        int pos=upper_bound(a+1,a+100000,n)-a;
//        cout<<a[pos]<<endl;
        cout<<pos-1<<endl;
    }
    return 0;
}