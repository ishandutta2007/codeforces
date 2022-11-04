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
#include<bitset>
//#include<unordered_map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
//#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef pair<int,int> pii;
//const double pi=acos(-1);
const int maxn=400010;
//const ll Mod=1000000007;
const ll Mod=998244353;




ll a[maxn];
ll b[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
ll c[maxn];
ll d[maxn];

int main()
{
    sync;
    int t;
    int n;
    int k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        rep(i,1,n)
        cin>>a[i];
        rep(i,1,k*2)
        {
            b[i]=0;
        }
        int m=n/2;
        for(int i=1;i<=m;i++)
        {
            b[a[i]+a[n-i+1]]++;
        }
        for(int i=1;i<=m;i++)
        {
            c[i]=min(a[i],a[n-i+1]);
        }
        sort(c+1,c+m+1);
        for(int i=1;i<=m;i++)
        {
            d[i]=max(a[i],a[n-i+1]);
        }
        sort(d+1,d+m+1);
        int p;
        for(int i=k+1;i<=k*2;i++)
        {
            p=lower_bound(d+1,d+m+1,i-k)-d-1;
            b[i]-=p;
        }
        for(int i=1;i<=k;i++)
        {
            p=lower_bound(c+1,c+m+1,i)-c;
            b[i]-=(m-p+1);
        }
        sort(b+1,b+2*k+1,cmp);
        cout<<m-b[1]<<endl;
    }
    
    return 0;
}