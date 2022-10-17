#include<iostream>
using namespace std;
int n,z;
void F(long long x,long long y)
{
	if(y>n)
	{
		if(x<=n)
			z++;
		return;
	}
	F(x,y*10);
	F(x+y,y*10);
}
int main()
{
	cin>>n;
	F(0,1);
	cout<<z-1;
	return 0;
}