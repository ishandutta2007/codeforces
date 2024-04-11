#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char s[N],t[N];
int main()
{
	scanf("%s%s",s+1,t+1);
	int sum=0,p=0,ans=0,n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<m;i++)
		if(t[i]!=t[i+1])
			p^=1;
	for(int i=1;i<=m;i++)
		if(s[i]!=t[i])
			sum^=1;
	for(int i=1;i<=n-m+1;i++)
	{
		ans+=(sum==0);
		if(p)
			sum^=1;
		if(t[1]!=s[i])
			sum^=1;
		if(t[m]!=s[i+m])
			sum^=1;
	}
	cout<<ans<<endl;
	return 0;
}