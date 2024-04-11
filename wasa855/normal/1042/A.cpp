#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	int n,m;
	cin>>n>>m;
	int maxn=0;
	int sum=0;;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	sum+=m;
	printf("%d %d\n",max(maxn,(sum/n+(sum%n==0?0:1))),maxn+m);
	return 0;
}
//asoydxitfrcsjyeruyfctr