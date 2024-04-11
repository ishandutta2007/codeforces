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
	int n,k;
	cin>>n>>k;
	int x=(n-k)/2+1;
	for(int i=0;i<n;i++)
	{
		if(i%x==x-1)
		{
			cout<<"0";
		}
		else cout<<"1";
	}
	return 0;
}