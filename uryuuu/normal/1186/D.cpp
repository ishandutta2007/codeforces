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
#define ch(a) (int(a-'0'))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100010;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;


double a[maxn];
int b[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    ll s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int zs=0,fs=0;
    for(int i=1;i<=n;i++)
    {
        int x=int(a[i]);
        s+=x;
        if(a[i]==double(int(x))*1.00000)
        {
            b[i]=x;
            continue;
        }
    }
    int R=0;
    int L=0;
    if(s<=0)
    {
        R=-s;
    }
    else
    {
        L=s;
    }
    
    for(int i=1;i<=n;i++)
        {
            int x=int(a[i]);
            if(a[i]==double(int(x))*1.00000)
            {
                continue;
            }
            b[i]=x;
            if(a[i]>=0&&zs<R)
            {
                b[i]=x+1;
                zs++;
            }
            if(a[i]<0&&fs<L)
            {
                b[i]=x-1;
                fs++;
            }
        }
    
    
    for(int i=1;i<=n;i++)
    {
        cout<<b[i]<<endl;
    }
    
    return 0;
}