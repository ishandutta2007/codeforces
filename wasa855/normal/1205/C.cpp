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
int query(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	return read()^1;
}
#define N 105
int a[N][N];
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int n=read();
	a[1][1]=1,a[n][n]=0;
	for(int i=4;i<n*2;i+=2)
	{
		if(i<=n+1) a[1][i-1]=query(1,i-3,1,i-1)^a[1][i-3],a[i-1][1]=query(i-3,1,i-1,1)^a[i-3][1];
		for(int j=2;j<=n&&j<i-1;j++)
		{
			if(i-j<=n) a[i-j][j]=query(i-j-1,j-1,i-j,j)^a[i-j-1][j-1];
		}
	}
	a[1][2]=1;
	a[2][3]=query(1,2,2,3)^1;
	a[2][1]=query(2,1,2,3)^a[2][3];
	a[3][2]=query(2,1,3,2)^a[2][1];
	if(n>=5) a[4][1]=query(2,1,4,1)^a[2][1],a[1][4]=query(1,2,1,4)^a[1][2];
	for(int i=7;i<n*2;i+=2)
	{
		if(i<=n+1) a[1][i-1]=query(1,i-3,1,i-1)^a[1][i-3],a[i-1][1]=query(i-3,1,i-1,1)^a[i-3][1];
		for(int j=2;j<=n&&j<i-1;j++)
		{
			if(i-j<=n) a[i-j][j]=query(i-j-1,j-1,i-j,j)^a[i-j-1][j-1];
		}
	}
	int xx=0;
	for(int i=1;i<=n-2;i++)
	{
		if((a[i][i]^a[i+1][i]^a[i+1][i+1]^a[i+2][i+1])==0)
		{
			if(query(i,i,i+2,i+1)^a[i][i]^a[i+2][i+1]) xx=1;
			break;
		}
		if((a[i+1][i]^a[i+1][i+1]^a[i+2][i+1]^a[i+2][i+2])==0)
		{
			if(query(i+1,i,i+2,i+2)^a[i+1][i]^a[i+2][i+2]) xx=1;
			break;
		}
	}
	cout<<"!\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2==1) cout<<(a[i][j]^xx);
			else cout<<a[i][j];
		}
		cout<<"\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}