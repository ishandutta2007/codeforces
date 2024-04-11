#include <bits/stdc++.h>
using namespace std;
int n,ans1,ans2;
int main()
{
	scanf("%d",&n);
	ans2=(n)/7*2+min(2,n%7);
	ans1=(n/7)*2+(n%7==6);
	printf("%d %d\n",ans1,ans2);
	return 0;
}