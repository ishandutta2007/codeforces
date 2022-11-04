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
const int maxn=300005;
const ll Mod=1e9+7;

ll a[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    ll q=0,w=0;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=1ll*(a[i]/2ll);
        a[i]%=2;
        if(a[i])
        {
            if(i%2==0)
                q++;
            else
                w++;
        }
    }
    
    cout<<sum+1ll*min(q,w)<<endl;
    return 0;
}