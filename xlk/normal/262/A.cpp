#include<iostream>
using namespace std;
int C(int x)
{
	if(x==0)
		return 0;
	return C(x/10)+(x%10==4||x%10==7);
}
int n,k,x,z;
int main()
{
	for(cin>>n>>k;n--;)
		cin>>x,z+=C(x)<=k;
	cout<<z;
	return 0;
}