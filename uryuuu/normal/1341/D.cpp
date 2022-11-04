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
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;

ll v[2005][2005];
int d[20];
int c[20];
int s[2005];
int b[2005];
int g[2005];
int n;
int dfs(int step,int k)
{
    if(k<0)
        return 0;
    if(step==n+1&&k==0)
        return 1;
if(step>n) 
return 0;
    if(v[step][k])
        return 0;
    v[step][k]=1;
    for(int i=9;i>=0;i--)
    {
        if((d[i]|s[step])==d[i])
        {
            g[step]=i;
            if(dfs(step+1,k-(c[i]-b[step])))
                return 1;
        }
    }
    return 0;
}


string ss;
int main()
{
    sync;
    int k;
    cin>>n>>k;
    d[0]=119;
    d[1]=18;
    d[2]=93;
    d[3]=91;
    d[4]=58;
    d[5]=107;
    d[6]=111;
    d[7]=82;
    d[8]=127;
    d[9]=123;
    c[0]=6;
    c[1]=2;
    c[2]=5;
    c[3]=5;
    c[4]=4;
    c[5]=5;
    c[6]=6;
    c[7]=3;
    c[8]=7;
    c[9]=6;
    for(int i=1;i<=n;i++)
    {
        cin>>ss;
        for(int j=0;j<=6;j++)
        {
            s[i]+=(int(ss[j]-'0')<<(6-j));
            if(ss[j]=='1')
                b[i]++;
        }
//        cout<<s[i]<<' '<<b[i]<<endl;
    }
    if(dfs(1,k)==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<g[i];
    }
    cout<<endl;
    
    
    return 0;
}