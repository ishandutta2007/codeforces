#include<iostream>
using namespace std;
int main()
{
	long long int n,m;
	cin>>n>>m;
	long long int min,max;
	min=(m-n%m)*(n/m)*((n/m)-1)/2+(n%m)*((n/m)+1)*((n/m))/2;
	max=(n+1-m)*(n-m)/2;
	cout<<min<<" "<<max;

}