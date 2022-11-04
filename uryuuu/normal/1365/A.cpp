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
//#include<map>
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

int a[100][100];


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
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        int cnt=0;
        int ns=0;
        int ms=0;
        int f;
        for(int i=1;i<=n;i++)
        {
            f=0;
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==1)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ns++;
        }
        for(int i=1;i<=m;i++)
        {
            f=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j][i]==1)
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
                ms++;
        }
        int ans=min(ms,ns);
        if(ans%2)
            cout<<"Ashish"<<endl;
        else
            cout<<"Vivek"<<endl;
        
    }
    
    return 0;
}