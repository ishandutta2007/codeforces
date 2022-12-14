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

int n,k,h[N];
int solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    if(n==2)
    {
        return abs(h[2]-h[1])<=k-1;
    }
    int l=h[1]-2*(k-1),r=h[1]+(k-1);
    for(int i=2;i<=n;i++)
    {
        if(h[i]<l||h[i]>r)return 0;
        if(i==n-1)
        {
            r=min(r+k-1,h[i]+2*(k-1));
            l=max(l,h[i]-(k-1));
        }
        else
        {
            r=min(r+k-1,h[i]+2*(k-1));
            l=max(l-k+1,h[i]-2*(k-1));
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;cin>>_;
    while(_--)
        cout<<(solve()?"YES":"NO")<<endl;
	return 0;
}