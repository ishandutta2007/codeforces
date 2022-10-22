#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long
 
#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
 
#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5
 
#define _ 0
using namespace std;
 
int a[102][102];
int n;
char f;
 
void pp(int x1,int y1,int x2,int y2)
{
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	cin>> f; f-='0';
	if (f==1)
		a[x2][y2]=a[x1][y1];
	else
		a[x2][y2]=a[x1][y1]^1;
}
 
void prt()
{
	cout<<'!'<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<a[i][j];
		cout<<endl;
	}
}
int main()
{
	cin>>n;
	//RPT(i,1,n+1)
	//	RPT(j,1,n+1)
	//		a[i][j]=2;
	a[1][1]=1;
	a[n][n]=0;
	for (int i=3;i<=n;i+=2)
		pp(1,i-2,1,i);
	for (int i=2;i<=n;i+=2)
		pp(1,i-1,2,i);
	for (int i=1;i<=n;i++)
	{
		if (i&1)
		{
			for (int j=3;j<=n;j+=2)
			{
				if (i==n && j==n)
					continue;
				pp(j-2,i,j,i);
			}
		}
		else
		{
			for (int j=4;j<=n;j+=2)
				pp(j-2,i,j,i);
		}
	}
	a[1][2]=1;
	pp(1,2,2,3);
	pp(1,2,3,2);
	
	
	printf("? %d %d %d %d\n",2,1,3,2);
	fflush(stdout);
	cin>> f; f-='0';
	if (f)
		a[2][1]=a[3][2];
	else
		a[2][1]=a[3][2]^1;
		
	for (int i=4;i<=n;i+=2)
		pp(1,i-2,1,i);
	for (int i=5;i<=n;i+=2)
		pp(2,i-2,2,i);
	for (int i=1;i<=n;i++)
	{
		if (i&1)
		{
			for (int j=4;j<=n;j+=2)
			{
				pp(j-2,i,j,i);
			}
		}
		else
		{
			for (int j=3;j<=n;j+=2)
			{
				if (i==2 && j==3)
				{
					continue;
				}
				pp(j-2,i,j,i);
			}
		}
	}
	bool diff;
	for (int i=1;i<=n-2;i++)
		if (a[i][i]!=a[i+2][i+2])
		{
			if (a[i][i]^a[i+1][i]^a[i+1][i+1]^a[i+2][i+1]==0)
			{
				printf("? %d %d %d %d\n",i,i,i+2,i+1);
				fflush(stdout);
				cin>> f; f-='0';
				//WRT((int)f);
				diff=!((a[i+1][i]==a[i+1][i+1])==f); 
			}
			else 
			{
				printf("? %d %d %d %d\n",i+1,i,i+2,i+2);
				fflush(stdout);
				cin>> f; f-='0';
				//WRT((int)f);
				diff=!((a[i+1][i+1]==a[i+2][i+1])==f); 
			}
			break;
		}
	//WRT(diff);
	//prt();
	cout<<'!'<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			if (diff && (i+j)&1) 
				cout<<(a[i][j]^1);
			else
				cout<<a[i][j];
		cout<<endl;
	}
	return ~~(0^_^0);
}