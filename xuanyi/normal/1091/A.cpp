#include <cstdio>
#include <algorithm>

int y,b,r;

int main(){
	scanf("%d%d%d",&y,&b,&r);
	int x=std::min(y,std::min(b-1,r-2));
	printf("%d\n",x*3+3);
	return 0;
}