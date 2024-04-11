#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y; scanf("%d%d",&x,&y);
	while((x>=2&&y>=2)||(x>=1&&y>=12)||(y>=22)){
		if((x>=2&&y>=2)) x-=2, y-=2;
		else if((x>=1&&y>=12)) x-=1, y-=12;
		else y-=22;
		if(!((x>=2&&y>=2)||(x>=1&&y>=12)||(y>=22))){
			printf("Ciel\n");
			return 0;
		}
		if(y>=22) y-=22;
		else if(y>=12&&x>=1) y-=12, x-=1;
		else x-=2, y-=2;
	}
	printf("Hanako\n");
	return 0;
}