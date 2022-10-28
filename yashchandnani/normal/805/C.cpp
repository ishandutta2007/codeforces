#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;
	int ans =-1;
	if (n%2)
	{
		ans=0;
	}
	ans+=n/2;
	cout<<ans;


	return 0;
}