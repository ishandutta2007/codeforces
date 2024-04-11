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
int n,k;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	if(n==1)
	{
		if(k==0) cout<<a[1]<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(a[1]!=1&&k) k--,a[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=0&&k) k--,a[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d",a[i]);
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}