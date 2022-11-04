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
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;
const ll Mod=1000000007;




int main()
{
    sync;
    int t;
    ll a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        ll s=-1;
        b+=1;
        while(b)
        {
            b/=10;
            s++;
        }
        cout<<1ll*a*s<<endl;
    }
    return 0;
}