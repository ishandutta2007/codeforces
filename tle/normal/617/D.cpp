#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
int main()
{
	int x[4],y[4];
	while(cin>>x[1]>>y[1]>>x[2]>>y[2]>>x[3]>>y[3])
	{
		if(x[1]==x[2]&&x[2]==x[3]) {printf("1\n"); continue;}
		if(y[1]==y[2]&&y[2]==y[3]) {printf("1\n"); continue;}
		bool ok2=0;
		int p[4]={1,2,3,0};
		do
		{
			if(x[p[1]]==x[p[2]]&&y[p[2]]==y[p[0]]) ok2=1;
			if(y[p[1]]==y[p[2]]&&x[p[2]]==x[p[0]]) ok2=1;
			int x1=min(x[p[0]],x[p[1]]),x2=max(x[p[0]],x[p[1]]);
			int y1=min(y[p[0]],y[p[1]]),y2=max(y[p[0]],y[p[1]]);
			if((y[p[2]]==y1||y[p[2]]==y2)&&(x[p[2]]>=x1&&x[p[2]]<=x2)) ok2=1;
			if((x[p[2]]==x1||x[p[2]]==x2)&&(y[p[2]]>=y1&&y[p[2]]<=y2)) ok2=1;
		}while(next_permutation(p,p+3));
		if(ok2) printf("2\n"); else printf("3\n");
	}
}