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
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n;
ll arr[N],add[N];
ll solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)add[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ll ret=0;
    for(int i=1;i<=n;i++)
    {
        add[i]+=add[i-1];

        if(arr[i]+i+1<=n)add[arr[i]+i+1]++;
        add[i+2]--;
        arr[i]+=add[i];
        if(arr[i]<=0)
        {
            add[i+1]-=-arr[i]+1;
            add[i+2]+=-arr[i]+1;
        }
        ret+=max(arr[i],1ll)-1;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)cout<<solve()<<endl;
    return 0;
}