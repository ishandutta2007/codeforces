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
const int maxn=201000;
//const ll Mod=1000000007;
//const ll Mod=6597069766657;
using namespace std;
//const ll Mod=2e17;


int p[maxn],c[maxn],v[maxn];
vector<int>g[maxn];
int main()
{
    sync;
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,1,n)
        cin>>p[i];
        rep(i,1,n)
        cin>>c[i];
        mm(v);
        for(int i=1;i<=n;i++)
            g[i].clear();
        int ans=9999999;
        rep(i,1,n)
        {
            if(v[i])
                continue;
            int x=p[i];
            while(v[x]==0)
            {
                g[i].push_back(x);
                v[x]=1;
                x=p[x];
            }
            int siz=g[i].size();
            for(int j=1;j<=siz;j++)
            {
                int flag=0;
                if(siz%j==0)
                {
                    for(int st=0;st<j;st++)
                    {
                        int f=0;
                        for(int k=st;k<siz;k+=j)
                        {
                            if(c[g[i][k]]!=c[g[i][st]])
                            {
                                f=1;
                                break;
                            }
                        }
                        if(f==0)
                        {
                            ans=min(ans,j);
                            flag=1;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}