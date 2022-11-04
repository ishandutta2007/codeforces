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
//#pragma comment(linker, "/STACK:36777216")  //hdu 
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
using namespace std;
typedef pair<int,ll> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

int nxt[maxn];
string s,t;
int n;
void getnxt()
{
    n=t.length();
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<n)
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
 
int ss[2],tt[2],gg[2];
string g;

int main()
{
    sync;
    cin>>s>>t;
    getnxt();
    int m=s.length();
    for(int i=0;i<m;i++)
    {
        ss[int(s[i]-'0')]++;
    }
    for(int i=0;i<n;i++)
    {
        tt[int(t[i]-'0')]++;
    }
    int st=nxt[n];
    g="";
    for(int i=st;i<n;i++)
    {
        gg[int(t[i]-'0')]++;
        g+=t[i];
    }
    if(ss[0]<tt[0]||ss[1]<tt[1])
    {
        cout<<s<<endl;
        return 0;
    }
    cout<<t;
    for(int i=0;i<=1;i++)
        ss[i]-=tt[i];
    while(ss[0]>=gg[0]&&ss[1]>=gg[1])
    {
        cout<<g;
        for(int i=0;i<=1;i++)
            ss[i]-=gg[i];
    }
    for(int i=1;i<=ss[0];i++)
        cout<<0;
    for(int i=1;i<=ss[1];i++)
        cout<<1;
    cout<<endl;
        
        
    return 0;
}