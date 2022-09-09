#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1050;
int a[N][N],b[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
	{
		scanf("%i",&a[i][j]);
	}
	b[1]=sqrt((ll)a[1][2]*a[1][3]/a[2][3]);
	for(int i=2;i<=n;i++) b[i]=a[1][i]/b[1];
	for(int i=1;i<=n;i++) printf("%i ",b[i]);
	return 0;
}