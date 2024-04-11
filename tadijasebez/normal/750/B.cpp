#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x=0,n,i,y;
	scanf("%i",&n);
	char t[20];
	bool ok=1;
	while(n--)
	{
		scanf("%i %s",&y,t);
		if(x==0 && t[0]!='S') ok=0;
		if(x==20000 && t[0]!='N') ok=0;
		if(t[0]=='N') x-=y;
		if(t[0]=='S') x+=y;
		if(x<0 || x>20000) ok=0;
	}
	if(x!=0) ok=0;
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}