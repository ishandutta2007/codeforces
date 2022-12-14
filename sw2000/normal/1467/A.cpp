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
void solve()
{
    int n;
    cin>>n;
    cout<<9;
    if(n==1)return;
    cout<<8;
    if(n==2)return;
    for(int i=0;i<n-2;i++)
    {
        cout<<(i+9)%10;
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