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
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
using namespace std;
typedef pair<int,ll> pii;
//const double pi=acos(-1);
const int maxn=500010;  // 
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;
int a[205][205];

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=0;j<n;j++)
            {
                if(s[j]=='1')
                    a[i][j+1]=1;
                else
                    a[i][j+1]=0;
            }
        }
        if(a[n][n-1]==a[n-1][n])
        {
            if(a[1][2]==a[n][n-1])
                sum++;
            if(a[2][1]==a[n][n-1])
                sum++;
            cout<<sum<<endl;
            if(a[1][2]==a[n][n-1])
                cout<<1<<' '<<2<<endl;
            if(a[2][1]==a[n][n-1])
                cout<<2<<' '<<1<<endl;
            continue;
        }
        if(a[1][2]==a[2][1])
        {
            if(a[1][2]==a[n][n-1])
                sum++;
            if(a[2][1]==a[n-1][n])
                sum++;
            cout<<sum<<endl;
            if(a[1][2]==a[n][n-1])
                cout<<n<<' '<<n-1<<endl;
            if(a[2][1]==a[n-1][n])
                cout<<n-1<<' '<<n<<endl;
            continue;
        }
        if(a[1][2]==1)
            sum++;
        if(a[2][1]==1)
            sum++;
        if(a[n][n-1]==0)
            sum++;
        if(a[n-1][n]==0)
            sum++;
        cout<<sum<<endl;
        
        
        if(a[1][2]==1)
            cout<<1<<' '<<2<<endl;
        if(a[2][1]==1)
            cout<<2<<' '<<1<<endl;
        if(a[n][n-1]==0)
            cout<<n<<' '<<n-1<<endl;
        if(a[n-1][n]==0)
            cout<<n-1<<' '<<n<<endl;
    }
    
    
    return 0;
}