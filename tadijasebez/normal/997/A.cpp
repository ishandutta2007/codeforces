#include <stdio.h>
#define ll long long
const int N=300050;
char s[N];
int main()
{
	int cnt=0,n,i,x,y;
	scanf("%i %i %i",&n,&x,&y);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i-1]!='0' && s[i]=='0') cnt++;
	}
	if(!cnt) printf("0\n");
	else if(x<y) printf("%lld\n",(ll)x*(cnt-1)+y);
	else printf("%lld\n",(ll)cnt*y);
	return 0;
}