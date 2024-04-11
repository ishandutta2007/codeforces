#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N];
long long v[N];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1); 
	for(int i=2;i<=n;i++)
	{
		if(s[i]=='v'&&s[i-1]=='v')
			v[i]++;
		v[i]+=v[i-1];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='o')
		{
			long long s1=v[i-1],s2=v[n]-v[i];
			ans+=s1*s2;
		}
	}
	cout<<ans<<endl;
	return 0;
}