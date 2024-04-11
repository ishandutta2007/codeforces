#include <cstdio>

int main() {
	int s,v1,v2,t1,t2;
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	v1=t1*2+v1*s;
	v2=t2*2+v2*s;
	if(v1<v2) puts("First");
	else if(v1>v2) puts("Second");
	else puts("Friendship");
	return 0;
}