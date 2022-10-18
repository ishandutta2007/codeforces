#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 100005
int a[N],b[N];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(b[1]<a[n])
	{
		cout<<"-1\n";
		return 0;
	}
	if(b[1]==a[n])
	{
		int ans=0;
		for(int i=1;i<n;i++) ans+=a[i]*m;
		for(int i=1;i<=m;i++) ans+=b[i];
		cout<<ans<<endl;
		return 0;
	}
	int ans=0;
	for(int i=1;i<n;i++) ans+=a[i]*m;
	for(int i=1;i<m;i++) ans+=b[i];
	ans-=a[n-1];
	ans+=a[n];
	ans+=b[m];
	cout<<ans<<endl;
	return 0;
}