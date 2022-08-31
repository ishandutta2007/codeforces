#include<iostream>
using namespace std;
int main(){
	int n,h,t,s=0;
	cin>>n>>h;
	for (int i = 0; i < n; ++i)
	{
		cin>>t;
		if(t>h)
			s+=2;
		else
			s++;
	}
	cout<<s;
}