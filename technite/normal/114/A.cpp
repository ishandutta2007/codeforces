#include<bits/stdc++.h>
using namespace std;
int main()
{
	double k,n,p;
	scanf("%lf%lf",&k,&n);
	p = k;
	int count = 0;
	while(p != n && p <n)
	{
		p = p * k;
		count++;
	}
	if(count >= 0 && p == n)
	{
		printf("YES\n%d\n",count);
	}
	else
	{
		printf("NO\n");
	}
}