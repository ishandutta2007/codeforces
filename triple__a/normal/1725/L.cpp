#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
ll s[MAXN];
vector<ll> dis;
int bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    if(n==1) {if(a[1]>=0) puts("0"); else puts("-1"); return 0;}
    for(int i=1;i<=n;i++)
    {
        if(s[i]<0)
        {
            puts("-1");
            return 0;
        }
    }
    ll maxi=-INF;
    for(int i=1;i<=n-1;i++) maxi=max(maxi,s[i]);
    if(s[n]<maxi) {puts("-1"); return 0;}
    for(int i=1;i<=n-1;i++) dis.push_back(s[i]);
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    ll ans=0;
    for(int i=1;i<=n-1;i++)
    {
        int id=lower_bound(dis.begin(),dis.end(),s[i])-dis.begin()+1;
        ans+=(i-1-sum(id));
        add(id,1);
    }
    printf("%lld\n",ans);
    return 0;
}