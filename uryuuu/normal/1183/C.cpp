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
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[105];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll n,k,a,b;
        cin>>k>>n>>a>>b;
        ll s=n*b;
        if(s>=k)
        {
            cout<<-1<<endl;
        }
        else
        {
            ll d=(k-s)/(a-b);
            if(s+d*(a-b)==k)
                d--;
            cout<<min(n,d)<<endl;
        }
    }
    return 0;
}