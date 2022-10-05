#include <bits/stdc++.h>
using namespace std;
int n,m; 
int main()
{
	scanf("%d%d",&n,&m);
	if(!m) printf("1");
	else printf("%d",min(m,n-m));
	return 0;
}