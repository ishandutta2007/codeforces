#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n==1)
	{
		cin>>n;
		if(n==0)
			cout<<"UP";
		else if(n==15)
			cout<<"DOWN";
		else 
			cout<<-1;
	}
	else {
		int a[100];
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		if(a[n-1]==0)
			cout<<"UP";
		else if(a[n-1]==15)
			cout<<"DOWN";
		else if(a[n-2]>a[n-1])
			cout<<"DOWN";
		else
			cout<<"UP"; 
			
	}
}