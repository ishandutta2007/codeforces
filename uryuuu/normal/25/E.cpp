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
const int maxn=1000005;
const ll Mod=1000000007;
//const ll Mod=998244353;


string s[3];
int q[5];
int nxt[maxn];

int kmp(string s1,string s2)
{
    int len2=s2.length();
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<len2)
    {
        if(k==-1||s2[j]==s2[k])
        {
            j++;
            k++;
            nxt[j]=k;
        }
        else
            k=nxt[k];
    }
    
    int len1=s1.length();
    int i=0;
    j=0;
    while(i<len1)
    {
        if(j==-1||s1[i]==s2[j])
        {
            i++;
            j++;
        }
        else
            j=nxt[j];
        if(j==len2)
        {
            return j;
        }
    }
    return j;
}


int solve(string s1,string s2,string s3)
{
    int ans;
    ans=kmp(s1,s2);
    string str=s1;
    for(int i=ans;i<s2.length();i++)
    {
        str+=s2[i];
    }
    ans=kmp(str,s3);
    for(int i=ans;i<s3.length();i++)
    {
        str+=s3[i];
    }
    return str.length();
}

int main()
{
    sync;
    cin>>s[0]>>s[1]>>s[2];
    for(int i=0;i<=4;i++)
        q[i]=i;
    int ans=1e9;
    do
    {
        ans=min(ans,solve(s[q[0]],s[q[1]],s[q[2]]));
    }while(next_permutation(q,q+3));
    cout<<ans<<endl;
    
    return 0;
}