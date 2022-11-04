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
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=2000005;
//const ll Mod=1000000007;
const ll Mod=998244353;
using namespace std;



int main()
{
//    sync;
    int n,m;
//    cin>>n>>m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n/2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d %d\n",i,j);
            printf("%d %d\n",n+1-i,m+1-j);
//            cout<<i<<' '<<j<<endl;
//            cout<<n+1-i<<' '<<m+1-j<<endl;
        }
    }
//    cout<<"fuck"<<endl;
    if(n%2)
    {
        int w=1;
        int x=n/2+1;
        int y=1;
        cout<<x<<' '<<y<<endl;
        for(int i=m-1;i>=1;i--)
        {
            y=y+i*w;
            w*=-1;
            printf("%d %d\n",x,y);
        }
    }
    
    return 0;
}