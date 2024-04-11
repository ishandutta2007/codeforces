#include <iostream>
using namespace std;

int main() {
	// your code goes here
	string a;
	cin>>a;
	cout<<a;
	for(int i=a.length()-1;i>=0;i--)
	{
	    cout<<a[i];
	}
	return 0;
}