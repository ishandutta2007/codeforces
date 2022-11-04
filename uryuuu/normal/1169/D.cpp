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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn];
int sa[maxn],sb[maxn];
string s;
int r[maxn];

int main()
{
    sync;
    cin>>s;
    int n=s.length();
    for(int i=1;i<=n;i++)
    {
        a[i]=int(s[i-1]-'0');
        sa[i]=sa[i-1];
        sb[i]=sb[i-1];
        if(a[i]==1)
            sa[i]++;
        else
            sb[i]++;
        r[i]=n+1;
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]==1)
        {
            for(int k=1;k<=n;k++)
            {
                if(i-2*k<=0)
                    break;
                if(sa[i-k]<=1||sa[i-2*k]<1)
                    break;
                if(a[i-k]==1&&a[i-2*k]==1)
                {
                    r[i-2*k]=min(r[i-2*k],i);
                    break;
                }
            }
        }
        else
        {
            for(int k=1;k<=n;k++)
            {
                if(i-2*k<=0)
                    break;
                if(sb[i-k]<=1||sb[i-2*k]<1)
                    break;
                if(a[i-k]==0&&a[i-2*k]==0)
                {
                    r[i-2*k]=min(r[i-2*k],i);
                    break;
                }
            }
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        r[i]=min(r[i],r[i+1]);
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=1ll*(n-r[i]+1);
    }
    cout<<sum<<endl;
    
    return 0;
}