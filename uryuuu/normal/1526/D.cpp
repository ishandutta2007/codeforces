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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=300005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[maxn],b[maxn];

void upd(int x,int val)
{
    while(x<maxn)
    {
        b[x]+=val;
        x+=lb(x);
    }
}

int qry(int x)
{
    int sum=0;
    while(x)
    {
        sum+=b[x];
        x-=lb(x);
    }
    return sum;
}

string s;
vector<int>g[5];
int c[5],d[maxn],ans[5];

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
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='A')
                a[i]=1;
            else if(s[i-1]=='N')
                a[i]=2;
            else if(s[i-1]=='T')
                a[i]=3;
            else
                a[i]=4;
        }
        for(int i=1;i<=4;i++)
            g[i].clear();
        for(int i=1;i<=n;i++)
        {
            g[a[i]].push_back(i);
        }
        for(int i=1;i<=4;i++)
            c[i]=i;
        ll mx=-1ll;
        ll sum,cnt;
        int id;
        do
        {
            for(int i=0;i<=n;i++)
                b[i]=0;
            cnt=0;
            sum=0ll;
            for(int i=1;i<=4;i++)
            {
                id=c[i];
                for(int v:g[id])
                {
                    cnt++;
                    upd(v,1);
                    sum+=1ll*(cnt-qry(v));
                }
            }
            if(sum>mx)
            {
                mx=sum;
                for(int i=1;i<=4;i++)
                    ans[i]=c[i];
            }
        }while(next_permutation(c+1,c+5));
        for(int i=1;i<=4;i++)
        {
            id=ans[i];
            for(int j=0;j<g[id].size();j++)
            {
                if(id==1)
                    cout<<'A';
                else if(id==2)
                    cout<<'N';
                else if(id==3)
                    cout<<'T';
                else
                    cout<<'O';
            }
        }
        cout<<endl;
    }
    return 0;
}