#include<bits/stdc++.h>
using namespace std;
const int N=1505;
int n,a[N],ans,m,p,q;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	 for (int j=i+1;j<=n;j++)
	  if (a[i]>a[j])ans^=1;
	scanf("%d",&m);
	while (m--)
	 {
	 	scanf("%d%d",&p,&q);
	 	if ((q-p+1)*(q-p)/2%2)ans^=1;
	 	if (ans)puts("odd");
	 	else puts("even");
	 }   
}