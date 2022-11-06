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

ll s[maxn];
ll a[maxn];
ll b[maxn];
ll c[maxn];
ll d[maxn];
map<int,int>mp;

int main()
{
    sync;
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        cin>>n;
        a[0]=b[0]=c[0]=d[0]=0;
        mp.clear();
        for(int i=1;i<=2*n;i++)
        {
            cin>>s[i];
            a[i]=a[i-1];
            b[i]=b[i-1];
            if(s[i]==1)
                a[i]++;
            else
                b[i]++;
        }
        for(int i=1;i<=n;i++)
        {
            c[i]=c[i-1];
            d[i]=d[i-1];
            if(s[2*n-i+1]==1)
                c[i]++;
            else
                d[i]++;
            mp[c[i]-d[i]]=i;
        }
        int zx=0;
        int ss;
        for(int i=0;i<=n;i++)
        {
            if(mp[b[i]-a[i]]||b[i]==a[i])
            {
                ss=mp[b[i]-a[i]]+i;
                zx=max(zx,ss);
            }
        }
        cout<<2*n-zx<<endl;
    }
    return 0;
}