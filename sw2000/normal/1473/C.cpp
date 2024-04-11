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
const ll mod = 1e9 + 7;
int n,k;
void solve()
{
    cin>>n>>k;
    int d=2*k-n-1;
    for(int i=1;i<=k;i++)
    {
        if(i<=d)cout<<i<<' ';
        else cout<<(k-i+d+1)<<' ';
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}