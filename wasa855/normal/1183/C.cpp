#include<bits/stdc++.h>
using namespace std;
#define int long long
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
void work()
{
	int k,n,a,b;
	cin>>k>>n>>a>>b;
	if(b*n>=k)
	{
		cout<<"-1\n";
		return ;
	}
	k-=b*n;
	cout<<min(n,(k-1)/(a-b))<<endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--)
	{
		work();
	}
	return 0;
}