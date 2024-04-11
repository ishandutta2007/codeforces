#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e6+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

ll arr[maxn],brr[maxn],cnt;
ll f()
{
    ll ma=0;
    for(int i=1;i<cnt;i++)brr[i]+=brr[i-1];
    ll mi=0;
    for(int i=0;i<cnt;i++)
    {
        mi=min(mi,brr[i]);
        ma=max(ma,brr[i]-mi);
    }
    return ma;
}
ll solve()
{
    ll ret=0;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i%2==0)ret+=arr[i];
    }
    cnt=0;
    for(int i=1;i<n;i+=2)
    {
        brr[cnt++]=arr[i]-arr[i-1];
    }
    ll ma=f();
    cnt=0;
    for(int i=1;i<n-1;i+=2)
    {
        brr[cnt++]=arr[i]-arr[i+1];
    }
    ma=max(ma,f());

    return ret+ma;
}

int main()
{
//    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        cout<<solve()<<endl;
    }
}