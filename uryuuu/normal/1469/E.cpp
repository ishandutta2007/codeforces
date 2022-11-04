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
const int maxn=2000010;  // 
const ll Mod=1000000007;
//const ll Mod = 998244353;

int a[1<<23];
map<int,int>vis;
int ans[maxn];
string s;
int sum[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        ll pre=0;
        ll up=min(21,k);
        ll lmt=1ll<<up;
        vis.clear();
        for(int i=0;i<=n;i++)
        {
            sum[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=1-(s[i-1]-'0');
            sum[i]=sum[i-1]+a[i];
        }
        
        for(int i=k;i<=n;i++)
        {
            pre=0ll;
            for(int j=up-1;j>=0;j--)
            {
                pre=2ll*pre+a[i-j];
            }
            if(sum[i-up]-sum[i-k]==0)
                vis[pre]=1;
//            cout<<pre<<endl;
        }
        
        int f=0;
        ll x;
        for(int i=0;i<lmt;i++)
        {
            if(vis[i]==0)
            {
                x=i;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=k-up;i++)
            {
                cout<<0;
            }
            for(int i=1;i<=up;i++)
            {
                if(x%2)
                    ans[i]=1;
                else
                    ans[i]=0;
                x/=2;
            }
            for(int i=up;i>=1;i--)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}