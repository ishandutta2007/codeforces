#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,k;
	cin>>n>>m>>k;
	if(k<n)
	{
		cout<<k+1<<' '<<1<<endl;
		return 0;
	}
	k-=n;
	m--;
	cout<<n-k/m<<' '<<(k/m%2?m-1-k%m:k%m)+2<<endl;
	return 0;
}