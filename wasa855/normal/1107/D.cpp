#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define N 5205
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
char s[N][N/4];
int a[N][N];
int sum[N][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n/4;j++)
		{
			int d;
			if(isdigit(s[i][j])) d=s[i][j]-'0';
			else d=s[i][j]-'A'+10;
//			printf("%d %d %d\n",i,j,d);
			for(int k=1;k<=4;k++)
			{
				if((1<<(4-k))&d) a[i][(j-1)*4+k]=1;
				else a[i][(j-1)*4+k]=0;
			}
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",a[i][j]);
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",a[i]);
//		}
//		cout<<"\n";
//	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i!=0) continue;
		int x=n/i;
		bool ok=1;
		for(int c=1;c<=x;c++)
		{
			for(int d=1;d<=x;d++)
			{
				int res=sum[c*i][d*i]-sum[(c-1)*i][d*i]-sum[c*i][(d-1)*i]+sum[(c-1)*i][(d-1)*i];
				if(res!=0&&res!=i*i) ok=0;
			}
		}
		if(ok) maxn=i;
	}
	cout<<maxn<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}