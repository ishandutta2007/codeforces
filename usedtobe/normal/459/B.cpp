#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int i,j,k,m,ma,mi;
	long long ans,sa,si,n;
	mi=2000000000;
	ma=-1;
	sa=0;
	si=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k>ma)
		{
			ma=k;
			sa=0;
		}
		if(k>=ma)sa++;
		if(k<mi)
		{
			mi=k;
			si=0;
		}
		if(k<=mi)si++;
	}
	if(mi==ma)ans=n*(n-1)/2;else ans=sa*si;
	cout<<ma-mi<<" "<<ans<<endl;
	return 0;
}