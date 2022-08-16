#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	cout<<"I hate ";
	for (int i = 0; i < n-1; ++i)
	{
		if(i%2==0)
			cout<<"that I love ";
		else
			cout<<"that I hate ";
	}
	cout<<"it";
}