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
const int maxn=10001000;
const ll Mod=1000000007;
//const ll Mod=998244353;



int d[maxn];
int dp[200][20];
int a[100];

int main()
{
    sync;
    int x;
    for(int i=1;i<=maxn-3;i++)
    {
        x=i;
        while(x>0)
        {
            d[i]+=x%10;
            x/=10;
        }
    }
    d[0]=0;
    
    for(int i=0;i<=180;i++)
    {
        for(int j=0;j<=15;j++)
        {
            dp[i][j]=99999999;
        }
    }
    
    ll s;
    for(int i=0;i<=maxn-50;i++)
    {
        s=d[i]+d[i+1];
        for(int j=2;j<=9;j++)
        {
            s+=d[i+j];
            if(s<=150)
            {
                dp[s][j]=min(dp[s][j],i);
            }
            else
            {
                break;
            }
        }
    }
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k>=2)
        {
            if(dp[n][k]==99999999)
                cout<<-1<<endl;
            else
                cout<<dp[n][k]<<endl;
        }
        else if(k==0)
        {
            int cnt=0;
            while(n>0)
           {
               a[cnt++]=min(n,9);
               n-=9;
           }
           for(int i=cnt-1;i>=0;i--)
           {
               cout<<a[i];
           }
            cout<<endl;
        }
        else
        {
            if(n%2)
            {
                for(int i=8;i>=0;i--)
                {
                    if(i*2+1<=n)
                    {
                        x=i;
                        n=(n-(i*2+1))/2;
                        break;
                    }
                }
                int cnt=0;
                 while(n>0)
                {
                    a[cnt++]=min(n,9);
                    n-=9;
                }
                for(int i=cnt-1;i>=0;i--)
                {
                    cout<<a[i];
                }
                cout<<x<<endl;
            }
            else
            {
                if(n<10)
                {
                    cout<<-1<<endl;
                }
                else
                {
                    n-=10;
                    n/=2;
                    int cnt=0;
                    while(n>0)
                   {
                       if(cnt==0)
                       {
                           a[cnt++]=min(n,8);
                           n-=8;
                       }
                       else
                       {
                           a[cnt++]=min(n,9);
                           n-=9;
                       }
                   }
                   for(int i=cnt-1;i>=0;i--)
                   {
                       cout<<a[i];
                   }
                    cout<<9<<endl;
                }
            }
        }
    }
    
    
    
    
    
    return 0;
}