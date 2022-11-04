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
const int maxn=500005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        s="";
        cin>>s;
        int n=s.length();
        int f=0,f0=0,f5=0,m=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0')
                f++;
            else m++;
        }
        int ans=n;
        if(f)
            ans=m;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='0')
            {
                if(f0)
                    ans=min(ans,n-i-2);
                f0=1;
            }
            if(s[i]=='2')
            {
                if(f5)
                    ans=min(ans,n-i-2);
            }
            if(s[i]=='5')
            {
                if(f0)
                    ans=min(ans,n-i-2);
                f5=1;
            }
            if(s[i]=='7')
            {
                if(f5)
                    ans=min(ans,n-i-2);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}