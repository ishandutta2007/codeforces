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
const double pi=acos(-1);
const int maxn=200010;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;




int a[maxn];
int v[maxn];
int b[10];

int main()
{
    sync;
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int r=0;
        rep(i,1,n)
        {
            cin>>a[i];
            v[i]=0;
            r=max(a[i],r);
        }
        rep(i,1,n)
        {
            v[a[i]]++;
        }
        if(r>=n)
        {
            cout<<0<<endl;
//            cout<<r<<endl;
            continue;
        }
        int l=r+1;
        for(int i=1;i<=r;i++)
        {
            if(v[i]==1)
            {
                l=i;
                break;
            }
        }
        int f=0;
        for(int i=1;i<l;i++)
        {
            if(v[i]!=2)
            {
                f=1;
                break;
            }
        }
//        cout<<l<<' '<<r<<endl;
        for(int i=l;i<=r;i++)
        {
            if(v[i]!=1)
            {
//                cout<<i<<endl;
                f=1;
                break;
            }
        }
        if(f==1||l==1)
        {
            cout<<0<<endl;
            continue;
        }
        int cnt=0;
        for(int i=1;i<=r;i++)
        {
            v[i]=0;
        }
        int s=0;
        for(int i=1;i<=n;i++)
        {
            v[a[i]]++;
            s++;
            if(v[a[i]]>=2)
                break;
            if(s==r)
            {
                b[cnt++]=i;
                break;
            }
        }
        
        for(int i=1;i<=r;i++)
        {
            v[i]=0;
        }
        s=0;
        for(int i=n;i>=1;i--)
        {
            v[a[i]]++;
            s++;
            if(v[a[i]]>=2)
                break;
            if(s==r)
            {
                b[cnt++]=i-1;
                break;
            }
        }
        
        if(cnt==2&&b[0]==b[1])
        {
            cnt--;
        }
        cout<<cnt<<endl;
        for(int i=0;i<cnt;i++)
        {
            cout<<b[i]<<' '<<n-b[i]<<endl;
        }
        
        
    }
    
    return 0;
}