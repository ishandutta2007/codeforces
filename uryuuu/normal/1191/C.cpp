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
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    ll n,m,k,a;
    cin>>n>>m>>k;
    ll sum=0;
    ll q,w=-1;
    ll s=0;
    ll ss=0;
    for(ll i=0;i<m;i++)
    {
        scanf("%lld",&a);
        a=a-1-s;
        ll q=a/k;
        if(q!=w&&w!=-1)
        {
            sum++;
            w=(a-ss)/k;
            s+=ss;
            ss=1;
        }
        else
        {
            w=q;
            ss++;
        }
    }
    sum++;
    cout<<sum<<endl;
    return 0;
}