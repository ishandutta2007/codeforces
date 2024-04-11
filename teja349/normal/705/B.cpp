#include<iostream>
using namespace std;
int main(){
	long long int n,t,s=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		s+=t-1;
		if(s%2==1)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
}