#include <bits/stdc++.h>
using namespace std;
int num,ans;
int main()
{
	scanf("%d",&num);
	ans+=num/100;
	num%=100;
	ans+=num/20;
	num%=20;
	ans+=num/10;
	num%=10;
	ans+=num/5;
	num%=5;
	ans+=num/1;
	num%=1;
	printf("%d",ans);
	return 0;
}