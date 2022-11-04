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
//typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;


string a,b;
int sa[maxn],sb[maxn];
int La[maxn],Ra[maxn],Lb[maxn],Rb[maxn];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a="";
        b="";
        cin>>a>>b;
        int lena=1,lenb=1;
        sa[1]=int(a[0]-'0');
        sb[1]=int(b[0]-'0');
        La[1]=Ra[1]=Lb[1]=Rb[1]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                sa[++lena]=int(a[i]-'0');
                La[lena]=Ra[lena]=i+1;
            }
            else
            {
                Ra[lena]++;
            }
            
            if(b[i]!=b[i-1])
            {
                sb[++lenb]=int(b[i]-'0');
                Lb[lenb]=Rb[lenb]=i+1;
            }
            else
            {
                Rb[lenb]++;
            }
        }
        if(lena!=lenb)
        {
            cout<<-1<<'\n';
            continue;
        }
        int f=0;
        for(int i=1;i<=lena;i++)
        {
            if(sa[i]!=sb[i])
                f=1;
        }
        if(f)
        {
            cout<<-1<<'\n';
            continue;
        }
        
        ll ans=0;
        for(int i=2;i<=lena;i+=2)
        {
            ans+=1ll*abs(La[i]-Lb[i])+1ll*abs(Ra[i]-Rb[i]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}