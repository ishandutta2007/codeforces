#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a;
		cin>>a;
		sort(a.begin(),a.end());
//		cout<<a<<endl;
		string x,y;
		int n=a.length();
		x+=a[0];
		for(int i=1;i<n;i++)
		{
			if(abs(a[i]-x[x.length()-1])!=1) x+=a[i];
			else y+=a[i];
		}
		if(!y.length())
		{
			cout<<x<<endl;
			continue;
		}
		if(abs(y[0]-x[x.length()-1])!=1)
		{
			x+=y;
			cout<<x<<endl;
			continue;
		}
		if(abs(x[0]-y[y.length()-1])!=1)
		{
			y+=x;
			cout<<y<<endl;
			continue;
		}
		cout<<"No answer\n";
	}
	return 0;
}