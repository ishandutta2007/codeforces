#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

int main()
{
	//freopen("in.txt", "r", stdin);
	ll n,cnt,ans=1;
	cin>>n;
	if(n%2)
    {
        cout<<"0";
    }
    else
    {
        cnt=n/2;
        while(cnt--)ans*=2;
        cout<<ans;
    }
	return 0;
}