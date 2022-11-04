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

#include<map>
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
string s,ans;
int v[30];

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
        mm(v);
        for(int i=0;i<n;i++)
        {
            a[i+1]=ch(s[i]);
        }
        sort(a+1,a+n+1);
        if(a[k]!=a[1])
        {
            cout<<char('a'+a[k]-1)<<endl;
            continue;
        }
        ans="";
        ans+=char('a'+a[k]-1);
        if(n>k)
        {
            if(a[k+1]!=a[n])
            {
                for(int i=k+1;i<=n;i++)
                {
                    ans+=char('a'+a[i]-1);
                }
            }
            else
            {
                int len=(n-k);
                int d=len/k;
                if(len%k)
                    d++;
                for(int i=1;i<=d;i++)
                {
                    ans+=char('a'+a[k+1]-1);
                }
            }
        }
        cout<<ans<<endl;
        
        
       
        
    }
    
    
    return 0;
}