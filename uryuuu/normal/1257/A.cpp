#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const ll Mod=1e9+7;

int main()
{
    sync;
    int t,n,x,a,b;
    cin>>t;
    int d;
    int aa,bb;
    while(t--)
    {
        cin>>n>>x>>a>>b;
        aa=max(a,b);
        bb=min(a,b);
        d=aa-bb;
        cout<<min(d+x,n-1)<<endl;
    }
    
    return 0;
}