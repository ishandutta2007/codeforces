#include <stdio.h>
#include <cstring>
int a,b,c,n,i;
void Swap(int &a, int &b)
{
	a^=b;
	b^=a;
	a^=b;
}
int main()
{
	scanf("%i",&n);
	a=1,b=2,c=3;
	bool ok=true;
	while(n--)
	{
		scanf("%i",&i);
		if(c==i) ok=0;
		if(a==i) Swap(b,c);
		if(b==i) Swap(a,c);
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}