#include <cstdio>

char love[]="love", hate[]="hate";
int n;

int main()
{
	scanf("%i", &n);
	for(int i=0;i<n-1;i++) printf("I %s that ",i%2==0?hate:love);
	printf("I %s it",n%2==0?love:hate);
}