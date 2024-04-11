#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1005
int s[N];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) s[read()]++;
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		ans+=s[i]/2*2;
		s[i]%=2;
	}
//	cout<<ans<<endl;
	int x=ans/2;
	ans+=((n+1)/2-x);
	cout<<ans<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}