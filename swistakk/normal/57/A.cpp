#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, x1, y1, x2, y2;
	cin>>n>>x1>>y1>>x2>>y2;
	if(x1==x2 && x1%n==0)
	{
		cout<<abs(y1-y2)<<endl;
		return 0;
	}
	if(y1==y2 && y1%n==0)
	{
		cout<<abs(x1-x2)<<endl;
		return 0;
	}
	cout<<min(x1+x2, 2*n-x1-x2)+min(y1+y2, 2*n-y1-y2)<<endl;
	return 0;
}