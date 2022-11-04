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
#define mkp make_pair
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100010;
const ll Mod=1000000007;
//const ll Mod=998244353;


string s[1005];
int a[1005][1005];
int b[1005][1005];

int main()
{
    sync;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        for(int j=1;j<=m;j++)
        {
            if(s[i][j-1]=='#')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
            if(a[i-1][j-1]&&a[i-1][j]&&a[i-1][j+1]&&a[i][j-1]&&a[i][j+1]&&a[i+1][j-1]&&a[i+1][j]&&a[i+1][j+1])
            {
                b[i-1][j-1]=1;
                b[i-1][j]=1;
                b[i-1][j+1]=1;
                b[i][j-1]=1;
                b[i][j+1]=1;
                b[i+1][j-1]=1;
                b[i+1][j]=1;
                b[i+1][j+1]=1;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]!=a[i][j])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    
    return 0;
}