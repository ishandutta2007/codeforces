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

int a[maxn];
int vis[maxn];
map<int,int>mp;

int main()
{
    sync;
    int t;
    cin>>t;
    int n,k;
    while(t--)
    {
        cin>>n;
        mp.clear();
        int f=0;
        rep(i,1,n)
        {
            cin>>a[i];
            vis[i]=0;
            mp[a[i]]++;
            if(mp[a[i]]>(n+1)/2)
            {
                f=1;
            }
        }
        if(f)
        {
            cout<<-1<<endl;
            continue;
        }
        k=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i+1])
            {
                vis[a[i]]+=2;
                k++;
            }
        }
        vis[a[1]]++;
        vis[a[n]]++;
        sort(vis+1,vis+n+1);
        cout<<k+max(0,vis[n]-k-2)<<endl;
    }
    return 0;
}