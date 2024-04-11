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
#define mkp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=300010;
const ll Mod=1000000007;
//const ll Mod=998244353;
  

int main()
{
    sync;
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n<31)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int x=n-30;
        if(x==6)
        {
            cout<<"YES"<<endl;
            cout<<6<<' '<<10<<' '<<15<<' '<<5<<endl;
        }
        else if(x==10)
        {
            cout<<"YES"<<endl;
            cout<<6<<' '<<10<<' '<<15<<' '<<9<<endl;
        }
        else if(x==14)
        {
            cout<<"YES"<<endl;
            cout<<6<<' '<<10<<' '<<15<<' '<<13<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<6<<' '<<10<<' '<<14<<' '<<x<<endl;
        }
    }
    
    return 0;
}