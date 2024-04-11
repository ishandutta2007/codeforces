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


ll a[maxn],pre[maxn];
map<ll,int>mp;

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        n=0;
        for(auto f:mp)
        {
            a[++n]=f.second;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+a[i];
        }
        int ans=1e8,sum;
        int L,R;
        for(int i=0;i<=a[n];i++)
        {
            sum=0;
            L=lower_bound(a+1,a+n+1,i)-a-1;
            sum+=pre[L];
            R=upper_bound(a+1,a+n+1,i)-a;
            sum+=((pre[n]-pre[R-1])-i*(n-R+1));
            ans=min(sum,ans);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}