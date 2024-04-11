#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
//#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
#define lb(x) (x&(-x));
#define add(a,b) ((a+=(b))%=Mod)
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;


ll m[1005];
ll v[1005];
ll a[1005];

int main()
{
    sync;
    int n;
    cin>>n;
    ll da=0;
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
    }
    for(int i=1;i<=n;i++)
    {
        ll sum=0;
        a[i]=m[i];
        sum+=a[i];
        for(int j=i+1;j<=n;j++)
        {
            a[j]=min(m[j],a[j-1]);
            sum+=a[j];
        }
        for(int j=i-1;j>=1;j--)
        {
            a[j]=min(m[j],a[j+1]);
            sum+=a[j];
        }
        if(sum>da)
        {
            for(int j=1;j<=n;j++)
            {
//                cout<<a[j]<<' ';
                v[j]=a[j];
            }
//            cout<<endl;
            da=sum;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<v[i]<<' ';
    cout<<endl;
    return 0;
}