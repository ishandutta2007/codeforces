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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216") //hdu 
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
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


ll a[65];
string tmp[65];
int len[65];
string s;

int main()
{
    sync;
    a[1]=1;
    for(int i=2;i<=62;i++)
    {
        a[i]=2ll*a[i-1];
    }
    for(int i=1;i<=62;i++)
    {
        tmp[i]="";
        while(a[i])
        {
            tmp[i]+=char('0'+a[i]%10);
            a[i]/=10;
        }
        reverse(tmp[i].begin(),tmp[i].end());
        len[i]=tmp[i].length();
    }
    
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        s="";
        cin>>s;
        n=s.length();
        int ans=1e9;
        int sum;
        int L;
        int j;
        for(int i=1;i<=62;i++)
        {
            L=0;sum=0;
            for(j=0;j<len[i];j++)
            {
                while(L<n&&s[L]!=tmp[i][j])
                {
                    L++;
                    sum++;
                }
                if(L>=n)
                {
                    sum+=len[i]-j;
                    break;
                }
                L++;
            }
            sum+=n-L;
            ans=min(ans,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}