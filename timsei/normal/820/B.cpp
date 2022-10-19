using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#define eps 0.0000001
double it;
int n;
double a;
int v1,v2,v3;
int ans;
int main()
{
	scanf("%d",&n);
	cin>>a;
	it=360.0/(double) n;
	ans=1;
	for(int i=1;i<=n-2;i++)
	{
		double hh=(it)*i/2.0;
		double hhh=it*(i+1)/2.0;
		if(i==n-2&&hhh<=a-eps)
		{
			cout<<1<<" "<<2<<" "<<3<<endl;return 0;
		}
		if(hh<=a+eps&&hhh>=a-eps)
		{
			if(a-hh<hhh-a){ans=i;break;}
			else{ans=i+1;break;}
		}
	}
	if(ans==n-1){cout<<1<<" "<<2<<" "<<3<<endl;return 0;}
	cout<<1<<" "<<n<<" "<<ans+1<<endl;
}