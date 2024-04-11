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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=400005;
const ll Mod=1000000007;

int n,k,a[maxn];
vector<int>v;
int main()
{
    sync;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int i=0;i<25;i++)
    {
        v.clear();
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]&(1<<i))
                cnt++;
            v.push_back(a[j]&((1<<i)-1));
        }
        sort(v.begin(),v.end());
        int pre=(1ll*cnt*(n-cnt))&1;
        int now=0;
        for(int j=n-1;j>=0;j--)
        {
            while(now<n&&v[now]+v[j]<(1<<i))
                now++;
            if(now<j)
            {
                pre=pre+(j-now);
                pre&=1;
            }
        }
        if(pre)
            ans+=(1<<i);
    }
    cout<<ans<<endl;
    return 0;
}