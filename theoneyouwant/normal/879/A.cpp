#include <iostream>
using namespace std;

int main() {
	int n;
	long long int counter=0,k=0;
	cin>>n;
	int s[n];
	int d[n];
	for(int i=0;i<n;i++)
	{
	    cin>>s[i]>>d[i];
	}
	int j=0;
	for(int i=0;i<n;i++)
	{
	    k=s[i];
	    while(k<=counter)
	    {
	        k+=d[i];
	    }
	    counter=k;
	}
	cout<<counter;
	return 0;
}