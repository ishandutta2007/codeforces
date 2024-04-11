#include <bits/stdc++.h>
using namespace std;

int main(){

	int a,b,c,n,ans=0,t;
	cin>>a>>b>>c;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		if ((t>b)&&(t<c))
		{
			ans++;
		}
	}
	cout<<ans;



	return 0;

}