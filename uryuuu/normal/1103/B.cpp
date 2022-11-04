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
const int maxn=200005;
//const ll Mod=1000000007;
const ll Mod=998244353;

string s;
int main()
{
    sync;
    while(1)
    {
        cin>>s;
        if(s[0]!='s')
            return 0;
        
        cout<<"? "<<0<<' '<<1<<endl;
        cin>>s;
        if(s[0]=='x')
        {
            cout<<"! "<<1<<endl;
            continue;
        }
        
        ll l=1ll,r=2ll,mid;
        while(1)
        {
            cout<<"? "<<l<<' '<<r<<endl;
            cin>>s;
            if(s[0]=='x')
                break;
            l=r;
            r=2ll*r;
        }
        while(l+1<r)
        {
            ll mid=1ll*(l+r)/2ll;
            cout<<"? "<<l<<' '<<mid<<endl;
            cin>>s;
            if(s[0]=='y')
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        cout<<"! "<<r<<endl;
    }
    
    return 0;
}