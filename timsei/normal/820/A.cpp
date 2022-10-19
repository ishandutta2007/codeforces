using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
int c,v0,v1,a,l;
int main()
{
	cin>>c>>v0>>v1>>a>>l;
	int ans=0;
	int now=0;
	while(1)
	{
		ans++;
		now-=l;if(now<0)now=0;
		now+=v0;if(now>=c)break;
		v0+=a;if(v0>v1)v0=v1;
	}
	cout<<ans<<endl;
}