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
int cc[N];
int cp[N];
int h[N];
int f[5005][505];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n*k;i++) cc[read()]++;
	for(int i=1;i<=n;i++) cp[read()]++;
	for(int i=1;i<=k;i++) h[i]=read();
	for(int i=0;i<=n*k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=0;l<=k;l++)
			{
				if(i>=l)
				{
					if(f[i][j]<f[i-l][j-1]+h[l]) f[i][j]=f[i-l][j-1]+h[l];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=100000;i++)
	{
		ans+=f[cc[i]][cp[i]];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}