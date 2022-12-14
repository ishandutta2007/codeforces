#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
struct tri {ll a, b, c;};
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;
const ll mod = 1e9 + 7;
const double PI = acos(0) * 2;
int lb(int a){return a&(-a);}
vector<tri>ans;
ll x,xx,z,y;

void dfs(ll a,ll b)
{
    if(a==1)return;
    while(a!=b/2)
    {
        ans.push_back({a,a,1});
        a*=2;
        if(a&b)
        {
            ans.push_back({a,b,2});
            a^=b;
        }
    }
    if(a&x)
    {
        ans.push_back({x,a,2});
        x^=a;
    }
    dfs(x,a);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>x;
    if(x&2)
    {
        ans.push_back({x,x,1});
        ans.push_back({x,x*2,1});
        xx=x*3;
    }
    else xx=x;
    z=xx;
    while(lb(z*2)<=xx)
    {
        ans.push_back({z,z,1});
        z*=2;
    }
    ans.push_back({z,xx,1});
    y=z+xx;
    ans.push_back({y,xx,2});
    y^=xx;
    ans.push_back({y,z,2});
    y^=z;

    dfs(x,y);

    cout<<ans.size()<<endl;
    for(auto i:ans)
    {
        cout<<i.a<<" "<<(i.c==1?"+":"^")<<" "<<i.b<<endl;
    }
    return 0;
}