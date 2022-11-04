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
const int maxn=200010;
const ll Mod=1000000007;
//const ll Mod=998244353;

int a[500][500];

int main()
{
    sync;
    int t;
    int n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<=n+4;i++)
        {
            for(int j=0;j<=n+4;j++)
            {
                a[i][j]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(k==0)
                break;
            for(int j=0;j<n;j++)
            {
                a[j][(i+j)%n]=1;
                k--;
                if(k==0)
                    break;
            }
            if(k==0)
                break;
        }
        int mnr=999999,mxr=0,mnc=999999,mxc=0;
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=0;j<n;j++)
            {
                if(a[i][j])
                    s++;
            }
            mnr=min(mnr,s);
            mxr=max(mxr,s);
        }
        for(int i=0;i<n;i++)
        {
            int s=0;
            for(int j=0;j<n;j++)
            {
                if(a[j][i])
                    s++;
            }
            mnc=min(mnc,s);
            mxc=max(mxc,s);
        }
        
        ll g=(mxr-mnr)*(mxr-mnr)+(mxc-mnc)*(mxc-mnc)*(mxc-mnc);
        cout<<g<<endl;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j];
            cout<<endl;
        }
    }
    
    return 0;
}