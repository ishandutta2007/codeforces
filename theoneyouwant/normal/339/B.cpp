#include <iostream>
using namespace std;

int main() {
	int m,n;
	cin>>n>>m;
	int x,l=1;
	long long int t=0;
	for(int i=0;i<m;i++)
	{
	    cin>>x;
	    if(l>x)
	    {
	       t=t+n-(l-x); 
	    }
	    else
	    {
	        t=t+(x-l);
	    }
	    l=x;
	}
	cout<<t;
	return 0;
}