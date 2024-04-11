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
//const ll Mod=1000000007;
const ll Mod = 998244353;

int a[2020][2020];
ll ans[20];
string s;
int rmin[20],rmax[20],cmax[20],cmin[20];

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<=15;i++)
        {
            rmin[i]=9999;
            cmin[i]=9999;
            rmax[i]=0;
            cmax[i]=0;
        }
        mm(ans);
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=n;j++)
            {
                a[i][j]=int(s[j-1]-'0');
            }
        }
        int d;
        ll len,h;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d=a[i][j];
                rmax[d]=max(i,rmax[d]);
                rmin[d]=min(i,rmin[d]);
                cmax[d]=max(j,cmax[d]);
                cmin[d]=min(j,cmin[d]);
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d=a[i][j];
                len=1ll*max(i-1,n-i);
                h=1ll*max(j-cmin[d],cmax[d]-j);
                ans[d]=max(ans[d],1ll*len*h);
                
                len=1ll*max(j-1,n-j);
                h=1ll*max(i-rmin[d],rmax[d]-i);
                ans[d]=max(ans[d],1ll*len*h);
            }
        }
        for(int i=0;i<=9;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}