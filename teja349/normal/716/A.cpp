#include<iostream>
using namespace std;
int main(){
	int n,c;
	cin>>n>>c;
	int a[123456];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int p=1;
	for (int i = n-1; i >=1; --i)
	{
		if(a[i]-a[i-1]>c)
			break;
		else
			p++;
	}
	cout<<p;
}