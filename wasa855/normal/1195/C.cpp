#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int a[N][3];
int f[N][4];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i][1]=read();
	}
	for(int i=1;i<=n;i++)
	{
		a[i][2]=read();
	}
	for(int i=1;i<=n;i++)
	{
		f[i][1]=max(f[i-1][3],f[i-1][2])+a[i][1];
		f[i][2]=max(f[i-1][3],f[i-1][1])+a[i][2];
		f[i][3]=max(max(f[i-1][1],f[i-1][2]),f[i-1][3]);
	}
	cout<<max(max(f[n][1],f[n][2]),f[n][3])<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}