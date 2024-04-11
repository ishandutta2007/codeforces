#include<iostream>
using namespace std;
int main(){
	long long int n;
	cin>>n;
	cout<<2<<endl;
	for (long long int i = 2; i < n+1; ++i)
	{
		cout<<i*(i+1)*(i+1)-(i-1)<<endl;
	}
}