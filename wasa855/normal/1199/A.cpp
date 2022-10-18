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
#define N 100005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		bool ok=true;
		for(int j=max(i-x,1);j<i;j++)
		{
			if(a[i]>=a[j]) ok=false;
		}
		for(int j=i+1;j<=min(i+y,n);j++)
		{
			if(a[i]>=a[j]) ok=false;
		}
		if(ok)
		{
			cout<<i<<endl;
			return 0;
		}
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}