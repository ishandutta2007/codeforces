#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
signed main()
{
	int n;
	cin>>n;
	char x;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x=='-')
		{
			ans=max(ans-1,0);
		}
		else ans++;
	}
	cout<<ans<<endl;
	return 0;
}