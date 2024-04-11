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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200005;
const ll Mod=1e9+7;

ll a[105];

int main()
{
    sync;
    ll sum;
    int t,n;
    cin>>t;
    while(t--)
    {
        ll sum=0;
        ll s=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                a[i]=1;
                sum++;
            }
            s+=a[i];
        }
        if(s==0)
            sum++;
        cout<<sum<<endl;
    }
    
    return 0;
}