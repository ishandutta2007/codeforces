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
#define ch(a) (int(a-'A')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=3010;
//const ll Mod=1000000007;
const ll Mod=998244353;

int a[505][505];
int b[505][505];

int main()
{
    sync
    int n,m;
    cin>>n>>m;
    int q1=0,q2=0,w1=0,w2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    int f=0;
    for(int i=1;i<=n;i++)
    {
        q1=0;
        q2=0;
        for(int j=1;j<=m;j++)
        {
            cin>>b[i][j];
            if(b[i][j])
                q2++;
            if(a[i][j])
                q1++;
        }
        if((q1-q2)%2!=0)
        {
            f=1;
            break;
        }
    }
    
    for(int i=1;i<=m;i++)
    {
        q1=0;
        q2=0;
        for(int j=1;j<=n;j++)
        {
            if(b[j][i])
                q2++;
            if(a[j][i])
                q1++;
        }
        if((q1-q2)%2!=0)
        {
            f=1;
            break;
        }
    }
    
    
    if(f==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}