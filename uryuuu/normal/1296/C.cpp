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
const ll Mod=998244353;

string s;
ll a[maxn];
ll ss[maxn];
map<ll,int>mp;
int main()
{
    sync;
    int t;
    ll n;
    cin>>t;
    while(t--)
    {
        mm(a);
        mm(ss);
        mp.clear();
        cin>>n;
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
                a[i]=1;
            else if(s[i]=='R')
                a[i]=-1;
            else if(s[i]=='U')
                a[i]=1000000;
            else
                a[i]=-1000000;
        }
        ss[1]=0;
        int zx=99999999;
        int l=0,r=0;
        mp[0]=1;
        for(int i=2;i<=n+1;i++)
        {
            ss[i]=ss[i-1]+a[i-2];
            if(mp[ss[i]])
            {
                if(zx>i-mp[ss[i]])
                {
                    zx=i-mp[ss[i]];
                    l=mp[ss[i]];
                    r=i-1;
                }
//                cout<<ss[i]<<' '<<l<<' '<<r<<endl;
            }
            mp[ss[i]]=i;
        }
        if(zx==99999999)
            cout<<-1<<endl;
        else
            cout<<l<<' '<<r<<endl;
    }
    return 0;
}