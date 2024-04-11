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

int a[maxn];
string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        int n=s.length();
        int L=0,lst=2;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='?')
            {
                lst=(i+int(s[i]-'0'))%2;
                break;
            }
        }
        ll ans=0;
        int d,len;
        int pos=0;
        int pre=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                continue;
            }
            d=(i+int(s[i]-'0'))%2;
            if(d!=lst)
            {
//                cout<<i<<endl;
                len=i-L;
                ans+=1ll*(len+1)*len/2ll+1ll*(pre-1ll)*len;
//                cout<<pre<<' '<<len<<' '<<1ll*pre*(len+1)*len/2ll<<endl;
                lst=d;
                pre=i-pos;
                L=i;
            }
            pos=i;
        }
        len=n-L;
//        cout<<pre<<' '<<len<<' '<<1ll*pre*(len+1)*len/2ll<<endl;
        ans+=1ll*(len+1)*len/2ll+1ll*(pre-1ll)*len;
        cout<<ans<<endl;
    }
    return 0;
}