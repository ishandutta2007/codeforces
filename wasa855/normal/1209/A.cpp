#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 105
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=100;i++)
	{
		bool vis=false;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==i) vis=true;
		}
		if(!vis) continue;
		vis=false;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%i==0) vis=true,a[j]=101;
		}
		if(vis) ans++;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//a