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
int l[N],r[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&a[i]);
	}
	l[1]=1,r[n]=n;
	for(int i=1;i<=n;i++)
	{
		if(i!=1) l[i]=(a[i]==a[i-1]?l[i-1]:i);
	}
	for(int i=n-1;i>=1;i--)
	{
		r[i]=(a[i]==a[i+1]?r[i+1]:i);
	}
	int pre0=n,pre1=n,suf0=0,suf1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			pre0=i-1;break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			pre1=i-1;break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==1)
		{
			suf0=i+1;break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==0)
		{
			suf1=i+1;break;
		}
	}
	if(pre0==n||pre1==n)
	{
		cout<<"tokitsukaze\n";return 0;
	}
	if(suf0-pre0-1<=k)
	{
		cout<<"tokitsukaze\n";return 0;
	}
	if(suf1-pre1-1<=k)
	{
		cout<<"tokitsukaze\n";return 0;
	}
	if(2*k<n)
	{
		cout<<"once again\n";return 0;
	}
	for(int i=2;i<=n-k;i++)
	{
		if(l[i-1]!=1||r[i+k]!=n)
		{
			cout<<"once again\n";return 0;
		}
	}
	cout<<"quailty\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}