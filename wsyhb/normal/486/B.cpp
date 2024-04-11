#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int A[max_n][max_n],B[max_n][max_n],C[max_n][max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&B[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			A[i][j]=1;
			for(int k=1;k<=m;++k)
				A[i][j]&=B[i][k];
			for(int k=1;k<=n;++k)
				A[i][j]&=B[k][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			C[i][j]=0;
			for(int k=1;k<=m;++k)
				C[i][j]|=A[i][k];
			for(int k=1;k<=n;++k)
				C[i][j]|=A[k][j];
			if(C[i][j]!=B[i][j])
			{
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			printf("%d%c",A[i][j],j<m?' ':'\n');
	return 0;
}