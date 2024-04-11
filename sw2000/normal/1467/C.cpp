#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int n[3];
ll sum,arr[3][N];

ll solve(int a)
{
    int b=(a+1)%3,c=(b+1)%3;
    ll ret1=0,ret2=0,m1=inf,m2=inf;
    for(int i=0;i<n[b];i++)
        ret1+=arr[b][i],m1=min(m1,arr[b][i]);
    for(int i=0;i<n[c];i++)
        ret2+=arr[c][i],m2=min(m2,arr[c][i]);
    return min(ret1,min(ret2,m1+m2));
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    for(int i=0;i<3;i++)cin>>n[i];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<n[i];j++)
        {
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
    }
    ll ans=linf;
    for(int i=0;i<3;i++)
        ans=min(ans,solve(i));
    cout<<sum-ans*2;
    return 0;
}