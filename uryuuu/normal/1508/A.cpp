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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;
 
 
string s[4];
int n;
int g[2][maxn];
int num[2];
int f=0;

void solve(string s,string t,int c,int len)
{
    string a[2];
    a[0]=s;
    a[1]=t;
    mm(num);
    g[0][0]=0;
    g[1][0]=0;
    
    for(int k=0;k<=1;k++)
    {
        for(int i=1;i<=2*n+2;i++)
        {
            g[k][i]=2*n+1;
        }
    }
    
    for(int k=0;k<=1;k++)
    {
        for(int i=0;i<2*n;i++)
        {
            if(int(a[k][i]-'0')==c)
            {
                g[k][++num[k]]=i+1;
            }
        }
    }
    
    int mx,j;
    for(int i=1;i<=len+1;i++)
    {
        mx=max(g[0][i]-g[0][i-1],g[1][i]-g[1][i-1]);
        for(j=1;j<=mx-1;j++)
        {
            cout<<1-c;
        }
        if(i!=len+1)
            cout<<c;
    }
    cout<<endl;
}

int cnt[4][2];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mm(cnt);
        for(int i=1;i<=3;i++)
        {
            s[i]="";
            cin>>s[i];
            for(int j=0;j<2*n;j++)
            {
                cnt[i][int(s[i][j]-'0')]++;
            }
        }
        
        
        f=0;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(i==j)
                    continue;
                if(cnt[i][0]>=n&&cnt[j][0]>=n)
                {
                    solve(s[i],s[j],0,max(cnt[i][0],cnt[j][0]));
                    f=1;
                    break;
                }
                if(cnt[i][1]>=n&&cnt[j][1]>=n)
                {
                    solve(s[i],s[j],1,max(cnt[i][1],cnt[j][1]));
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        
    }
    
    return 0;
}