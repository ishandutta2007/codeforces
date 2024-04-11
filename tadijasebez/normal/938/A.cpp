#include <stdio.h>
const int N=150;
char s[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	bool last=0;
	for(i=1;i<=n;i++)
	{
		bool mark=0;
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y') mark=1;
		if(!mark) printf("%c",s[i]),last=0;
		else if(last==0) printf("%c",s[i]),last=1;
	}
	printf("\n");
	return 0;
}