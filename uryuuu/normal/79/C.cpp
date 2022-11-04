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


int nxt[maxn];
string s,t;
int lens,lent;
void getnxt()
{
    lent=t.length();
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<lent)
    {
        if(k==-1||t[j]==t[k])
        {
            j++;
            k++;
            nxt[j]=k;
        }
        else
            k=nxt[k];
    }
}
 
int vis[maxn],dp[maxn];

void kmp()
{
    getnxt();
    int i=0,j=0;
    while(i<lens)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
        }
        else
            j=nxt[j];
        if(j==lent)
        {
            vis[i-lent]=min(vis[i-lent],lent);
            j=nxt[j];
        }
    }
}

int main()
{
    sync;
    cin>>s;
    lens=s.length();
    for(int i=0;i<=lens;i++)
    {
        vis[i]=1e8;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        t="";
        cin>>t;
        kmp();
    }
    int mx=0,pos=0;
    int sum=0;
    for(int i=lens-1;i>=0;i--)
    {
        sum=min(sum+1,vis[i]-1);
        if(sum>mx)
        {
            mx=sum;
            pos=i;
        }
    }
    cout<<mx<<' '<<pos<<endl;
    
    return 0;
}