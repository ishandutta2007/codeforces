#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	long long t,a,b,k,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>a>>b>>k;
		cout<<(a-b)*(k/2)+a*(k%2)<<endl;
	}
	return 0;
}