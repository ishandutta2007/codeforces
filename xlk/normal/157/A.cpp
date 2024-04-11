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

const int inf=0x3fffffff;
using namespace std;
int n;
int a[40][40];
int check(int x,int y)
{
	int re=0;
	fr(i,n)
		re+=a[x][i];
	fr(i,n)
		re-=a[i][y];
	return re<0;
		
}
int ans;
int main()
{
	scan(n)
	fr(i,n)
		fr(j,n)
			scan(a[i][j])
	fr(i,n)
		fr(j,n)
			if(check(i,j))
				ans++;
	print(ans);
	return 0;
}