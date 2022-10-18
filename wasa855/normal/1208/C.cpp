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
int x[4][4]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
#define N 2005
int a[N][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	int m=n/4;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<4;k++)
			{
				for(int l=0;l<4;l++)
				{
					a[i*4+k+1][j*4+l+1]=x[k][l]+16*(i*m+j);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		cout<<"\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//