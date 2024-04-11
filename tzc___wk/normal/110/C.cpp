#include <iostream>
using namespace std;
int main()
{
	int n,x,a=0,b=0;
	cin>>n;
	if(n<=0)
	{
		cout<<"-1";
	}
	else
	{
		for(int i=0;i<7;i++)
		{
			x=n-(4*i);
			if(x%7==0)
			{
				a=x/7;
				b=i; 
				break;
			}
			if(x<0)
			{
				cout<<"-1";
				break;
			}
		}
		for(int i=0;i<b;i++)
			cout<<"4";
		for(int i=0;i<a;i++)
			cout<<"7";
	}
	return 0;
}