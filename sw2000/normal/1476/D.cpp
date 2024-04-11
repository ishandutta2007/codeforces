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

int n,arr[N];
string s;
void solve()
{
    cin>>n>>s;
    arr[0]=2;
    for(int i=1;i<n;i++)
    {
        if(s[i]!=s[i-1])arr[i]=arr[i-1]+1;
        else arr[i]=2;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]!=s[i+1])arr[i]=arr[i+1];
    }

    for(int i=0;i<=n;i++)
    {
        int a=1;
        if(i<n&&s[i]=='R')a=max(a,arr[i]);
        if(i&&s[i-1]=='L')a=max(a,arr[i-1]);
        cout<<a<<' ';
    }
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