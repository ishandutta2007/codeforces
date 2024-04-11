#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        if(n==2)cout<<2<<endl;
        else if(n&1)cout<<1<<endl;
        else cout<<0<<endl;
    }
	return 0;
}