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
int arr[N],n,u,v;
ll solve()
{
    cin>>n>>u>>v;
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    for(int i=2;i<=n;i++)
        if(abs(arr[i]-arr[i-1])>1)return 0;
    if(s.size()==1)
    {
        return v+min(u,v);
    }
    else return min(u,v);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)cout<<solve()<<endl;
    return 0;
}