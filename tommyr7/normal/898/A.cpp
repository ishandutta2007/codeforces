#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if (n<=5) printf("%d\n",0);
	else if (n%10<=5) printf("%d%d\n",n/10,0);
	else printf("%d%d\n",(n/10)+1,0);
	return 0;
}