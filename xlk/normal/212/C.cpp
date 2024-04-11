#include<iostream>
#include<string.h>
using namespace std;
long long f[120],g[120];
char s[120];
int n;
long long F(int x)
{
	f[0]=x,g[0]=1-x;
	for(int i=0;i<n;i++)
		if(s[i]=='A')
		{
			f[i+1]=f[i]+g[i];
			if(s[i+1]=='A')
				g[i+1]=0;
			else
				g[i+1]=g[i];
		}
		else
		{
			if(s[i+1]=='A')
				f[i+1]=g[i],g[i+1]=f[i];
			else
				f[i+1]=g[i],g[i+1]=g[i];
		}
	return x?f[n]:g[n];
}
int main()
{
	cin>>s;
	n=strlen(s),s[n]=s[0];
	cout<<F(0)+F(1);
}