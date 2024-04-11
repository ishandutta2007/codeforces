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

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	int _;cin>>_;
	while(_--)
    {
        int n,k;
        cin>>n>>k;
        if(k<n)
        {
            if(n%k==0)cout<<1<<endl;
            else cout<<2<<endl;
        }
        else cout<<(k-1)/n+1<<endl;
    }
	return 0;
}