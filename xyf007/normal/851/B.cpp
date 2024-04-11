#include<bits/stdc++.h>
using namespace std;
long long ax,ay,bx,by,cx,cy;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy);
	if((by-ay)*(cx-bx)==(bx-ax)*(cy-by)&&(cy-ay)*(cx-bx)==(cx-ax)*(cy-by))
	  {
	  	printf("No");
	  	return 0;
	  }
	if((by-ay)*(by-ay)+(bx-ax)*(bx-ax)==(cy-by)*(cy-by)+(cx-bx)*(cx-bx))
	  printf("Yes");
	else
	  printf("No");
	return 0;
}