#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int Ask(int x1, int y1, int x2, int y2)
{
	printf("? %i %i %i %i\n",x1,y1,x2,y2);
	fflush(stdout);
	int b;scanf("%i",&b);
	return b;
}
const int N=55;
int a[N][N],b[N][N],c[N][N];
void GetA(int x1, int y1, int x2, int y2)
{
	int b=Ask(x1,y1,x2,y2);
	if(b) a[x2][y2]=a[x1][y1];
	else a[x2][y2]=a[x1][y1]^1;
}
void GetB(int x1, int y1, int x2, int y2)
{
	int t=Ask(x1,y1,x2,y2);
	if(t) b[x2][y2]=b[x1][y1];
	else b[x2][y2]=b[x1][y1]^1;
}
int n;
void Case1(int x, int y)
{
	int x1,y1,x2,y2;
	if(x>1)
	{
		x1=x-1;y1=y-1;
		x2=x+1;y2=y;
	}
	else
	{
		x1=x;y1=y-1;
		x2=x+2;y2=y;
	}
	int t=Ask(x1,y1,x2,y2);
	if((c[x1][y1]==c[x2][y2])!=t)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if((i+j)%2==1) b[i][j]^=1;
	}
	printf("!\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%i",a[i][j]^b[i][j]);
		printf("\n");
	}
	fflush(stdout);
}
void Change()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if((i+j)%2==1) b[i][j]^=1;
}
void Output()
{
	printf("!\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%i",a[i][j]^b[i][j]);
		printf("\n");
	}
	fflush(stdout);
}
void Case2()
{
	vector<int> A,B;
	vector<pair<int,int>> PA,PB;
	for(int i=1;i<=n;i+=2) A.pb(a[1][i]),PA.pb({1,i});
	for(int i=3;i<=n;i+=2) A.pb(a[i][n]),PA.pb({i,n});
	for(int i=2;i<=n;i+=2) B.pb(b[1][i]),PB.pb({1,i});
	for(int i=2;i<=n;i+=2) B.pb(b[i][n]),PB.pb({i,n});
	for(int i=0;i+1<B.size();i++)
	{
		if((A[i]==A[i+1])==(B[i]==B[i+1]))
		{
			int t=Ask(PA[i].first,PA[i].second,PB[i+1].first,PB[i+1].second);
			if(t==1)
			{
				if(A[i]!=B[i+1]) Change();
			}
			else if(A[i]==B[i+1]) Change();
			Output();
			return;
		}
		if((A[i+1]==A[i+2])==(B[i]==B[i+1]))
		{
			int t=Ask(PB[i].first,PB[i].second,PA[i+2].first,PA[i+2].second);
			if(t==1)
			{
				if(B[i]!=A[i+2]) Change();
			}
			else if(B[i]==A[i+2]) Change();
			Output();
			return;
		}
	}
}
int main()
{
	scanf("%i",&n);
	a[1][1]=1;
	for(int i=3;i<=n;i+=2) GetA(i-2,1,i,1);
	GetA(1,1,2,2);
	for(int i=4;i<=n;i+=2) GetA(i-2,2,i,2);
	for(int i=1;i<=n;i+=2) for(int j=3;j<=n;j+=2) if(i!=n || j!=n) GetA(i,j-2,i,j);
	for(int i=2;i<=n;i+=2) for(int j=4;j<=n;j+=2) GetA(i,j-2,i,j);
	GetB(1,2,2,3);
	int t=Ask(2,1,2,3);
	if(t) b[2][1]=b[2][3];
	else b[2][1]=b[2][3]^1;
    for(int i=4;i<=n;i+=2) GetB(i-2,1,i,1);
    for(int i=3;i<=n;i+=2) GetB(i-2,2,i,2);
    for(int i=1;i<=n;i+=2) for(int j=4;j<=n;j+=2) GetB(i,j-2,i,j);
    for(int i=2;i<=n;i+=2) for(int j=3;j<=n;j+=2) if(i!=2 || j!=3) GetB(i,j-2,i,j);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=a[i][j]^b[i][j];
    for(int i=1;i<n;i++) for(int j=2;j<=n;j++)
	{
		if(c[i][j]!=c[i+1][j-1])
		{
			Case1(i,j);
			return 0;
		}
	}
	Case2();
	return 0;
}