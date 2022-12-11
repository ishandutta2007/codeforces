#include <bits/stdc++.h>
using namespace std;
int n,t,k,d,ans1,ans2;
int main()
{
	scanf("%d%d%d%d",&n,&t,&k,&d);
	ans1=((n+k-1)/k)*t;
	ans2=d+((n-(d/t)*k)+2*k-1)/(2*k)*t;
	if (ans2<ans1) printf("YES\n"); else printf("NO\n");
	return 0;
}