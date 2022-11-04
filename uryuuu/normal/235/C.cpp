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
const int maxn=4000005;
//const ll Mod=1000000007;
const ll Mod=998244353;

string s;
int n;

int len1,len[maxn],tot=1,root=1,last=1,ch[maxn][27],fa[maxn];
int pos[maxn],v[maxn],key[maxn];//maxn 
void extend(int x)
{
    int now=++tot,pre=last;
    last=now;
    key[last]++;// 
    len[now]=len[pre]+1;
    while(pre&&!ch[pre][x])
    {
        ch[pre][x]=now;
        pre=fa[pre];
    }
    if(!pre)
        fa[now]=root;
    else
    {
        int q=ch[pre][x];
        if(len[q]==len[pre]+1)
            fa[now]=q;
        else
        {
            int nows=++tot;
            memcpy(ch[nows],ch[q],sizeof(ch[q]));
            len[nows]=len[pre]+1;
            fa[nows]=fa[q];
            fa[q]=fa[now]=nows;
            for(;pre&&ch[pre][x]==q;pre=fa[pre])
            {
                ch[pre][x]=nows;
            }
        }
    }
}

int vis[maxn];

void sort()  //
{
    for(int i=1;i<=tot;i++)
        v[len[i]]++;
    for(int i=1;i<=tot;i++)
        v[i]+=v[i-1];
    for(int i=1;i<=tot;i++)
        pos[v[len[i]]--]=i;
    for(int i=tot;i>=1;i--)
    {
        key[fa[pos[i]]]+=key[pos[i]];
    }
}



int main()
{
    sync;
    cin>>s;
    n=s.length();
    int id;
    for(int i=0;i<n;i++)
    {
        id=int(s[i]-'a');
        extend(id);
    }
    sort();
    int q;
    cin>>q;
    memset(vis,inf,sizeof(vis));
    while(q--)
    {
        s="";
        cin>>s;
        len1=s.length();
        for(int i=0;i<len1-1;i++)
        {
            s+=s[i];
        }
        ll ans=0;
        int now=1,Len=0;
        for(int i=0;i<len1+len1-1;i++)
        {
            id=int(s[i]-'a');
            while(now&&ch[now][id]==0)
            {
                now=fa[now];
                Len=len[now];
            }
            if(now==0)
            {
                now=1;
                Len=0;
            }
            else
            {
                now=ch[now][id];
                Len+=1;
            }
            while(now&&len[fa[now]]>=len1)
            {
                now=fa[now];
                Len=len[now];
            }
            if(Len>=len1&&vis[now]!=q)
            {
                ans+=key[now];
                vis[now]=q;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}