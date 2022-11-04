//#include <bits/stdc++.h>
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
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300005;
ll n,ans,a[maxn];
map<ll,ll>H;
int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int d=1;
    while(d<=n)
    {
        H[d]=1;
        d=d*2;
    }
    ans=0;
    multiset<ll>s;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==-1)
            break;
        s.insert(a[i]);
        if(H[i])
        {
            ans+=*s.begin();
            s.erase(s.begin());
        }
    }
    cout<<ans<<endl;
    return 0;
}