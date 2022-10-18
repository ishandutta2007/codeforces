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
int a[N],b[N],c[N];
int c1[N],c2[N],c3[N];
int minn[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	int n=n1+n2+n3;
	for(int i=1;i<=n1;i++) a[i]=read(),c1[a[i]]++;
	for(int i=1;i<=n2;i++) b[i]=read(),c2[b[i]]++;
	for(int i=1;i<=n3;i++) c[i]=read(),c3[c[i]]++;
	for(int i=1;i<=n;i++)
	{
		c1[i]+=c1[i-1];
		c2[i]+=c2[i-1];
		c3[i]+=c3[i-1];
	}
	for(int i=0;i<=n;i++)
	{
		minn[i]=c3[i]-c2[i];
	}
	for(int i=n-1;i>=0;i--)
	{
		if(minn[i+1]<minn[i]) minn[i]=minn[i+1];
	}
	int ans=n;
	for(int i=0;i<=n;i++)
	{
		int res=c2[i]-c1[i]+minn[i]+c1[n]+c2[n];
		if(res<ans) ans=res;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}