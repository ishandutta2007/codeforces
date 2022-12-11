#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n;
struct Data
{
	int x,id;
}a[maxn];
bool operator < (Data A,Data B){return A.x>B.x;}
int Ans[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+n+1);
	int st=0;
	for(int i=1;i<=n;++i)
	{
		int pos=a[i].id;
		for(int j=0;j<a[i].x;++j)Ans[(st+j)%(n+1)][pos]=1;
		st++;
	}
	printf("%d\n",n+1); 
	for(int i=0;i<=n;++i)
	{
		for(int j=1;j<=n;++j)printf("%d",Ans[i][j]);
		puts("");
	}
}