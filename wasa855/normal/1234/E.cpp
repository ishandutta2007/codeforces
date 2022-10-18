#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 200005
int a[N];
int f[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++) a[i]=read();
	for(int i=1;i<=m-1;i++)
	{
		int x=a[i],y=a[i+1];
		if(x==y) continue;
		if(x>y) swap(x,y);
		f[1]+=(y-x),f[x]-=(y-x);
		f[x]+=(y-1),f[x+1]-=(y-1);
		f[x+1]+=(y-x-1),f[y]-=(y-x-1);
		f[y]+=x,f[y+1]-=x;
		f[y+1]+=(y-x),f[n+1]-=(y-x);
	}
	for(int i=1;i<=n;i++)
	{
		f[i]+=f[i-1];
		printf("%I64d ",f[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}