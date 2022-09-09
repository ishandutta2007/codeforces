#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=2050;
int n,sz,sol[3*N];
char s[N],t[N];
void Move(int x)
{
	sol[++sz]=x;
	rotate(s,s+n-x,s+n);
	reverse(s,s+x);
}
int main()
{
	scanf("%i",&n);
	int i,j;
	scanf("%s",s);
	scanf("%s",t);
	for(i=0;i<n;i++)
	{
		int x=-1;
		for(j=i;j<n;j++) if(t[i]==s[j]) x=j;
		if(!(~x)) return printf("-1\n"),0;
		Move(n);
		Move(x);
		Move(1);
	}
	Move(n);
	printf("%i\n",sz);
	for(i=1;i<=sz;i++) printf("%i ",sol[i]);
	return 0;
}