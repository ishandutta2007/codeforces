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
//#include<unordered_map>
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
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


string s;
int sum1[1010],sum0[1010];
 
int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        sum1[0]=sum0[0]=0;
        for(int i=1;i<=n;i++)
        {
            sum1[i]=sum1[i-1];
            sum0[i]=sum0[i-1];
            if(s[i-1]=='1')
                sum1[i]++;
            else
                sum0[i]++;
        }
        int ans=1010;
        
        ans=min(sum1[n],sum0[n]);
        
        for(int i=1;i<n;i++)
        {
            ans=min(ans,sum0[i]+sum1[n]-sum1[i]);
            ans=min(ans,sum1[i]+sum0[n]-sum0[i]);
        }
        cout<<ans<<endl;
                
                
    }
    
    
    return 0;
}