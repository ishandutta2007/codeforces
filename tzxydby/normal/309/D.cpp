#include<bits/stdc++.h>
using namespace std;
const int N=32005;
int n,m,i,j,f;
int a[N];
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=m+1;i<=(n+1)/2;i++)
	{
		for(j=m+1;j<2*i;j++)
		{
			f=(i*(2*i-j)+(n+1)*(2*j-i))/(i+j);
   			f=max(f,m);
			if(f>n-m)
				continue;
			a[i]+=n-m-f;
		}
	}
	for(i=m+1;i<=(n+1)/2;i++)
		ans+=2*a[i];
	if(n%2)
		ans-=a[i-1];
	printf("%I64d\n",3*ans);
	return 0;
}