#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string x,y;
long long N,M;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	if(a<b) return gcd(b,a);
	return gcd(b,a%b);
}

long long tmp1[26],tmp2[26];

int main()
{
	cin>>N>>M;
	cin>>x>>y;
	int a=x.size(),b=y.size();
	int d=gcd(a,b);
	long long ans=0;
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<26;j++)
		{
			tmp1[j]=0,tmp2[j]=0;
		}
		for(int j=i;j<a;j+=d) tmp1[x[j]-'a']++;
		for(int j=i;j<b;j+=d) tmp2[y[j]-'a']++;
		long long all=(a/d);
		all*=(b/d);
		long long same=0;
		for(int j=0;j<26;j++) same+=tmp1[j]*tmp2[j];
		ans+=(all-same);
	}
	long long x1=b/d;
	long long t=N/x1;
	ans*=t;
	cout<<ans<<"\n";
	return 0;
}