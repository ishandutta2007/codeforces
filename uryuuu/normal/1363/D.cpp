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
#define flush fflush(stdout)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=1010;
const ll Mod=1000000007;
//const ll Mod = 998244353;

vector<int>g[maxn];
int pos[maxn];
string s;
int res[maxn];

int main()
{
//    sync;
    int n,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int sz,x;
        for(int i=1;i<=n;i++)
            pos[i]=0;
        for(int i=1;i<=k;i++)
            g[i].clear();
        for(int i=1;i<=k;i++)
        {
            cin>>sz;
            for(int j=0;j<sz;j++)
            {
                cin>>x;
                g[i].push_back(x);
                pos[x]=i;
            }
        }
        
        int mx;
        cout<<"? "<<n<<' ';
        for(int i=1;i<=n;i++)
            cout<<i<<' ';
        cout<<endl;
        flush;
        cin>>mx;
        int ans;
        int p;
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            cout<<"? "<<mid<<' ';
            for(int i=1;i<=mid;i++)
                cout<<i<<' ';
            cout<<endl;
            flush;
            cin>>ans;
            if(ans==mx)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        p=l;
        
        
        for(int i=1;i<=k;i++)
        {
            for(int v:g[i])
                pos[v]=i;
        }
        
        for(int i=1;i<=k;i++)
            res[i]=mx;
        
        int pp=pos[p];
        if(pp==0)
        {
            cout<<"! ";
            for(int i=1;i<=k;i++)
            {
               cout<<res[i]<<' ';
            }
            cout<<endl;
            flush;
            cin>>s;
            continue;
        }
        
        
        cout<<"? "<<n-g[pp].size()<<' ';
        for(int i=1;i<=n;i++)
        {
            if(pos[i]!=pp)
                cout<<i<<' ';
        }
        cout<<endl;
        cin>>res[pp];
        
        
        
        cout<<"! ";
        for(int i=1;i<=k;i++)
        {
            cout<<res[i]<<' ';
        }
        cout<<endl;
        flush;
        cin>>s;
    }
    
    return 0;
}