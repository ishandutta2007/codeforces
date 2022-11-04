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
#include<unordered_map>
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
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=1000;
const ll Mod=1000000007;
//const ll Mod=998244353;
using namespace std;

int a[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    sync;
    int k;
    cin>>k;
    if(k==0)
    {
        cout<<1<<' '<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    int d;
    for(int i=0;i<=20;i++)
    {
        if(k<(1<<i))
        {
            d=i;
            break;
        }
    }
    int x=1<<d;
    int y=(1<<(d+1))-1;
    cout<<3<<' '<<4<<endl;
    cout<<y<<' '<<k<<' '<<k<<' '<<0<<endl;
    cout<<x<<' '<<0<<' '<<k<<' '<<0<<endl;
    cout<<x<<' '<<x<<' '<<y<<' '<<k<<endl;
    return 0;
}