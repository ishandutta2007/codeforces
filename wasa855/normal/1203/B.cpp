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
#define N 10005
int cnt[N];
int a[N];
void work()
{
	memset(cnt,0,sizeof(cnt));
	int n=read();
	for(int i=1;i<=4*n;i++) cnt[read()]++;
	int m=0;
	for(int i=1;i<=10000;i++)
	{
		while(cnt[i]>=2) cnt[i]-=2,a[++m]=i;
		if(cnt[i]==1)
		{
			cout<<"NO\n";
			return ;
		}
	}
	int res=a[1]*a[m];
	for(int i=1;i<=n;i++)
	{
		if(a[i]*a[m-i+1]!=res)
		{
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}