#include<iostream>
using namespace std;
int n,i,c[5],x,z;
int main()
{
	cin>>n;
	while(n--)
		cin>>x,c[x]++;
	cout<<c[4]+c[3]+(c[2]+1)/2+max(0,(c[1]-c[3]-c[2]%2*2+3)/4);
	return 0;
}