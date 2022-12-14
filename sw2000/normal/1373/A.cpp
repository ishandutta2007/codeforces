#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int maxn=1e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

void solve()
{
    ll a,b,c;cin>>a>>b>>c;
    if(a<c)cout<<"1 ";
    else cout<<"-1 ";

    if(a*b>c)cout<<b;
    else cout<<"-1";
    cout<<endl;
}

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
}