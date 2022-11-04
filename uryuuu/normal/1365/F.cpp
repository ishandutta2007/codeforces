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
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod = 998244353;


int a[600],b[600];
map<pii,int>mp;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,1,n)
            cin>>a[i];
        rep(i,1,n)
            cin>>b[i];
        mp.clear();
        if(n%2&&a[n/2+1]!=b[n/2+1])
        {
            cout<<"No"<<endl;
            continue;
        }
        int u,v;
        for(int i=1;i<=n/2;i++)
        {
            u=a[i];
            v=a[n-i+1];
            if(u>v)
                swap(u,v);
            mp[mkp(u,v)]++;
        }
        
        int f=0;
        
        for(int i=1;i<=n/2;i++)
        {
            u=b[i];
            v=b[n-i+1];
            if(u>v)
                swap(u,v);
            if(mp[mkp(u,v)]==0)
            {
                f=1;
                break;
            }
            mp[mkp(u,v)]--;
        }
        if(f)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}