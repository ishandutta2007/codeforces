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
#define ch(a) (int(a-'1')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;







int main()
{
    sync;
    int t;
    int n;
    int x,m;
    cin>>t;
    while(t--)
    {
        cin>>x>>n>>m;
        int f=0;
        int zx=x;
        while(n--)
        {
            x=x/2+10;
            zx=min(zx,x);
        }
        if(zx<=m*10)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    
    
    return 0;
}