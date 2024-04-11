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
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=100005;
const ll Mod=1000000007;


int a[2005];
map<int,int>mp,vis;

int main()
{
    sync;
    int n;
    cin>>n;
    int f=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]]>1)
        {
            f=1;
            vis[a[i]]=1;
        }
    }
    int cnt=0;
    for(auto ff:vis)
    {
        cnt++;
    }
    if(f==0)
    {
        cout<<0<<endl;
        return 0;
    }
    int zx=3000;
    int l=1,r=0;
    while(r<=n)
    {
        r++;
        mp[a[r]]--;
        {
            if(mp[a[r]]==1)
                cnt--;
        }
        while(l<=r)
        {
            if(mp[a[l]]<1)
            {
                mp[a[l]]++;
                l++;
            }
            else
                break;
        }
        if(cnt==0)
            zx=min(zx,r-l+1);
    }
    cout<<zx<<endl;
    return 0;
}