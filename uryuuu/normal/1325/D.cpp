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
const int maxn=100005;
//const ll Mod=1000000007;
using namespace std;
 
int main()
{
    sync;
    ll u,v;
    cin>>u>>v;
    if(v==u)
    {
        if(v==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
            cout<<u<<endl;
        }
        return 0;
    }
    if(u>v||(v-u)%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    ll x=(v-u)/2;
    if((x&u)==0)
    {
        cout<<2<<endl;
        cout<<x<<' '<<(x|u)<<endl;
    }
    else
    {
        cout<<3<<endl;
        cout<<x<<' '<<x<<' '<<u<<endl;
    }
    return 0;
}