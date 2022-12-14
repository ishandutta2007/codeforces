#include<bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
#define endl '\n'
#define double long double
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
typedef vector<int>vi;
struct tri {int a, b, c;};
const int N = 4e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
string s, t;
int cnt[200],pos[N],c[N],n;
int lb(int a){return a&-a;}
void add(int p,int v)
{
    for(;p<=n;p+=lb(p))
        c[p]+=v;
}
int query(int p)
{
    int ret=0;
    for(;p;p-=lb(p))
        ret+=c[p];
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
//    freopen("in.txt", "r", stdin);
    cin>>n>>s;
    vi v[50];
    for(int i=0;i<n;i++)
    {
        v[s[i]-'a'].push_back(n-1-i);
    }
    ll ans=0;
    int cnt[50];
    for(int i=0;i<26;i++)cnt[i]=v[i].size();
    for(int i=0;i<n;i++)pos[v[s[i]-'a'][--cnt[s[i]-'a']]]=i+1;
//    for(int i=0;i<n;i++)cout<<pos[i]<<' ';cout<<endl;
//    for(int i=0;i<n;i++)ans+=abs(i-pos[i]);
    for(int i=1;i<=n;i++)
        add(i,1);
    for(int i=0;i<n;i++)
    {
        ans+=query(pos[i]-1);
        add(pos[i],-1);
    }
    cout<<ans;
    return 0;
}