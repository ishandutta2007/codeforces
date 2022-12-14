#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10;
const int mod=1e9+7;

string s;
ll n,p,k,arr[N],x,y;
ll solve()
{
    cin>>n>>p>>k>>s;
    cin>>x>>y;
    s="3"+s;
    ll ret=linf;

    for(int i=n;i>=p;i--)
    {
        if(i+k<=n)arr[i]=arr[i+k];
        else arr[i]=0;
        if(s[i]=='0')arr[i]+=x;
        ret=min(ret,arr[i]+(i-p)*y);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    int _;
    cin>>_;
    while(_--)
        cout<<solve()<<endl;
    return 0;
}