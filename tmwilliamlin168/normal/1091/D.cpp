#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
long long n;
long long last=1,lastkey=1;

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++){
		lastkey=(lastkey+last-1)*(i%mod)%mod;
		last*=i;
		last%=mod;
	}
	cout<<lastkey;
	return 0;
}