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
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=1000005;
//const ll Mod=1000000007;
//const ll Mod=998244353;

string s;
int pre[maxn],suc[maxn];

int main()
{
    sync;
    cin>>s;
    int n=s.length();
    int j,k;
    
    j=0;k=-1;
    pre[0]=-1;
    while(j<n)
    {
        if(k==-1||s[j]==s[k])
        {
            j++;
            k++;
            pre[j]=k;
        }
        else
            k=pre[k];
    }
    
    reverse(s.begin(),s.end());
    
    j=0;k=-1;
    suc[0]=-1;
    while(j<n)
    {
        if(k==-1||s[j]==s[k])
        {
            j++;
            k++;
            suc[j]=k;
        }
        else
            k=suc[k];
    }
    
    reverse(s.begin(),s.end());
    
    int pos=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]==suc[n-i+pre[i]])
        {
            if(mx<pre[i])
            {
                mx=pre[i];
                pos=i;
            }
        }
    }
    if(pos==0)
        cout<<"Just a legend"<<endl;
    else
    {
        int L=pos-pre[pos];
        for(int i=1;i<=pre[pos];i++)
        {
            cout<<s[L];
            L++;
        }
        cout<<endl;
    }
    
    return 0;
}