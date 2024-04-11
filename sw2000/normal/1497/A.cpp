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
int n,arr[N];
void solve()
{
    cin>>n;
    set<int>a;
    vi b;
    for(int i=0;i<n;i++)
    {
        int t;cin>>t;
        if(!a.count(t))a.insert(t);
        else b.push_back(t);
    }
    for(auto i:a)cout<<i<<' ';
    for(auto i:b)cout<<i<<' ';
    cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
    {
        solve();
    }
	return 0;
}