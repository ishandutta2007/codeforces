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
const ll Mod=998244353;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
ll a[5];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<3;i++)
            scanf("%lld",&a[i]);
        sort(a,a+3);
        cout<<(a[2]-(a[1]-a[0]))/2+a[1]<<endl;
    }
    return 0;
}