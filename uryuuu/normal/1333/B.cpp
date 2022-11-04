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
#include<unordered_map>
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
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;


int a[maxn],b[maxn];
int sa[maxn],sb[maxn];


int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rep(i,1,n)
        cin>>a[i];
        rep(i,1,n)
        cin>>b[i];
        sa[0]=0;
        sb[0]=0;
        rep(i,1,n)
        {
            sa[i]=sa[i-1];
            sb[i]=sb[i-1];
            if(a[i]>0)
                sa[i]++;
            if(a[i]<0)
                sb[i]++;
        }
        int f=0;
        for(int i=n;i>=1;i--)
        {
           if(b[i]>a[i])
           {
               if(sa[i-1]==0)
               {
                   f=1;
                   break;
               }
           }
            else if(b[i]<a[i])
            {
                if(sb[i-1]==0)
                {
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    
    
    
    return 0;
}