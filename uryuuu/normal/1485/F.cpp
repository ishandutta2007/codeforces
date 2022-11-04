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

map<ll,ll>mp;
ll b[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        mp[0]=1ll;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>b[i];
        ll change=0,sum=1ll;
        ll tmp;
        for(int i=1;i<=n;i++)
        {
            change-=b[i];
            tmp=sum-mp[b[i]+change];
            mp[b[i]+change]=sum;
            sum=(1ll*sum+tmp)%Mod;
        }
        cout<<(sum%Mod+Mod)%Mod<<endl;
    }
    
    
    return 0;
}