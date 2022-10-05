#include<iostream>
using namespace std;
int a[1000];
int main()
{
	std::ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		long long h;
		cin>>n>>h;
		for(int j=1;j<=n;j++) cin>>a[j];
		long long x=0,y=h;
		if(h>2000000000)
		{
			cout<<h-a[n]+a[1];
			if(i<t) cout<<endl;
			continue;
		}
		for(;x<y;)
		{
			int z=(x+y)/2;
			bool r=false;
			long long h1=h;
			for(int j=1;j<=n;j++)
			{
				if((j+1<=n)&(a[j+1]<=a[j]+z-1))
				h1-=a[j+1]-a[j];
				else
				h1-=z;
				if(h1<=0)
				{
					r=true;
					break;
				}
			}
			if(r) y=z;
			else x=z+1;
		}
		cout<<x;
		if(i<t) cout<<endl;
	}
	return 0; 
}