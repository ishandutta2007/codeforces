#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string s;
long long a[100001];
const int mod=1e9+7;
int main()
{
	cin>>s;
	s+='b';
	long long ans=1,temp=1,sum=0;
	for(int i=0,sz=s.size();i<sz;i++)
	{
		
		if(s[i]=='a')
		{
			sum++;
		}
		else
		{
			if(s[i]=='b')
			{
				a[temp++]=sum;
				sum=0;
			}
		}
	}
	for(int i=1;i<temp;i++)
	{
		ans=ans*(a[i]+1)%mod;
	}
	printf("%lld",(ans-1+mod)%mod);
	return 0;
}
//vr