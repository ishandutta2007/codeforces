#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long d,m,ans=1;
		cin>>d>>m;
		long long j=d,coun=0;
		while(j>0)
		{
			j/=2;
			coun++;
		}
		for(long long i=0;i<coun;i++)
		{
			ans=(ans*(min((long long)pow(2,i+1)-1,d) - pow(2,i) +2));
			ans%=m;
		
		}
		ans--;
		cout<<(ans+m)%m<<endl;
	}
}