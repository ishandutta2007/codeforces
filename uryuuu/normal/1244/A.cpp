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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=500005;
const ll Mod=1000000007;

int main()
{
    sync
    int t;
    int a,b,c,d,k;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d>>k;
        int aa;
        if(a%c==0)
            aa=a/c;
        else
            aa=a/c+1;
        int bb=k-aa;
        if(bb*d>=b)
            cout<<aa<<' '<<bb<<endl;
        else
            cout<<-1<<endl;
    }
    
    return 0;
}