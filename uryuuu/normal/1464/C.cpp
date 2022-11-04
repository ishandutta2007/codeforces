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

string s;
ll b[maxn];
int vis[maxn];

int main()
{
    sync;
    b[0]=1ll;
    for(int i=1;i<=40;i++)
    {
        b[i]=2ll*b[i-1];
    }
    int n;
    ll d;
    cin>>n>>d;
    cin>>s;
    ll sum=0ll;
    int id;
    for(int i=0;i<n;i++)
    {
        id=ch(s[i]);
        sum=1ll*sum+b[id-1];
        if(i<n-2)
        {
            vis[id]++;
        }
        if(i==n-2)
        {
            sum-=b[id];
        }
    }
    for(int i=26;i>=1;i--)
    {
        while(vis[i]--)
        {
            if(sum-b[i]>=d)
            {
                sum=1ll*sum-b[i];
            }
        }
    }
    if(sum==d)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    
    
    return 0;
}