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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;


ll a[maxn];
ll b[maxn];
ll dl=(1ll<<32)-1;
ll p=2e13;
bool v[maxn];
string ss[maxn];

int s=0;
int f=0;
ll sum=0;
int l;

void dfs(int r,ll sm)
{
    s++;
    if(ss[r][0]=='e')
        return;
    while(s<=l)
    {
        if(ss[s][0]=='e')
            return;
        if(ss[s][0]=='a')
        {
            if(sm>dl||sum+sm>dl)
            {
                cout<<"OVERFLOW!!!"<<endl;
                exit(0);
            }
            sum+=sm;
        }
        else
        {
            ll x=b[s];
            if(1ll*sm*x>dl)
            {
                dfs(s+1,p);
            }
            else
                dfs(s+1,1ll*sm*x);
        }
        s++;
    }
    return;
}

int main()
{
    sync;
    cin>>l;
    for(int i=1;i<=l;i++)
    {
        cin>>ss[i];
        if(ss[i][0]=='f')
            cin>>b[i];
    }
    s=0;
    for(int i=1;i<=l;i++)
    {
        if(v[i]==0)
        {
            dfs(i,1);
        }
        i=s;
    }
    cout<<sum<<endl;
    return 0;
}