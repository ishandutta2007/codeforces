#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define int long long
#define N 300005
int a[N];
int d[N];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<n;i++)
	{
		d[i]=a[i+1]-a[i];
	}
	int ans=a[n]-a[1];
	sort(d+1,d+n,cmp);
	for(int i=1;i<k;i++)
	{
		ans-=d[i];
	}
	cout<<ans<<endl;
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}