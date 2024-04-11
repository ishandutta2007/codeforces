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

int a[maxn],b[maxn],p[maxn];;
string s;

int main()
{
    sync;
    int t;
    int n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cin>>s;
        int pre=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
            {
                a[i+1]=1;
                pre++;
            }
            else
                a[i+1]=0;
        }
        a[0]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                p[++cnt]=i;
            }
        }
        int m=0;
        for(int i=2;i<=cnt;i++)
        {
            if(p[i]-p[i-1]-1>0)
                b[++m]=p[i]-p[i-1]-1;
        }
        sort(b+1,b+m+1);
        int sum=0;
        int d=k;
        for(int i=1;i<=m;i++)
        {
            if(d>=b[i])
            {
                d-=b[i];
                sum++;
            }
            else
                break;
        }
        if(pre==0&&k==0)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=2*min(pre+k,n)-(m-sum+1);
        cout<<ans<<endl;
        
    }
    
    
    return 0;
}