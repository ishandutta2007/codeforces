#include<iostream>
using namespace std;
long long n,_=1LL<<60;
void F(long long x,int y,int z)
{
	if(x>=n)
		if(y==z)
			_=min(_,x);
	if(x>n*100)
		return;
	F(x*10+4,y+1,z);
	F(x*10+7,y,z+1);
}
int main()
{
	cin>>n;
	F(0,0,0);
	cout<<_;
	return 0;
}