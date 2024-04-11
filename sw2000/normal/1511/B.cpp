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
const int mod=1e9+7;

int n,arr[N];
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<1;
    for(int i=0;i<a-1;i++)cout<<0;
    cout<<' ';

    for(int i=0;i<b-(c-1);i++)cout<<1;
    for(int i=0;i<c-1;i++)cout<<0;
    cout<<endl;
}
int main()
{
    srand(time(0));
	ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        solve();
    }
	return 0;
}