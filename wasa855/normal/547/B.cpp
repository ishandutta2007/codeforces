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
#define N 200005
int a[N];
int L[N],R[N];
int ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	stack<int> s;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
		if(s.empty()) L[i]=0;
		else L[i]=s.top();
		s.push(i);
	}
	while(!s.empty()) s.pop();
	for(int i=n;i>=1;i--)
	{
		while(!s.empty()&&a[s.top()]>=a[i]) s.pop();
		if(s.empty()) R[i]=n+1;
		else R[i]=s.top();
		s.push(i);
	}
//	for(int i=1;i<=n;i++) ans[i]=n+1;
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d %d\n",L[i],R[i]);
//	}
	for(int i=1;i<=n;i++)
	{
		if(ans[R[i]-L[i]-1]<a[i]) ans[R[i]-L[i]-1]=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		if(ans[i]>ans[i-1]) ans[i-1]=ans[i];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}