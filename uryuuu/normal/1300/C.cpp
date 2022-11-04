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

ll a[maxn];
ll b[40];

int main()
{
    sync;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll d,cnt;
    for(int i=0;i<n;i++)
    {
        d=a[i];
        cnt=0;
        while(d)
        {
            if(d%2==1)
            {
                b[cnt]++;
            }
            d/=2;
            cnt++;
        }
    }
    ll s=0;
    for(int i=35;i>=0;i--)
    {
        s*=2;
        if(b[i]==1)
            s=s+1;
    }
    ll da=-1,p=0;
    for(int i=0;i<n;i++)
    {
        if(da<(a[i]&s))
        {
            da=a[i]&s;
            p=i;
        }
    }
    cout<<a[p]<<' ';
    for(int i=0;i<n;i++)
    {
        if(i==p)
            continue;
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}