#include<bits/stdc++.h>
using namespace std;
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 300005
int a[N];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		int x=max(i-1,n-i);
		ans=min(a[i]/x,ans);
	}
	cout<<ans<<endl;
	return 0;
}