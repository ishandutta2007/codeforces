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
int n;
string l,r;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
	cin>>n>>l>>r;
    unsigned long long a=0,b=0;
    for(int i=0;i<n;i++)
    {
        a=(a*2+(l[i]=='1'))%mod;
        b=(b*2+(r[i]=='1'))%mod;
    }
    b=(b-a+mod+1)%mod;
    if(l[0]==r[0])
    {
        if(b>=3)r[n-1]='1';
        cout<<r;
        return 0;
    }
    for(int i=0;i<n;i++)cout<<1;
	return 0;
}