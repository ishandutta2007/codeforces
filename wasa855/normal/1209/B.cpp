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
int x[N],y[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
//		cout<<x[i]<<endl;
	}
	int maxn=0;
	for(int i=1;i<=10005;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++) if(a[j]==1) cnt++;
		if(cnt>maxn) maxn=cnt;
		for(int j=1;j<=n;j++)
		{
			if(i>=y[j]&&(i-y[j])%x[j]==0) a[j]^=1;
		}
	}
	cout<<maxn<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//s