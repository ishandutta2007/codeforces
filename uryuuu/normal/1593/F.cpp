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
const int maxn=5000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

bool dp[42][42][42][42];
int a[50];

string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        s="";
        int n,ma,mb;
        cin>>n>>ma>>mb;
        cin>>s;
        for(int i=1;i<=n;i++)
        {
            a[i]=int(s[i-1]-'0');
        }
        mm(dp);
        int x;
        dp[0][0][0][0]=1;
        int xa,xb,numa,numb;
        for(int i=1;i<=n;i++)
        {
            x=a[i];
            for(xa=0;xa<ma;xa++)
            {
                for(numa=0;numa<i;numa++)
                {
                    for(xb=0;xb<mb;xb++)
                    {
                        if(dp[i-1][xa][numa][xb])
                        {
                            dp[i][(xa*10+x)%ma][numa+1][xb]=1;
                            dp[i][xa][numa][(xb*10+x)%mb]=1;
                        }
                    }
                }
            }
        }
        int mx=1e9;
        int ansa;
        for(int i=1;i<n;i++)
        {
            if(dp[n][0][i][0])
            {
//                cout<<i<<' '<<endl;
                if(abs(i-(n-i))<mx)
                {
                    mx=abs(i-(n-i));
                    ansa=i;
                }
            }
        }
        if(mx==1e9)
        {
            cout<<-1<<endl;
            continue;
        }
        s="";
        int nowa=0,nowb=0;
        int f=0;
        for(int i=n;i>=1;i--)
        {
            x=a[i];
            f=0;
            for(xa=0;xa<ma;xa++)
            {
                for(numa=0;numa<i;numa++)
                {
                    for(xb=0;xb<mb;xb++)
                    {
                        if(dp[i-1][xa][numa][xb])
                        {
                            if((xa*10+x)%ma==nowa&&numa+1==ansa&&xb==nowb)
                            {
                                nowa=xa;
                                ansa=numa;
                                nowb=xb;
                                s+='R';
                                f=1;
                                break;
                            }
                            if(xa==nowa&&numa==ansa&&(xb*10+x)%mb==nowb)
                            {
                                nowa=xa;
                                ansa=numa;
                                nowb=xb;
                                s+='B';
                                f=1;
                                break;
                            }
                        }
                    }
                    if(f)
                        break;
                }
                if(f)
                    break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}