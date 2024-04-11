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

int a[1005][1005];
char c;
vector<int>in[2],to[2];
int ans[maxn];

int main()
{
    sync;
    int t;
    int n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>c;
                if(c=='a')
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }
        }
        
        if(m%2)
        {
            cout<<"YES"<<endl;
            m++;
            for(int i=1;i<m;i+=2)
            {
                cout<<1<<' '<<2<<' ';
            }
            cout<<endl;
            continue;
        }
        
        int fl=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i][j]==a[j][i])
                {
//                    cout<<"FUCK"<<' '<<i<<' '<<j<<endl;
                    cout<<"YES"<<endl;
                    for(int k=1;k<=m;k+=2)
                        cout<<i<<' '<<j<<' ';
                    cout<<i<<endl;
                    fl=1;
                    break;
                }
            }
            if(fl)
                break;
        }
        if(fl)
            continue;
        
        
        
        int u,v,h;
        int f=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=1;j++)
            {
                in[j].clear();
                to[j].clear();
            }
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                in[a[j][i]].push_back(j);
                to[a[i][j]].push_back(j);
            }
            if(in[0].size()&&to[0].size())
            {
                u=in[0][0];
                h=to[0][0];
                v=i;
                f=1;
                break;
            }
            if(in[1].size()&&to[1].size())
            {
                u=in[1][0];
                h=to[1][0];
                v=i;
                f=1;
                break;
            }
        }
        if(f==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        
        int mid=m/2+1;
        m++;
        
        for(int i=mid%2;i<=m;i+=2)
        {
            ans[i]=v;
        }
        for(int i=(mid+1)%2;i<=m;i+=2)
        {
            ans[i]=u;
        }
        for(int i=mid+1;i<=m;i+=2)
        {
            ans[i]=h;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
        
    }
    return 0;
}