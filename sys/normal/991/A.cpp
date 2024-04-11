#include <bits/stdc++.h>
using namespace std;
int ans,a,b,c,n;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&n);
	a-=c;
	b-=c;
	if(a<0||b<0){printf("-1");return 0;}
	ans=a+b+c;
	if(ans+1>n)printf("-1");
	else printf("%d",n-ans);
	return 0;
}