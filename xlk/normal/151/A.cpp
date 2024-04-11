#include<iostream>
using namespace std;
int n,k,l,c,d,p,nl,np;
int main()
{
	cin>>n>>k>>l>>c>>d>>p>>nl>>np;
	cout<<min(min(k*l/nl,p/np),c*d)/n;
	return 0;
}