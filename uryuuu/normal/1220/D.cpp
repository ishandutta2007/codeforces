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
#define lb(x) (x&(-x));
using namespace std;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int maxn=200005;
const ll Mod=1000000007;

ll a[maxn],c[maxn],v[maxn];

int main()
{
    sync;
    int n;
    cin>>n;
    int ans,da=-1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        c[i]=__builtin_ctzll(a[i]);
        v[c[i]]++;
        if(v[c[i]]>da)
        {
            da=v[c[i]];
            ans=c[i];
        }
    }
    cout<<n-da<<endl;
    for(int i=0;i<n;i++)
    {
        if(c[i]!=ans)
            cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
    
}