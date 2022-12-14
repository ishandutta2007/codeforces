#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
const int maxn=2e5+10;
const double PI=acos(0)*2;
int a[maxn],w[maxn];
ll solve()
{
    ll ret=0;
    int n,k;scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        ret+=a[i];
    }
    for(int i=0;i<k;i++)scanf("%d",w+i);
    sort(a,a+n);
    sort(w,w+k,greater<int>());
    for(int i=0,st=0;i<k;i++)if(w[i]>2)
    {
        for(int j=0;j<w[i]-2;j++)
            ret-=a[st+j+1];
        st+=w[i]-1;
    }
    for(int i=0,st=n-1;i<k;i++)if(w[i]==1)
    {
        ret+=a[st--];
    }
    return ret;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        printf("%lld\n",solve());
    }
}