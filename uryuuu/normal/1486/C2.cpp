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
const int maxn=500005;
const ll Mod=1000000007;
//const ll Mod=998244353;


int main()
{
    sync;
    int n;
    cin>>n;
    int p,pos=0;
    int l=1,r=n,mid;
    cout<<"? "<<1<<' '<<n<<endl;
    cin>>p;
    if(p>1)
    {
        cout<<"? "<<1<<' '<<p<<endl;
        cin>>pos;
    }
    if(p>1&&pos==p)
    {
        l=1;r=p-1;
        while(l<r)
        {
            mid=(l+r+1)/2;
            cout<<"? "<<mid<<' '<<p<<endl;
            cin>>pos;
            if(p==pos)
                l=mid;
            else
                r=mid-1;
        }
        cout<<"! "<<l<<endl;
    }
    else
    {
        l=p+1;r=n;
        while(l<r)
        {
            mid=(l+r)/2;
            cout<<"? "<<p<<' '<<mid<<endl;
            cin>>pos;
            if(p==pos)
                r=mid;
            else
                l=mid+1;
        }
        cout<<"! "<<l<<endl;
    }
    
    
    return 0;
}