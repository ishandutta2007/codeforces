#include<iostream>
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
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
const ll Mod=1e9+7;
using namespace std;
ll a[25];
int main()
{
    sync
    int n,l,r;
    cin>>n>>l>>r;
    a[0]=1;
    for(int i=1;i<r;i++)
    {
        a[i]=a[i-1]*2;
    }
    ll minn=0,maxx=0;
    for(int i=0;i<l;i++)
        minn+=a[i];
    for(int i=0;i<min(n,r);i++)
        maxx+=a[i];
//    cout<<maxx<<endl;
    if(n>l)
        minn+=n-l;
    if(n>r)
        maxx+=(a[r-1]*(n-r));
    cout<<minn<<' '<<maxx<<endl;
    return 0;
}