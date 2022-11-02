#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include <stack>
#include <set>
#include <map>

int res,n,a,b,c,m;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	scanf("%d%d%d%d",&n,&a,&b,&c);
	res=0;
	for (int x=0;x<=a;x+=2)
		for (int y=0;y<=b;y++){
			m=n-x/2-y;
			if (m<0) continue;
			if (m&1)continue;
			if (m/2>c)continue;
			res++;
		}
	printf("%d\n",res);
}