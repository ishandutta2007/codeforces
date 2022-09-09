#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,z,t1,t2,t3;
	scanf("%i %i %i %i %i %i",&x,&y,&z,&t1,&t2,&t3);
	int st=abs(x-y)*t1;
	int ev=(abs(z-x)+abs(x-y))*t2+3*t3;
	if(ev<=st) printf("YES\n");
	else printf("NO\n");
	return 0;
}