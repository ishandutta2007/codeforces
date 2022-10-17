#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",x);
#define print(x) printf("%d ",x);
#define F(i,j,k) f[(i)/2%2][j][k]
const int inf=0x3fffffff;
const double pi=acos(-1.);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<int> vi;
int n;
int a[520][520];
int s[520][520];
int f[2][520][520];
int S(int xa,int ya,int xb,int yb)
{
	return s[xb][yb]-s[xa-1][yb]-s[xb][ya-1]+s[xa-1][ya-1];
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	fo(i,n)
		fo(j,m)
		{
			scanf("%d",&a[i][j]);
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			F(1,i,j)=a[i][j];
		}
	int ans=-inf;
	for(int k=3;k<=n&&k<=m;k+=2)
		for(int i=1;i+k-1<=n;i++)
			for(int j=1;j+k-1<=m;j++)
			{
				F(k,i,j)=S(i,j,i+k-1,j+k-1)-F(k-2,i+1,j+1)-a[i+1][j];
				ans=max(F(k,i,j),ans);
			}
	cout<<ans;
	return 0;
}