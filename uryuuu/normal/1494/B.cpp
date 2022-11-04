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
#define ch(a) (int(a-'A')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;

string s;
int a[4];

int main()
{
    sync;
    int t;
    int n;
    int u,r,d,l;
    cin>>t;
    int sum,f;
    int mx,mn;
    while(t--)
    {
        cin>>n>>u>>r>>d>>l;
        f=0;
        
        mx=max(r,l);
        mn=min(r,l);
        if(u==n)
        {
            mx--;
            mn--;
        }
        else if(u==n-1)
        {
            mx--;
            if(mx<mn)
                swap(mx,mn);
        }
        if(d==n)
        {
            mx--;
            mn--;
        }
        else if(d==n-1)
        {
            mx--;
            if(mx<mn)
                swap(mx,mn);
        }
        if(mx<0||mn<0)
            f=1;
        
        mx=max(u,d);
        mn=min(u,d);
        if(r==n)
        {
            mx--;
            mn--;
        }
        else if(r==n-1)
        {
            mx--;
            if(mx<mn)
                swap(mx,mn);
        }
        if(l==n)
        {
            mx--;
            mn--;
        }
        else if(l==n-1)
        {
            mx--;
            if(mx<mn)
                swap(mx,mn);
        }
        if(mx<0||mn<0)
            f=1;
        
        if(f==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }
    
    return 0;
}