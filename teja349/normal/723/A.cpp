#include<iostream>
using namespace std;
#include<algorithm>
int main(){
	int a[3];
	for (int i = 0; i < 3; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+3);
	cout<<a[2]-a[0]<<endl;
}