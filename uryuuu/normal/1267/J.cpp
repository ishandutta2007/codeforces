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
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-10
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=2000005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn];
unordered_map<int,int>mp;
int b[maxn];
int vis[maxn];
void check(int x,int s)
{
    if(x<=0)
        return;
    if(s%x==0)
    {
        mp[x]=1;
        return;
    }
    if(s%(x-1)<=s/(x-1))
        mp[x]=1;
}

int main()
{
//    sync;
    int t;
//    cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x;
        
//        cin>>n;
        scanf("%d",&n);
        int cnt=0,id;
        for(int i=1;i<=n;i++)
        {
//            cin>>a[i];
            scanf("%d",&a[i]);
            vis[i]=0;
            b[i]=0;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i-1])
                cnt++;
            b[cnt]++;
        }
        int L,R;
        
        int mx=1;
        for(int i=1;i<=cnt;i++)
        {
            x=b[i];
            mp.clear();
            mp.reserve(1024);
            mp.max_load_factor(0.25);
            for(L=1;L<=x;)
            {
                id=x/L;
                R=x/id;
                check(id+2,x);
                check(id+1,x);
                check(id,x);
                check(id-1,x);
                L=R+1;
            }
            for(auto f:mp)
            {
                vis[f.first]++;
                if(vis[f.first]==cnt)
                    mx=max(f.first,mx);
            }
        }
//        cout<<mx<<endl;
        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            x=b[i];
//            cout<<x<<' ';
            if(x%mx==0)
            {
                ans+=x/mx;
            }
            else
            {
                ans+=(x/mx+1);
            }
        }
//        cout<<ans<<endl;
        printf("%d\n",ans);
    }
    return 0;
}

//1 1 1 3