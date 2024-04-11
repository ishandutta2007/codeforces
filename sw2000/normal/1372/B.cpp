#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e3+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

void solve()
{
    int n;cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<n/i<<' '<<n-n/i<<endl;
            return;
        }
    }
    cout<<1<<' '<<n-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
//    freopen("in.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}