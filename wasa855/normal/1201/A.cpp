#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1005
int sum[N][10];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	string x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=0;j<m;j++)
		{
			sum[j+1][x[j]-'A']++;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int maxn=0;
		for(int j=0;j<5;j++)
		{
			if(sum[i][j]>maxn) maxn=sum[i][j]; 
		}
		ans+=maxn*read();
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}