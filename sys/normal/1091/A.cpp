#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int main()
{
	scanf("%d%d%d",&x,&y,&z);
	printf("%d",3*min(min(x+1,y),z-1));
	return 0;
}