#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,k;
	int t;
	cin>>t;
	while(t--)
	{	
		cin>>a>>b>>c>>d>>k;
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y<=k)
			cout<<x<<' '<<y<<endl;
		else
			cout<<-1<<endl;
	} 
	return 0;
}