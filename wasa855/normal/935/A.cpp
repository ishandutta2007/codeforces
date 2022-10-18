#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(n%i==0) ans++;
	}
	cout<<ans<<endl;
	return 0;
}