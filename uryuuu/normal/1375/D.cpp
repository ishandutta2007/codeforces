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
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=400010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[4000],b[4005];
int vis[4005];


int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        for(int i=0;i<=n+1000;i++)
        {
            vis[i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            vis[a[i]]++;
        }
        
        while(1)
        {
            int f=0;
            for(int i=2;i<=n;i++)
            {
                if(a[i]<a[i-1])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                break;
            }
            for(int i=0;i<=n;i++)
            {
                if(vis[i]==0)
                {
                    if(i==n)
                    {
                        for(int j=1;j<=n;j++)
                        {
                            if(a[j]!=j-1)
                            {
                                vis[a[j]]--;
                                vis[n]++;
                                b[cnt++]=j;
                                a[j]=n;
                                break;
                            }
                        }
                    }
                    else
                    {
                        vis[a[i+1]]--;
                        vis[i]++;
                        b[cnt++]=i+1;
                        a[i+1]=i;
                    }
                    break;
                }
            }
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<b[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}